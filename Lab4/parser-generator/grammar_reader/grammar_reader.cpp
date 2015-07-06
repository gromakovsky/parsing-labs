#include "grammar_reader.h"

#include "errors.h"

#include <iostream>
#include <memory>

grammar_ptr grammar_reader::read_grammar(const std::string & filename, bool verbose/* = false*/,
                                         bool trace_scanning/* = false*/,
                                         bool trace_parsing/* = false*/)
{
   input_ = filename;
   start_scan(input_, trace_scanning);

   yy::grammar_parser parser(*this);
   parser.set_debug_level(trace_parsing);
   parser.parse();

   finish_scan();

   grammar.token_bimap.insert({"EOF", 0});

   grammar.check_validity();
   grammar.set_internal_fields(verbose);

   return std::make_shared<grammar_t>(grammar);
}

void grammar_reader::error(const yy::location & l, const std::string & m) const
{
   std::cerr << l << ": " << m << std::endl;
}

void grammar_reader::error(const std::string & m) const
{
   std::cerr << m << std::endl;
}
