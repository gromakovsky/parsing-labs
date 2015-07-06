%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.2"
%defines

%define parser_class_name {grammar_parser}

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires
{
   #include <string>
   #include "rule.h"
   class grammar_reader;
}

//%glr-parser

// The parsing context.
%param { grammar_reader & gr }

%locations
%initial-action
{
   // Initialize the initial location.
   @$.begin.filename = @$.end.filename = &gr.input_;
};

%define parse.trace
%define parse.error verbose

%code
{
   #include "grammar_reader.h"
   #include <utility>
}

%define api.token.prefix {TOK_}
%token
   END  0                  "end of file"
   LBRACE                  "{"
   RBRACE                  "}"
   SEMICOLON               ";"
   GRAMMAR_DELIMITER       "::="
  ;

%token <size_t> NUMBER;

%token <std::string> NEWLINES

%token <std::string> EPSILON
%token <std::string> TYPENAME
%token <std::string> NONTERM
%token <std::string> TERMINAL
%token <std::string> TRANSLATING

%type <std::vector<item_t>>   right_part
%type <item_t>                right_part_item
%%

%start grammar_description;

grammar_description:
   ids
   NEWLINES
   types
   rules 

ids:
   %empty
|  TERMINAL NUMBER 
   { gr.grammar.token_bimap.insert( {$1, $2} ); }
   ids

types:
   %empty
|  TYPENAME NONTERM
   { gr.grammar.non_term_types[$2] = $1; }
   types

rules:
   %empty
|  NEWLINES
   rule rules

rule:
    NONTERM GRAMMAR_DELIMITER right_part
    {
      rule_t rule = {$1, $3}; 
      gr.grammar.rules.insert( std::make_pair($1, rule) ); 
      gr.grammar.non_terminals.insert($1);
    }

right_part:
    right_part_item
    { $$.push_back($1); }
|   right_part right_part_item
    { $$ = $1; $$.push_back($2); }

right_part_item:
   EPSILON  { $$ = empty_token_t(); }
|  NONTERM  { $$ = $1; gr.grammar.non_terminals.insert($1); }
|  TERMINAL { $$ = gr.grammar.token_id($1); }
|  TRANSLATING { $$ = translating_symbol_t($1.substr(1, $1.length() - 2)); }

%%

void yy::grammar_parser::error(const location_type& l, const std::string& m)
{
   gr.error(l, m);
}

