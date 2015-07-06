#pragma once

#include "node.h"
#include "cdecl_parser.hpp"

#include <istream>
#include <memory>

struct cdecl_context
{
   node_t * result();

   friend class cdecl_parser<cdecl_context>;

private:
   void construct(node_ptr & node, const std::string & str,
                  const std::vector<boost::variant<std::string, node_ptr>> & children);

private:
   std::shared_ptr<node_t> root_;
};
