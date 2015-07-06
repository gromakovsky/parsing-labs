#include "cdecl_parser.hpp"
#include "cdecl_context.h"
#include "cdecl_lexical_iterator.h"
#include "node.h"

#include <fstream>
#include <iostream>
#include <exception>

#include <boost/graph/graphviz.hpp>

typedef std::pair<int, int>                                                edge_t;
typedef boost::adjacency_list< boost::vecS, boost::vecS, boost::directedS> graph_t;

void dfs(node_t * v, std::vector<edge_t> & edges, std::vector<const char *> & names)
{
   size_t i = names.size();

   names.push_back(v->str().c_str());

   for (auto child : v->get_children())
   {
      edges.push_back({i, names.size()});
      dfs(child.get(), edges, names);
   }
}

void write_graph(node_t * root, std::ostream & out)
{
   std::vector<const char *> names;
   std::vector<edge_t> edges;
   dfs(root, edges, names);
   graph_t graph(edges.begin(), edges.end(), names.size());
   boost::write_graphviz(out, graph, boost::make_label_writer(names.data()));
}

int main()
{
   std::ifstream in("input.txt");

   cdecl_context ctx;
   cdecl_lexical_iterator it(in);
   cdecl_parser<cdecl_context> parser(ctx, it);

   try
   {
      parser.start_parsing();
   }
   catch (const std::exception & e)
   {
      std::cerr << "Parser failed:" << std::endl
                << e.what() << std::endl
                ;
      return EXIT_FAILURE;
   }

   try
   {
      write_graph(ctx.result(), std::cout);
   }
   catch (const std::exception & e)
   {
      std::cerr << "Could not write graph:" << std::endl
                << e.what() << std::endl
                ;
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
