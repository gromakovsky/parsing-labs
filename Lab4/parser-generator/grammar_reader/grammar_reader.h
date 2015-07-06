#pragma once

#include "grammar_parser.h"
#include "grammar.h"

#include <string>

// Tell Flex the lexer's prototype ...
# define YY_DECL yy::grammar_parser::symbol_type yylex(grammar_reader & gr)
// ... and declare it for the parser's sake.
YY_DECL;

struct grammar_reader
{
   friend class yy::grammar_parser;

   grammar_ptr read_grammar(const std::string & filename, bool verbose = false,
                            bool trace_scanning = false, bool trace_parsing = false);

private:
   // Handling the scanner.
   void start_scan(const std::string & filename, bool trace_scanning = false);
   void finish_scan();

   // Error handling.
   void error(const yy::location & l, const std::string & m) const;
   void error(const std::string & m) const;

private:
   std::string input_;

   grammar_t grammar;
};
