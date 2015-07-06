// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "obfuscation_parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "obfuscation_parser.h"

// User implementation prologue.

#line 51 "obfuscation_parser.cpp" // lalr1.cc:407
// Unqualified %code blocks.
#line 35 "obfuscation_parser.yy" // lalr1.cc:408

   #include "obfuscator.h"

#line 57 "obfuscation_parser.cpp" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 143 "obfuscation_parser.cpp" // lalr1.cc:474

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  obfuscation_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  obfuscation_parser::obfuscation_parser (obfuscation::obfuscator & o_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      o (o_yyarg)
  {}

  obfuscation_parser::~obfuscation_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  obfuscation_parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  obfuscation_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  obfuscation_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  obfuscation_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  obfuscation_parser::symbol_number_type
  obfuscation_parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  obfuscation_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  obfuscation_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 22: // NUMBER
        value.move< int > (that.value);
        break;

      case 18: // DIRECTIVE
      case 19: // QUALIFIER
      case 20: // IDENTIFIER
      case 21: // STRING_LITERAL
      case 25: // var_declaration
      case 26: // typename
      case 27: // asterisks
      case 28: // ampersands
      case 29: // qualifiers
      case 30: // namespaces
      case 31: // variable_list
      case 32: // variable
      case 33: // func_prototype
      case 34: // argument_list
      case 35: // func_definition
      case 36: // statement_list
      case 37: // statement
      case 38: // constant
      case 39: // expression
      case 40: // function_call
      case 41: // expr_list
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  obfuscation_parser::stack_symbol_type&
  obfuscation_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 22: // NUMBER
        value.copy< int > (that.value);
        break;

      case 18: // DIRECTIVE
      case 19: // QUALIFIER
      case 20: // IDENTIFIER
      case 21: // STRING_LITERAL
      case 25: // var_declaration
      case 26: // typename
      case 27: // asterisks
      case 28: // ampersands
      case 29: // qualifiers
      case 30: // namespaces
      case 31: // variable_list
      case 32: // variable
      case 33: // func_prototype
      case 34: // argument_list
      case 35: // func_definition
      case 36: // statement_list
      case 37: // statement
      case 38: // constant
      case 39: // expression
      case 40: // function_call
      case 41: // expr_list
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  obfuscation_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  obfuscation_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 18: // DIRECTIVE

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 352 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 19: // QUALIFIER

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 359 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 20: // IDENTIFIER

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 366 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 21: // STRING_LITERAL

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 373 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 22: // NUMBER

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< int > (); }
#line 380 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 25: // var_declaration

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 387 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 26: // typename

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 394 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 27: // asterisks

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 401 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 28: // ampersands

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 408 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 29: // qualifiers

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 415 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 30: // namespaces

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 422 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 31: // variable_list

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 429 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 32: // variable

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 436 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 33: // func_prototype

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 443 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 34: // argument_list

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 450 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 35: // func_definition

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 457 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 36: // statement_list

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 464 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 37: // statement

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 471 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 38: // constant

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 478 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 39: // expression

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 485 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 40: // function_call

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 492 "obfuscation_parser.cpp" // lalr1.cc:617
        break;

      case 41: // expr_list

#line 87 "obfuscation_parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< std::string > (); }
#line 499 "obfuscation_parser.cpp" // lalr1.cc:617
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  obfuscation_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  obfuscation_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  obfuscation_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  obfuscation_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  obfuscation_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  obfuscation_parser::debug_level_type
  obfuscation_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  obfuscation_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline obfuscation_parser::state_type
  obfuscation_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  obfuscation_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  obfuscation_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  obfuscation_parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 26 "obfuscation_parser.yy" // lalr1.cc:725
{
   // Initialize the initial location.
   yyla.location.begin.filename = yyla.location.end.filename = &o.current_input;
}

