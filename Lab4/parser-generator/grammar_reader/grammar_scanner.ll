%{ /* -*- C++ -*- */
#include "grammar_reader.h"
#include "grammar_parser.h"
#include "errors.h"

typedef boost::error_info<struct tag_unexpected_character, char> errinfo_char;
typedef boost::error_info<struct tag_location, yy::location> errinfo_location;

#include <string>
// Work around an incompatibility in flex (at least versions
// 2.5.31 through 2.5.33): it generates code that does
// not conform to C89.  See Debian bug 333231
// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
# undef yywrap
# define yywrap() 1

// The location of the current token.
static yy::location loc;
%}

%option noyywrap nounput batch debug noinput

empty_word  %empty
cpp_id      [a-zA-Z][a-zA-Z_0-9]*
type_name   %type\ ({cpp_id}::)*{cpp_id}\**

int         [0-9]+
translating \{.*\}
lowercase   [a-z]+
uppercase   [A-Z]+

blank       [ \t]
comment     \/\/.*\n

%{
   // Code run each time a pattern is matched.
   #define YY_USER_ACTION  loc.columns (yyleng);
%}

%%
%{
   // Code run each time yylex is called.
   loc.step ();
%}

{blank}+          loc.step();
{comment}         loc.lines(1); loc.step();
[\n]{2,}          loc.lines(yyleng); loc.step (); return yy::grammar_parser::make_NEWLINES(yytext, loc);
[\n]              loc.lines(1); loc.step();

{empty_word}      return yy::grammar_parser::make_EPSILON("", loc);
{type_name}       return yy::grammar_parser::make_TYPENAME(std::string(yytext).substr(6), loc);

"::="             return yy::grammar_parser::make_GRAMMAR_DELIMITER(loc);
{translating}     return yy::grammar_parser::make_TRANSLATING(yytext, loc);
{lowercase}       return yy::grammar_parser::make_NONTERM(yytext, loc);
{uppercase}       return yy::grammar_parser::make_TERMINAL(yytext, loc);
{int}             return yy::grammar_parser::make_NUMBER(std::stoi(yytext), loc);

.                 BOOST_THROW_EXCEPTION(grammar_unexpected_character() << errinfo_char(yytext[0]) << errinfo_location(loc));
<<EOF>>           return yy::grammar_parser::make_END(loc);
%%

#include <cerrno>

#include <boost/exception/all.hpp>

void grammar_reader::start_scan(const std::string & filename, bool trace_scanning)
{
    yy_flex_debug = trace_scanning;
    if (!(yyin = fopen(filename.c_str (), "r")))
    {
      BOOST_THROW_EXCEPTION(grammar_file_open_error() 
                            << boost::errinfo_api_function("fopen")
                            << boost::errinfo_errno(errno)
                            << boost::errinfo_file_name(filename)
                            << boost::errinfo_file_open_mode("r"));
    }
}

void grammar_reader::finish_scan()
{
  fclose(yyin);
}

