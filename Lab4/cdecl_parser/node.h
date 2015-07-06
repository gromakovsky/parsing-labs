#pragma once

#include "node_fwd.h"

#include <vector>
#include <string>
#include <memory>

#include <boost/variant/variant.hpp>

struct node_t
{
   node_t(const std::string & str);

   void add_child(node_ptr child);
   void add_child(const std::string & str);

   void add_children(const std::vector<boost::variant<std::string, node_ptr>> & children);

   std::vector<node_ptr> get_children() const;
   std::string str() const;

private:
   std::string str_;
   std::vector<node_ptr> children_;
};