#line 621 "obfuscation_parser.cpp" // lalr1.cc:725

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (o));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 22: // NUMBER
        yylhs.value.build< int > ();
        break;

      case 18: // DIRECTIVE
      case 19: // QUALIFIER
      case 20: // IDENTIFIER
      case 21: // STRING_LITERAL
      case 25: // var_declaration
      case 26: // typename
      case 27: // asterisks
      case 28: // ampersands
      case 29: // qualifiers
      case 30: // namespaces
      case 31: // variable_list
      case 32: // variable
      case 33: // func_prototype
      case 34: // argument_list
      case 35: // func_definition
      case 36: // statement_list
      case 37: // statement
      case 38: // constant
      case 39: // expression
      case 40: // function_call
      case 41: // expr_list
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 3:
#line 94 "obfuscation_parser.yy" // lalr1.cc:847
    { o.output << yystack_[0].value.as< std::string > () << std::endl; }
#line 763 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 4:
#line 95 "obfuscation_parser.yy" // lalr1.cc:847
    { o.output << yystack_[0].value.as< std::string > () << std::endl; }
#line 769 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 96 "obfuscation_parser.yy" // lalr1.cc:847
    { o.output << yystack_[1].value.as< std::string > () << ';' << std::endl; }
#line 775 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 6:
#line 97 "obfuscation_parser.yy" // lalr1.cc:847
    { o.output << yystack_[0].value.as< std::string > () << std::endl; }
#line 781 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 7:
#line 100 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + ' ' + yystack_[1].value.as< std::string > () + ";\n"
                                          + "bool" + ' ' + o.generate_name() + ";";}
#line 788 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 8:
#line 104 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[3].value.as< std::string > () + yystack_[2].value.as< std::string > () + yystack_[1].value.as< std::string > () + " " + yystack_[0].value.as< std::string > (); }
#line 794 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 9:
#line 107 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = ""; }
#line 800 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 108 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = "*" + yystack_[0].value.as< std::string > (); }
#line 806 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 111 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = ""; }
#line 812 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 112 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = "&"; }
#line 818 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 113 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = "&&"; }
#line 824 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 116 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = ""; }
#line 830 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 117 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > () + ' ' + yystack_[0].value.as< std::string > (); }
#line 836 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 120 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = ""; }
#line 842 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 121 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = std::string("::") + yystack_[0].value.as< std::string > (); }
#line 848 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 124 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > (); }
#line 854 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 125 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + ", " + yystack_[0].value.as< std::string > (); }
#line 860 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 128 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + " " + yystack_[1].value.as< std::string > () + " " + o.process_name(yystack_[0].value.as< std::string > ()); }
#line 866 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 131 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[6].value.as< std::string > () + yystack_[5].value.as< std::string > () + yystack_[4].value.as< std::string > () + ' ' + yystack_[3].value.as< std::string > () + '(' + yystack_[1].value.as< std::string > () + ')'; }
#line 872 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 132 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[5].value.as< std::string > () + yystack_[4].value.as< std::string > () + yystack_[3].value.as< std::string > () + ' ' + yystack_[2].value.as< std::string > () + "()"; }
#line 878 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 135 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > () + ' ' + yystack_[0].value.as< std::string > (); }
#line 884 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 136 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[3].value.as< std::string > () + ' ' + yystack_[2].value.as< std::string > () + ", " + yystack_[0].value.as< std::string > (); }
#line 890 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 139 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[3].value.as< std::string > () + "\n{\n" + yystack_[1].value.as< std::string > () + "\n}\n"; }
#line 896 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 142 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = ""; }
#line 902 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 143 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > () + "\n" + yystack_[0].value.as< std::string > (); }
#line 908 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 146 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = o.process_name(yystack_[3].value.as< std::string > ()) + " = " + yystack_[1].value.as< std::string > () + ";"; }
#line 914 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 147 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > (); }
#line 920 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 148 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > (); }
#line 926 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 31:
#line 149 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = "return " + yystack_[1].value.as< std::string > () + ";"; }
#line 932 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 32:
#line 152 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = o.split_string(yystack_[0].value.as< std::string > ()); }
#line 938 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 33:
#line 153 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = o.convert_number(yystack_[0].value.as< int > ()); }
#line 944 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 156 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = o.process_name(yystack_[0].value.as< std::string > ()); }
#line 950 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 157 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = std::string("&") + o.process_name(yystack_[0].value.as< std::string > ()); }
#line 956 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 158 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = std::string("*") + o.process_name(yystack_[0].value.as< std::string > ()); }
#line 962 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 37:
#line 159 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > (); }
#line 968 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 38:
#line 160 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + " + " + yystack_[0].value.as< std::string > (); }
#line 974 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 161 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + " - " + yystack_[0].value.as< std::string > (); }
#line 980 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 162 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + " * " + yystack_[0].value.as< std::string > (); }
#line 986 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 163 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + " / " + yystack_[0].value.as< std::string > (); }
#line 992 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 42:
#line 166 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[4].value.as< std::string > () + yystack_[3].value.as< std::string > () + "(" + ")" + ";"; }
#line 998 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 167 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[5].value.as< std::string > () + yystack_[4].value.as< std::string > () + "(" + yystack_[2].value.as< std::string > () + ")" + ";"; }
#line 1004 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 170 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > (); }
#line 1010 "obfuscation_parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 171 "obfuscation_parser.yy" // lalr1.cc:847
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + ", " + yystack_[0].value.as< std::string > (); }
#line 1016 "obfuscation_parser.cpp" // lalr1.cc:847
    break;


