#pragma once

#include "token.h"
#include "translating_symbol.h"

#include <string>
#include <vector>

#include <boost/variant/variant.hpp>
#include <boost/range/any_range.hpp>
#include <boost/iterator/iterator_categories.hpp>

using nonterm_t      = std::string;
using item_t         = boost::variant<nonterm_t, token_id_t, translating_symbol_t, empty_token_t>;
using items_range_t  = boost::any_range<item_t, boost::single_pass_traversal_tag, item_t, std::ptrdiff_t>;

struct rule_t
{
   nonterm_t            left;
   std::vector<item_t>  right;
};
