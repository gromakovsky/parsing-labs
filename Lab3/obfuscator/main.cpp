#include "obfuscator.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main (int argc, char * argv[])
{
   bool trace_parsing;
   bool trace_scanning;
   po::options_description visible_options(std::string("Usage: ") + argv[0] + " [options] file ...\nOptions");
   visible_options.add_options()
   ("help", "display this help")
   ("output,o", po::value<std::string>(), "output file (stdout is used by default)")
   ("trace_parsing,p", po::value(&trace_parsing)->zero_tokens(), "trace parsing")
   ("trace_scanning,s", po::value(&trace_scanning)->zero_tokens(), "trace scanning")
   ("max_var_len,M", po::value<size_t>()->default_value(10), "max length of obfuscated variable name")
   ("min_var_len,m", po::value<size_t>()->default_value(1), "min length of obfuscated variable name")
   ;

   po::options_description hidden_options("Hidden options");
   hidden_options.add_options()
   ("input", po::value< std::vector<std::string> >(), "input file")
   ;

   po::options_description cmdline_options;
   cmdline_options.add(visible_options).add(hidden_options);

   po::positional_options_description p;
   p.add("input", -1);

   po::variables_map vm;
   po::store(po::command_line_parser(argc, argv).options(cmdline_options).positional(p).run(), vm);
   po::notify(vm);

   if (vm.count("help") || argc == 1)
   {
      std::cout << visible_options << std::endl;
      return EXIT_SUCCESS;
   }

   if (!vm.count("input"))
   {
      std::cerr << "At least 1 input file must be specified" << std::endl;
      return EXIT_FAILURE;
   }

   std::ostream * output = vm.count("output") ? new std::ofstream(vm["output"].as<std::string>()) : &std::cout;

   obfuscation::obfuscator o(*output, vm["min_var_len"].as<size_t>(), vm["max_var_len"].as<size_t>(), trace_parsing, trace_scanning);

   int res = 0;

   for (const auto & filename : vm["input"].as< std::vector<std::string> >())
   {
      res |= o.obfuscate(filename);
   }

   if (vm.count("output"))
   {
      delete output;
   }

   return res;
}