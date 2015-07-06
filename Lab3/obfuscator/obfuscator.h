#pragma once

#include "obfuscation_parser.h"

#include <string>
#include <unordered_map>
#include <unordered_set>

// Tell Flex the lexer's prototype ...
# define YY_DECL yy::obfuscation_parser::symbol_type yylex(obfuscation::obfuscator & o)
// ... and declare it for the parser's sake.
YY_DECL;

namespace obfuscation
{
class obfuscator
{
   friend class yy::obfuscation_parser;
   
   std::string generate_name();
   std::string process_name(const std::string & name);
   
   std::string split_string(const std::string & str) const;
   
   std::string convert_number(int num) const;

   // Handling the scanner.
   bool start_scan(const std::string &);
   void finish_scan();
   
   // Error handling.
   void error(const yy::location & l, const std::string & m) const;
   void error(const std::string & m) const;

public:
   obfuscator(std::ostream & output, size_t min_len, size_t max_len, bool trace_parsing = false, bool trace_scanning = false);

   int obfuscate(const std::string & filename);

private:
   const std::vector<char> symbols_in_names = {'I', 'O', '0', '1'};
   const size_t MIN_LEN;
   const size_t MAX_LEN;

   std::random_device generator;
   std::uniform_int_distribution<size_t> length_distribution;
   std::uniform_int_distribution<size_t> symbol_distribution;
   
   std::unordered_map<std::string, std::string> names_map;
   std::unordered_set<std::string> generated_names;

   std::ostream & output;
   std::string current_input;

   bool trace_scanning;
   bool trace_parsing;
};
}