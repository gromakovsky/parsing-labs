#include "grammar.h"

#include "errors.h"

#include <iostream>
#include <iterator>
#include <algorithm>

#include <boost/range/adaptors.hpp>
#include <boost/variant/get.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/throw_exception.hpp>

namespace
{
   bool unite_sets(terminal_set & a, const terminal_set & b) // a = union(a, b)
   {
      bool result = false;

      for (token_id_t token : b)
      {
         result |= a.insert(token).second;
      }

      return result;
   }

   void check_rule(const rule_t & rule)
   {
      if (rule.right.empty())
      {
         BOOST_THROW_EXCEPTION(invalid_grammar()
                               << errinfo_message("Right part of the rule can't be empty. Use %empty"));
      }
      if (rule.right.size() == 1)
      {
         return;
      }
      for (const item_t & token : rule.right)
      {
         if (token.which() == 3)
         {
            BOOST_THROW_EXCEPTION(invalid_grammar()
                                  << errinfo_message("Right part with %empty can't contain anything else"));
         }
      }
   }

}

token_id_t grammar_t::token_id(const std::string & token) const
{
   if (token_bimap.left.count(token))
   {
      return token_bimap.left.at(token);
   }
   else
   {
      BOOST_THROW_EXCEPTION(unknown_terminal() << errinfo_terminal_name(token));
   }
}

std::string grammar_t::token_repr(token_id_t id) const
{
   return id == empty_token_id ? "%empty" : token_bimap.right.at(id);
}

std::string grammar_t::item_to_string(const item_t & item) const
{
   switch (item.which())
   {
      case 0: // nonterm_t
      {
         return boost::get<nonterm_t>(item);
      }
      case 1: // token_id_t
      {
         token_id_t token_id = boost::get<token_id_t>(item);
         return token_repr(token_id);
      }
      case 2: // translating_symbol_t
      {
         const translating_symbol_t & translating_symbol = boost::get<translating_symbol_t>(item);
         return "{" + translating_symbol.code + "}";
      }
      case 3: // empty_token_t
      {
         return "ε";
      }
      default:
      {
         BOOST_THROW_EXCEPTION(std::logic_error("Unreachable place"));
      }
   }
}

std::string grammar_t::range_to_string(const items_range_t & alpha) const
{
   std::string result;
   for (const item_t & item : alpha)
   {
      result += item_to_string(item);
      result += " ";
   }
   boost::algorithm::trim_right(result);

   return result;
}

terminal_set grammar_t::FIRST(const items_range_t & alpha) const
{
   if (alpha.empty() || alpha.front().which() == 3) // empty_token_t
   {
      return {empty_token_id};
   }

   const item_t & first_item = alpha.front();

   switch (first_item.which())
   {
      case 0: // nonterm_t
      {
         const nonterm_t & nonterm = boost::get<nonterm_t>(first_item);
         terminal_set result = FIRST_.at(nonterm);
         if (result.count(empty_token_id))
         {
            result.erase(empty_token_id);
            unite_sets(result, FIRST(boost::make_iterator_range(std::next(alpha.begin()), alpha.end())));
         }
         return result;
      }
      case 1: // token_id_t
      {
         return {boost::get<token_id_t>(first_item)};
      }
      case 2: // translating_symbol_t
      {
         return FIRST(boost::make_iterator_range(std::next(alpha.begin()), alpha.end()));
      }
      default:
         BOOST_THROW_EXCEPTION(std::logic_error("Unreachable place"));
   }
}

terminal_set grammar_t::FOLLOW(const nonterm_t & non_terminal) const
{
   return FOLLOW_.at(non_terminal);
}

void grammar_t::set_internal_fields(bool verbose)
{
   if (verbose)
   {
      std::cerr << "Rules:" << std::endl;
      for (const rule_t & rule : rules | boost::adaptors::map_values)
      {
         std::cerr << rule.left << " → " << range_to_string(rule.right) << std::endl;
      }
      std::cerr << "------------" << std::endl << std::endl;
   }

   build_FIRST();
   build_FOLLOW();

   if (verbose)
   {
      std::cerr << "FIRST:" << std::endl;
      print_FIRST();
      std::cerr << "------------" << std::endl << std::endl;
      std::cerr << "FOLLOW:" << std::endl;
      print_FOLLOW();
      std::cerr << "------------" << std::endl << std::endl;
   }
}

void grammar_t::build_FIRST()
{
   for (const nonterm_t & non_terminal : non_terminals)
   {
      FIRST_[non_terminal];
   }

   bool changed;
   do
   {
      changed = false;
      for (const rule_t & rule : rules | boost::adaptors::map_values)
      {
         changed |= unite_sets(FIRST_[rule.left], FIRST(rule.right));
      }
   } while (changed);
}

void grammar_t::build_FOLLOW()
{
   for (const nonterm_t & non_terminal : non_terminals)
   {
      if (non_terminal == start_non_terminal)
      {
         FOLLOW_[non_terminal] = {0};
      } else {
         FOLLOW_[non_terminal];
      }
   }

   bool changed;
   do
   {
      changed = false;
      for (const rule_t & rule : rules | boost::adaptors::map_values)
      {
         for (size_t i = 0; i != rule.right.size(); ++i)
         {
            if (rule.right[i].which() != 0) // nonterm_t
            {
               continue;
            }
            const nonterm_t & non_terminal = boost::get<nonterm_t>(rule.right[i]);
            auto first = FIRST(boost::make_iterator_range(std::next(rule.right.begin(), i + 1), rule.right.end()));
            if (first.count(empty_token_id))
            {
               changed |= unite_sets(FOLLOW_[non_terminal], FOLLOW_[rule.left]);
               first.erase(empty_token_id);
            }
            changed |= unite_sets(FOLLOW_[non_terminal], first);
         }
      }
   } while (changed);
}

void grammar_t::check_validity() const
{
   auto rules_range = rules | boost::adaptors::map_values;
   std::for_each(boost::begin(rules_range), boost::end(rules_range), check_rule);
}

void grammar_t::print_FIRST() const
{
   for (const rule_t & rule : rules | boost::adaptors::map_values)
   {
      std::cerr << "FIRST(" << range_to_string(rule.right) << ") = ";
      print_terminal_set(FIRST(rule.right));
   }
   std::cerr << std::endl;
   for (const nonterm_t & non_terminal : non_terminals)
   {
      std::cerr << "FIRST(" << non_terminal << ") = ";
      print_terminal_set(FIRST_.at(non_terminal));
   }
}

void grammar_t::print_FOLLOW() const
{
   for (const nonterm_t & non_terminal : non_terminals)
   {
      std::cerr << "FOLLOW(" << non_terminal << ") = ";
      print_terminal_set(FOLLOW(non_terminal));
   }
}

void grammar_t::print_terminal_set(const terminal_set & set) const
{
   for (auto id : set)
   {
      std::cerr << token_repr(id) << " ";
   }
   std::cerr << std::endl;
}
