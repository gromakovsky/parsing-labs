#include "node.h"

namespace parsing
{
   node::node(const std::string & s) : s(s)
   {
   }

   void node::add_child(node * child)
   {
      children.push_back(child);
   }

   void node::add_child(const std::string & s)
   {
      children.push_back(new node(s));
   }
   
   std::vector<node *> node::get_children() const
   {
      return children;
   }
   
   std::string node::get_name() const
   {
      return s;
   }
}