#line 1020 "obfuscation_parser.cpp" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  obfuscation_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  obfuscation_parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char obfuscation_parser::yypact_ninf_ = -25;

  const signed char obfuscation_parser::yytable_ninf_ = -1;

  const signed char
  obfuscation_parser::yypact_[] =
  {
     -25,     5,   -25,   -25,    24,   -25,    10,    27,    26,   -25,
     -25,    10,    18,    33,    38,    39,    -9,   -25,   -25,    71,
      44,   -25,    10,    49,    24,     6,    17,   -25,    10,    69,
      60,   -25,   -25,    65,    18,   -25,   -25,   -25,    63,    64,
     -25,   -25,   -25,   -25,    36,     6,    73,   -25,   -25,    -4,
      66,   -25,   -25,     6,     6,     6,     6,   -25,    46,    -3,
     -25,    10,    75,   -25,    52,    57,    62,    67,   -25,    74,
      30,    78,    76,   -25,   -25,     6,    77,    24,   -25,   -25,
     -25
  };

  const unsigned char
  obfuscation_parser::yydefact_[] =
  {
       2,    14,     1,     3,    14,     4,     9,     0,     0,     6,
      15,     9,    11,     0,    18,    16,    26,     5,    10,    12,
       0,     7,     9,     0,    14,     0,    16,    29,     9,     0,
      26,    30,    13,    20,    11,    19,    17,     8,     0,     0,
      34,    32,    33,    37,     0,     0,     0,    25,    27,    14,
       0,    36,    35,     0,     0,     0,     0,    31,     0,     0,
      22,     9,     0,    20,    39,    38,    40,    41,    28,     0,
      44,     0,    23,    21,    42,     0,     0,    14,    45,    43,
      24
  };

  const signed char
  obfuscation_parser::yypgoto_[] =
  {
     -25,   -25,    88,    -1,     3,    58,    -2,    68,    79,    32,
     -25,    19,   -25,    70,   -25,   -25,   -24,   -25,    20
  };

  const signed char
  obfuscation_parser::yydefgoto_[] =
  {
      -1,     1,    27,    28,    34,    20,     7,    24,    13,    14,
       8,    62,     9,    29,    30,    43,    70,    31,    71
  };

  const unsigned char
  obfuscation_parser::yytable_[] =
  {
       6,    44,    10,    38,    39,     2,    60,    69,    25,    12,
       4,    26,    38,    39,    18,     4,    11,    40,    41,    42,
      45,    58,    37,     3,     4,    19,    40,    41,    42,    64,
      65,    66,    67,    23,    53,    54,    55,    16,    56,    17,
      53,    54,    55,     4,    56,    75,    21,    15,    61,    57,
      53,    54,    55,    22,    56,    23,    53,    54,    55,    68,
      56,    53,    54,    55,    33,    56,    53,    54,    55,    36,
      56,    53,    54,    55,    49,    56,    61,    25,    32,     4,
      26,    47,    59,    51,    52,    73,    63,    74,    76,     5,
      79,    77,    50,    72,    46,    78,    80,     0,     0,     0,
      48,    35
  };

  const signed char
  obfuscation_parser::yycheck_[] =
  {
       1,    25,     4,     6,     7,     0,    10,    10,    17,     6,
      19,    20,     6,     7,    11,    19,     6,    20,    21,    22,
       3,    45,    24,    18,    19,     7,    20,    21,    22,    53,
      54,    55,    56,    16,     4,     5,     6,    11,     8,    13,
       4,     5,     6,    19,     8,    15,    13,    20,    49,    13,
       4,     5,     6,    15,     8,    16,     4,     5,     6,    13,
       8,     4,     5,     6,    20,     8,     4,     5,     6,    20,
       8,     4,     5,     6,     9,     8,    77,    17,     7,    19,
      20,    12,     9,    20,    20,    10,    20,    13,    10,     1,
      13,    15,    34,    61,    26,    75,    77,    -1,    -1,    -1,
      30,    22
  };

  const unsigned char
  obfuscation_parser::yystos_[] =
  {
       0,    24,     0,    18,    19,    25,    26,    29,    33,    35,
      29,     6,    27,    31,    32,    20,    11,    13,    27,     7,
      28,    13,    15,    16,    30,    17,    20,    25,    26,    36,
      37,    40,     7,    20,    27,    31,    20,    29,     6,     7,
      20,    21,    22,    38,    39,     3,    30,    12,    36,     9,
      28,    20,    20,     4,     5,     6,     8,    13,    39,     9,
      10,    26,    34,    20,    39,    39,    39,    39,    13,    10,
      39,    41,    32,    10,    13,    15,    10,    15,    41,    13,
      34
  };

  const unsigned char
  obfuscation_parser::yyr1_[] =
  {
       0,    23,    24,    24,    24,    24,    24,    25,    26,    27,
      27,    28,    28,    28,    29,    29,    30,    30,    31,    31,
      32,    33,    33,    34,    34,    35,    36,    36,    37,    37,
      37,    37,    38,    38,    39,    39,    39,    39,    39,    39,
      39,    39,    40,    40,    41,    41
  };

  const unsigned char
  obfuscation_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     3,     2,     3,     4,     0,
       2,     0,     1,     2,     0,     2,     0,     2,     1,     3,
       3,     7,     6,     2,     4,     4,     0,     2,     4,     1,
       1,     3,     1,     1,     1,     2,     2,     1,     3,     3,
       3,     3,     5,     6,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const obfuscation_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"=\"", "\"-\"", "\"+\"",
  "\"*\"", "\"&\"", "\"/\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\";\"",
  "\"#\"", "\",\"", "\"::\"", "\"return\"", "DIRECTIVE", "QUALIFIER",
  "IDENTIFIER", "STRING_LITERAL", "NUMBER", "$accept", "program",
  "var_declaration", "typename", "asterisks", "ampersands", "qualifiers",
  "namespaces", "variable_list", "variable", "func_prototype",
  "argument_list", "func_definition", "statement_list", "statement",
  "constant", "expression", "function_call", "expr_list", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  obfuscation_parser::yyrline_[] =
  {
       0,    93,    93,    94,    95,    96,    97,   100,   104,   107,
     108,   111,   112,   113,   116,   117,   120,   121,   124,   125,
     128,   131,   132,   135,   136,   139,   142,   143,   146,   147,
     148,   149,   152,   153,   156,   157,   158,   159,   160,   161,
     162,   163,   166,   167,   170,   171
  };

  // Print the state stack on the debug stream.
  void
  obfuscation_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  obfuscation_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1447 "obfuscation_parser.cpp" // lalr1.cc:1155
#line 172 "obfuscation_parser.yy" // lalr1.cc:1156


void yy::obfuscation_parser::error(const location_type& l, const std::string& m)
{
   o.error(l, m);
}

