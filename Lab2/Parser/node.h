#pragma once

#include <vector>
#include <string>

namespace parsing
{
   class node
   {
      std::string s;
      std::vector<node *> children;
   public:
      node(const std::string & s);

      void add_child(node * child);
      void add_child(const std::string & s);
      
      std::vector<node *> get_children() const;
      std::string get_name() const;
   };
}