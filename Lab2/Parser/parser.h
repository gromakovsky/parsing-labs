#pragma once

#include "node.h"
#include "lexical_iterator.h"

#include <istream>
#include <set>

namespace parsing
{
   struct parser
   {
      parser(std::istream & is);

      node * parse();
      
private:
      node * S();
      node * SPrime();
      node * V();
      node * N();
      node * Q();

      void ensure(const std::set<token_t> & tokens) const;
      
private:      
      lexical_iterator it;
   };
}
