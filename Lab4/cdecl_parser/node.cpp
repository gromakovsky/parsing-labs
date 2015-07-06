#include "node.h"

#include <boost/variant/get.hpp>

node_t::node_t(const std::string & str) : str_(str)
{
}

void node_t::add_child(node_ptr child)
{
   children_.push_back(child);
}

void node_t::add_child(const std::string & str)
{
   children_.push_back(std::make_shared<node_t>(str));
}

void node_t::add_children(const std::vector<boost::variant<std::string, node_ptr>> & children)
{
   for (const auto & child : children)
   {
      if (child.which() == 0)
      {
         add_child(boost::get<std::string>(child));
      }
      else
      {
         add_child(boost::get<node_ptr>(child));
      }
   }
}

std::vector<node_ptr> node_t::get_children() const
{
   return children_;
}

std::string node_t::str() const
{
   return str_;
}
