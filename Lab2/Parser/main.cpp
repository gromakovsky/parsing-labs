#include "parser.h"

#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>

#include <boost/graph/graphviz.hpp>

typedef std::pair<int, int> edge_t;
typedef boost::adjacency_list< boost::vecS, boost::vecS, boost::directedS> graph_t;

void dfs(parsing::node * v, std::vector<edge_t> & edges, std::vector<const char *> & names)
{
   size_t i = names.size();
   names.push_back(v->get_name().c_str());

   for (auto child : v->get_children())
   {
      edges.push_back({i, names.size()});
      dfs(child, edges, names);
   }
}

void parse_and_write_graph(std::istream & is)
{
   parsing::parser p(is);

   parsing::node * tree;
   try
   {
      tree = p.parse();
   }
   catch (std::exception & e)
   {
      std::cerr << "Unhandled exception: " << e.what() << std::endl;
      return;
   }

   std::vector<const char *> names;
   std::vector<edge_t> edges;
   dfs(tree, edges, names);
   graph_t graph(edges.begin(), edges.end(), names.size());
   write_graphviz(std::cout, graph, boost::make_label_writer(names.data()));
}

int main()
{
   std::ifstream in("input.txt");
   parse_and_write_graph(in);

   return 0;
}
