#include "generating.h"

#include <sstream>

#include <boost/range/iterator_range.hpp>
#include <boost/variant/get.hpp>
#include <boost/optional/optional.hpp>

std::string generate_function(const grammar_ptr & grammar, const nonterm_t & non_term)
{
   std::stringstream ss;

   boost::optional<std::string> result_type;
   if (grammar->non_term_types.count(non_term))
   {
      result_type = grammar->non_term_types[non_term];
      ss << *result_type << " result_;" << std::endl;
   }

   ss << "switch (*it_)" << std::endl
      << "{" << std::endl
      ;

   auto rules_range = boost::make_iterator_range(grammar->rules.equal_range(non_term));
   for (const auto & pair : rules_range)
   {
      rule_t rule = pair.second;
      ss << "// " << rule.left << " → " << grammar->range_to_string(rule.right) << std::endl;
      for (token_id_t token_id : grammar->FIRST(rule.right))
      {
         if (token_id == empty_token_id)
         {
            for (token_id_t token_id : grammar->FOLLOW(rule.left))
            {
               ss << "\tcase " << token_id << ": //" << grammar->token_repr(token_id) << std::endl;
            }
         }
         else
         {
            ss << "\tcase " << token_id << ": //" << grammar->token_repr(token_id) << std::endl;
         }
      }
      ss << "\t{" << std::endl;
      size_t item_id = 0;
      for (const item_t & item : rule.right)
      {
         ss << "\t\t// " << grammar->item_to_string(item);
         ss << std::endl;

         if (item.which() == 3) // empty_token_t
         {
            break;
         }
         switch (item.which())
         {
            case 0: // nonterm_t
            {
               const nonterm_t & nonterm = boost::get<nonterm_t>(item);
               if (grammar->non_term_types.count(nonterm))
               {
                  auto type = grammar->non_term_types.at(nonterm);
                  ss << "\t\t" << type << " value" << item_id << "_ = " << nonterm << "();" << std::endl;
               }
               else
               {
                  ss << "\t\t" << nonterm << "();" << std::endl;
               }

               ss << std::endl;
               break;
            }
            case 1: // token_id_t
            {
               token_id_t token_id = boost::get<token_id_t>(item);
               ss << "\t\tensure(" << token_id << ");" << std::endl
                  << "\t\tstd::string value" << item_id << "_ = " << "it_.representation();" << std::endl
                  << "\t\t++it_;" << std::endl
                  << std::endl
                  ;
               break;
            }
            case 2: // translating_symbol_t
            {
               const translating_symbol_t & translating_symbol = boost::get<translating_symbol_t>(item);
               ss << translating_symbol.code << std::endl;
               break;
            }
            default: // empty_token_t or something weird
            {
               BOOST_THROW_EXCEPTION(std::logic_error("Unreachable place"));
            }
         }
         ++item_id;
      }
      ss << "\t\tbreak;" << std::endl
         << "\t}" << std::endl;
   }
   ss << "\tdefault:" << std::endl
      << "\t{" << std::endl
      << "\t\tstd::stringstream message;" << std::endl
      << "\t\tmessage << \"Grammar mismatch at position \" << it_.pos() << \":\" << std::endl" << std::endl
      << "\t\t\t<< \"Unexpected \" << it_.representation() << std::endl" << std::endl
      << "\t\t\t;" << std::endl
      << "\t\tthrow parsing_error(message.str().c_str());" << std::endl
      << "\t}" << std::endl
      ;

   ss << "}" << std::endl;

   if (result_type)
   {
      ss << "return result_;" << std::endl;
   }
   return ss.str();
}
