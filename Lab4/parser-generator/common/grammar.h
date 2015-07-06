#pragma once

#include "rule.h"

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>

#include <boost/bimap/bimap.hpp>

using terminal_set = std::unordered_set<token_id_t>;

struct grammar_t
{
   const nonterm_t start_non_terminal = "start";

   boost::bimaps::bimap<std::string, token_id_t>         token_bimap;
   std::unordered_map<nonterm_t, std::string>            non_term_types;
   std::unordered_set<nonterm_t>                         non_terminals;
   std::unordered_multimap<nonterm_t, rule_t>            rules;

   token_id_t     token_id(const std::string & token)          const;
   std::string    token_repr(token_id_t id)                    const;
   std::string    item_to_string(const item_t & item)          const;
   std::string    range_to_string(const items_range_t & alpha) const;

   terminal_set   FIRST(const items_range_t & alpha)           const;
   terminal_set   FOLLOW(const nonterm_t & non_terminal)       const;

   friend struct grammar_reader;

private:
   void set_internal_fields(bool verbose);

   void build_FIRST();
   void build_FOLLOW();

   void check_validity() const;

   void print_FIRST() const;
   void print_FOLLOW() const;

   void print_terminal_set(const terminal_set & set) const;

private:
   std::unordered_map<nonterm_t, terminal_set>   FIRST_;
   std::unordered_map<nonterm_t, terminal_set>   FOLLOW_;
};

using grammar_ptr = std::shared_ptr<grammar_t>;
