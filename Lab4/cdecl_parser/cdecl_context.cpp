#include "cdecl_context.h"

node_t * cdecl_context::result()
{
   return root_.get();
}

void cdecl_context::construct(node_ptr & node, const std::string & str,
                              const std::vector<boost::variant<std::string, node_ptr> > & children)
{
   node = std::make_shared<node_t>(str);
   node->add_children(children);
}
