#include "grammar_reader/grammar_reader.h"

#include "errors.h"
#include "parser-generating/generating.h"

#include <iostream>
#include <fstream>

#include <boost/exception/diagnostic_information.hpp>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main (int argc, char * argv[])
{
   bool verbose = false;
   bool trace_grammar_scanning = false;
   bool trace_grammar_parsing = false;
   po::options_description visible_options("Options");
   visible_options.add_options()
      ("help",                                                                         "display this help")
      ("parser-name,n",             po::value<std::string>()->default_value("parser"), "parser class name")
      ("verbose,v",                 po::value(&verbose)->zero_tokens(),                "be verbose")
      ("trace_grammar-scanning,s",  po::value(&trace_grammar_scanning)->zero_tokens(), "trace grammar scanning")
      ("trace-grammar-parsing,p",   po::value(&trace_grammar_parsing)->zero_tokens(),  "trace grammar parsing")
      ;

   po::options_description hidden_options("Hidden options");
   hidden_options.add_options()
      ("input",                     po::value<std::string>()->required(),              "input file")
      ;

   po::options_description cmdline_options;
   cmdline_options.add(visible_options).add(hidden_options);

   po::positional_options_description p;
   p.add("input", 1);

   po::variables_map vm;
   try
   {
      po::store(po::command_line_parser(argc, argv).options(cmdline_options).positional(p).run(), vm);
      if (vm.count("help"))
      {
         std::cout << "Usage: " << argv[0] << " [options] file" << std::endl
                   << visible_options << std::endl
                   ;
         return EXIT_SUCCESS;
      }

      po::notify(vm);
   }
   catch (const po::error & e)
   {
      std::cerr << "Command line options storing failed:" << std::endl
                << e.what() << std::endl
                << std::endl
                << "Try using --help option" << std::endl
                ;
      return EXIT_FAILURE;
   }

   grammar_reader reader;
   grammar_ptr grammar;

   try
   {
      grammar = reader.read_grammar(vm["input"].as<std::string>(), verbose,
            trace_grammar_scanning, trace_grammar_parsing);
   }
   catch (const grammar_read_error & e)
   {
      std::cerr << "Couldn't load grammar:" << std::endl
                << boost::diagnostic_information(e) << std::endl
                ;
      return EXIT_FAILURE;
   }

   const std::string parser_name = vm["parser-name"].as<std::string>();
   std::string filename = parser_name + ".hpp";

   std::ofstream output(filename.c_str());

   output << "/*" << std::endl
          << "\t\tThis file was automatically generated" << std::endl
          << "*/" << std::endl
          << std::endl
          ;

   output << "#pragma once" << std::endl << std::endl;

   const std::vector<std::string> helper_files = {
      "errors.h",
      "user_types.h",
      "lexical_iterator.h"
   };

   for (const auto & helper : helper_files)
   {
      output << "#include \"" << helper << '"' << std::endl;
   }
   output << "#include <sstream>" << std::endl
          << std::endl
          ;

   output << "// Declaration:" << std::endl
          << "template <class Context>" << std::endl
          << "struct " << parser_name << std::endl
          << "{" << std::endl
          << "\t" << parser_name << "(Context & ctx, lexical_iterator & it);" << std::endl
          << std::endl
          << "\tvoid start_parsing();" << std::endl
          << std::endl
          << "private:" << std::endl
          ;

   for (const auto & non_term : grammar->non_terminals)
   {
      std::string type;
      if (grammar->non_term_types.count(non_term))
      {
         type = grammar->non_term_types.at(non_term);
      }
      else
      {
         type = "void";
      }

      output << "\t" << type << " " << non_term << "();" << std::endl
             ;
   }

   output << std::endl
          << "\tvoid ensure(int token);" << std::endl
          << std::endl
          << "private:" << std::endl
          << "\tContext & ctx;" << std::endl
          << "\tlexical_iterator & it_;" << std::endl
          << "};" << std::endl
          ;


   output << std::endl
          << "// Definitions:" << std::endl
          << "template <class Context>" << std::endl
          << parser_name << "<Context>::" << parser_name << "(Context & ctx, lexical_iterator & it)" << std::endl
          << "\t: ctx(ctx)" << std::endl
          << "\t, it_(it)" << std::endl
          << "{}" << std::endl
          << std::endl
          << "template <class Context>" << std::endl
          << "void " <<  parser_name << "<Context>" << "::start_parsing()" << std::endl
          << "{" << std::endl
          << "\t" << grammar->start_non_terminal << "();" << std::endl
          << "\tensure(0);" << std::endl
          << "}" << std::endl
          << std::endl
          ;

   for (const auto & non_term : grammar->non_terminals)
   {
      std::string type;
      if (grammar->non_term_types.count(non_term))
      {
         type = grammar->non_term_types.at(non_term);
      }
      else
      {
         type = "void";
      }

      try
      {
      output << "template <class Context>" << std::endl
             << type << " " << parser_name << "<Context>" << "::" << non_term << "()" << std::endl
             << "{" << std::endl
             << generate_function(grammar, non_term) << std::endl
             << "}" << std::endl
             << std::endl
             ;
      }
      catch (const base_error & e)
      {
         std::cerr << "Generating failed:" << std::endl
                   << boost::diagnostic_information(e) << std::endl
                   ;
         return EXIT_FAILURE;
      }

   }

   output << "template <class Context>" << std::endl
          << "void " <<  parser_name << "<Context>" << "::ensure(int token)" << std::endl
          << "{" << std::endl
          << "\tif (*it_ != token)" << std::endl
          << "\t{" << std::endl
          << "\t\tstd::stringstream message;" << std::endl
          << "\t\tmessage << \"Grammar mismatch at position \" << it_.pos() << \":\" << std::endl" << std::endl
          << "\t\t\t<< \"Expected id \" << token << \", but found \" << it_.representation() << std::endl" << std::endl
          << "\t\t\t;" << std::endl
          << "\t\tthrow parsing_error(message.str().c_str());" << std::endl
          << "\t}" << std::endl
          << "}" << std::endl
          << std::endl
          ;

   return EXIT_SUCCESS;
}
