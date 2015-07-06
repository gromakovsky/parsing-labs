%{ /* -*- C++ -*- */
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <string>
#include "obfuscator.h"
#include "obfuscation_parser.h"

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

identifier  [a-zA-Z][a-zA-Z_0-9]*
qualifier   const|volatile
int         [0-9]+
blank       [ \t]
string      \".*\"
directive   #.*
comment     \/\/.*|\/\*[^\*]*\*\/

%{
   // Code run each time a pattern is matched.
   #define YY_USER_ACTION  loc.columns (yyleng);
%}

%%
%{
   // Code run each time yylex is called.
   loc.step ();
%}

{blank}+    loc.step();
{comment}   loc.step();
{directive}    return yy::obfuscation_parser::make_DIRECTIVE(yytext, loc);
[\n]+       loc.lines (yyleng); loc.step ();
"-" return yy::obfuscation_parser::make_MINUS(loc);
"+" return yy::obfuscation_parser::make_PLUS(loc);
"*" return yy::obfuscation_parser::make_ASTERISK(loc);
"/" return yy::obfuscation_parser::make_SLASH(loc);
"&" return yy::obfuscation_parser::make_AMPERSAND(loc);
"(" return yy::obfuscation_parser::make_LPAREN(loc);
")" return yy::obfuscation_parser::make_RPAREN(loc);
"{" return yy::obfuscation_parser::make_LBRACE(loc);
"}" return yy::obfuscation_parser::make_RBRACE(loc);
"=" return yy::obfuscation_parser::make_ASSIGN(loc);
"," return yy::obfuscation_parser::make_COMMA(loc);
";" return yy::obfuscation_parser::make_SEMICOLON(loc);
"::"                return yy::obfuscation_parser::make_DOUBLECOLON(loc);
"return"            return yy::obfuscation_parser::make_RETURN(loc);
{int} {
    long n = strtol (yytext, NULL, 10);
    return yy::obfuscation_parser::make_NUMBER(n, loc);
}
{string}            return yy::obfuscation_parser::make_STRING_LITERAL(yytext, loc);
{qualifier}         return yy::obfuscation_parser::make_QUALIFIER(yytext, loc);
{identifier}        return yy::obfuscation_parser::make_IDENTIFIER(yytext, loc);
.           std::cerr << loc << ": invalid character" << std::endl;
<<EOF>>     return yy::obfuscation_parser::make_END(loc);
%%

bool obfuscation::obfuscator::start_scan(const std::string & filename)
{
    yy_flex_debug = trace_scanning;
    if (!(yyin = fopen(filename.c_str (), "r")))
    {
      error("Couldn't open " + filename + ": " + strerror(errno));
      return false;
    }
    return true;
}

void obfuscation::obfuscator::finish_scan()
{
  fclose(yyin);
}

