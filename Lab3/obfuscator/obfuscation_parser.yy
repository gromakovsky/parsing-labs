%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.2"
%defines

%define parser_class_name {obfuscation_parser}

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires
{
   #include <string>
   namespace obfuscation 
   {
   class obfuscator;
   }
}

%glr-parser
// The parsing context.
%param { obfuscation::obfuscator & o }

%locations
%initial-action
{
   // Initialize the initial location.
   @$.begin.filename = @$.end.filename = &o.current_input;
};

%define parse.trace
%define parse.error verbose

%code
{
   #include "obfuscator.h"
}

%define api.token.prefix {TOK_}
%token
   END  0    "end of file"
   ASSIGN    "="
   MINUS     "-"
   PLUS      "+"
   ASTERISK  "*"
   AMPERSAND    "&"
   SLASH     "/"
   LPAREN    "("
   RPAREN    ")"
   LBRACE    "{"
   RBRACE    "}"
   SEMICOLON ";"
   SHARP     "#"
   COMMA        ","
   DOUBLECOLON  "::"
   RETURN       "return"
  ;

%token <std::string> DIRECTIVE 

%token <std::string> QUALIFIER
%token <std::string> IDENTIFIER

%token <std::string> STRING_LITERAL
%token <int> NUMBER

%type <std::string> var_declaration 
    %type <std::string> typename 
        %type <std::string> qualifiers
        %type <std::string> namespaces 
    %type <std::string> variable_list
        %type <std::string> variable
        %type <std::string> asterisks 
        %type <std::string> ampersands 

%type <std::string> func_prototype
    %type <std::string> argument_list

%type <std::string> func_definition
    %type <std::string> statement_list
    %type <std::string> statement
    %type <std::string> expression
    %type <std::string> constant
    %type <std::string> function_call
        %type <std::string> expr_list 

%printer { yyoutput << $$; } <*>;

%%
%start program;

program:
    %empty
|   program DIRECTIVE { o.output << $2 << std::endl; }
|   program var_declaration { o.output << $2 << std::endl; }
|   program func_prototype SEMICOLON { o.output << $2 << ';' << std::endl; }
|   program func_definition { o.output << $2 << std::endl; }

var_declaration:
    typename variable_list SEMICOLON { $$ = $1 + ' ' + $2 + ";\n"
                                          + "bool" + ' ' + o.generate_name() + ";";}  // declare meaningless variable

typename:
    qualifiers IDENTIFIER namespaces qualifiers { $$ = $1 + $2 + $3 + " " + $4; }

asterisks:
    %empty { $$ = ""; }
|   ASTERISK asterisks { $$ = "*" + $2; }

ampersands:
    %empty { $$ = ""; }
|   AMPERSAND { $$ = "&"; }
|   AMPERSAND AMPERSAND { $$ = "&&"; }

qualifiers:
    %empty                  { $$ = ""; }
|   QUALIFIER qualifiers    { $$ = $1 + ' ' + $2; }

namespaces:
    %empty                  { $$ = ""; }
|   DOUBLECOLON IDENTIFIER  { $$ = std::string("::") + $2; }

variable_list:
    variable                  { $$ = $1; }
|   variable COMMA variable_list                { $$ = $1 + ", " + $3; }

variable:
    asterisks ampersands IDENTIFIER              { $$ = $1 + " " + $2 + " " + o.process_name($3); }

func_prototype:
    typename asterisks ampersands IDENTIFIER LPAREN argument_list RPAREN { $$ = $1 + $2 + $3 + ' ' + $4 + '(' + $6 + ')'; }
|   typename asterisks ampersands IDENTIFIER LPAREN RPAREN { $$ = $1 + $2 + $3 + ' ' + $4 + "()"; }

argument_list:
    typename variable     { $$ = $1 + ' ' + $2; }
|   typename variable COMMA argument_list { $$ = $1 + ' ' + $2 + ", " + $4; }

func_definition:
    func_prototype LBRACE statement_list RBRACE { $$ = $1 + "\n{\n" + $3 + "\n}\n"; }

statement_list:
    %empty      { $$ = ""; }
|   statement statement_list      { $$ = $1 + "\n" + $2; }

statement:
    IDENTIFIER ASSIGN expression SEMICOLON            { $$ = o.process_name($1) + " = " + $3 + ";"; }
|   var_declaration                         { $$ = $1; }
|   function_call                           { $$ = $1; }
|   RETURN expression SEMICOLON { $$ = "return " + $2 + ";"; }

constant:
    STRING_LITERAL { $$ = o.split_string($1); }
|   NUMBER { $$ = o.convert_number($1); }

expression:
    IDENTIFIER { $$ = o.process_name($1); }
|   AMPERSAND IDENTIFIER { $$ = std::string("&") + o.process_name($2); }
|   ASTERISK IDENTIFIER { $$ = std::string("*") + o.process_name($2); }
|   constant { $$ = $1; }
|   expression PLUS expression { $$ = $1 + " + " + $3; }
|   expression MINUS expression { $$ = $1 + " - " + $3; }
|   expression ASTERISK expression { $$ = $1 + " * " + $3; }
|   expression SLASH expression { $$ = $1 + " / " + $3; }

function_call:
    IDENTIFIER namespaces LPAREN RPAREN SEMICOLON   { $$ = $1 + $2 + "(" + ")" + ";"; }
|   IDENTIFIER namespaces LPAREN expr_list RPAREN SEMICOLON { $$ = $1 + $2 + "(" + $4 + ")" + ";"; }

expr_list:
    expression { $$ = $1; }
|   expression COMMA expr_list { $$ = $1 + ", " + $3; }
%%

void yy::obfuscation_parser::error(const location_type& l, const std::string& m)
{
   o.error(l, m);
}

