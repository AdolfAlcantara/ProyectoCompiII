// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 21 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"

    #include <iostream>
    #include <unordered_map>
    #include "lexer.h"
    #include "expr_parser.h"

    #define yylex(arg) lexer.getNextToken(arg)

    namespace Expr
    {
        void Parser::error (const std::string& msg){
            
            std::cerr << msg << "\n";
            throw std::exception();
        }
    }

    // extern int yylineno;

    // void yyerror(std::unordered_map<std::string, int>& vars, const char* msg){
    //     throw std::string ("Line ")
    //     + std::to_string(yylineno)
    //     + ": "+msg;
    // }

#line 66 "expr_parser.cpp"


#include "expr_parser.h"




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

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



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
      *yycdebug_ << '\n';                       \
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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 8 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
namespace Expr {
#line 144 "expr_parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
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
  Parser::Parser (Ast::Node*&root_yyarg, ExprLexer& lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      root (root_yyarg),
      lexer (lexer_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 60: // expr
      case 61: // term
      case 62: // prod
      case 63: // factor
      case 64: // factor_p
        value.move< Ast::Expr* > (std::move (that.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // simple_stmts_p
      case 46: // func_stmt
      case 47: // while_stmt
      case 48: // for_stmt
      case 49: // if_stmt
      case 50: // if_opt
      case 51: // if_opt_p
      case 53: // assign_stmt
      case 55: // arg_list
      case 56: // arg_list_p
      case 57: // print_stmt
      case 58: // print_stmt_p
      case 59: // print_stmt_pp
        value.move< Ast::Node * > (std::move (that.value));
        break;

      case 23: // TK_NUMBER
        value.move< int > (std::move (that.value));
        break;

      case 22: // TK_STRING
      case 35: // TK_IDENTIFIER
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 60: // expr
      case 61: // term
      case 62: // prod
      case 63: // factor
      case 64: // factor_p
        value.copy< Ast::Expr* > (YY_MOVE (that.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // simple_stmts_p
      case 46: // func_stmt
      case 47: // while_stmt
      case 48: // for_stmt
      case 49: // if_stmt
      case 50: // if_opt
      case 51: // if_opt_p
      case 53: // assign_stmt
      case 55: // arg_list
      case 56: // arg_list_p
      case 57: // print_stmt
      case 58: // print_stmt_p
      case 59: // print_stmt_pp
        value.copy< Ast::Node * > (YY_MOVE (that.value));
        break;

      case 23: // TK_NUMBER
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 22: // TK_STRING
      case 35: // TK_IDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 60: // expr
      case 61: // term
      case 62: // prod
      case 63: // factor
      case 64: // factor_p
        value.move< Ast::Expr* > (YY_MOVE (s.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // simple_stmts_p
      case 46: // func_stmt
      case 47: // while_stmt
      case 48: // for_stmt
      case 49: // if_stmt
      case 50: // if_opt
      case 51: // if_opt_p
      case 53: // assign_stmt
      case 55: // arg_list
      case 56: // arg_list_p
      case 57: // print_stmt
      case 58: // print_stmt_p
      case 59: // print_stmt_pp
        value.move< Ast::Node * > (YY_MOVE (s.value));
        break;

      case 23: // TK_NUMBER
        value.move< int > (YY_MOVE (s.value));
        break;

      case 22: // TK_STRING
      case 35: // TK_IDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 60: // expr
      case 61: // term
      case 62: // prod
      case 63: // factor
      case 64: // factor_p
        value.YY_MOVE_OR_COPY< Ast::Expr* > (YY_MOVE (that.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // simple_stmts_p
      case 46: // func_stmt
      case 47: // while_stmt
      case 48: // for_stmt
      case 49: // if_stmt
      case 50: // if_opt
      case 51: // if_opt_p
      case 53: // assign_stmt
      case 55: // arg_list
      case 56: // arg_list_p
      case 57: // print_stmt
      case 58: // print_stmt_p
      case 59: // print_stmt_pp
        value.YY_MOVE_OR_COPY< Ast::Node * > (YY_MOVE (that.value));
        break;

      case 23: // TK_NUMBER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 22: // TK_STRING
      case 35: // TK_IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 60: // expr
      case 61: // term
      case 62: // prod
      case 63: // factor
      case 64: // factor_p
        value.move< Ast::Expr* > (YY_MOVE (that.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // simple_stmts_p
      case 46: // func_stmt
      case 47: // while_stmt
      case 48: // for_stmt
      case 49: // if_stmt
      case 50: // if_opt
      case 51: // if_opt_p
      case 53: // assign_stmt
      case 55: // arg_list
      case 56: // arg_list_p
      case 57: // print_stmt
      case 58: // print_stmt_p
      case 59: // print_stmt_pp
        value.move< Ast::Node * > (YY_MOVE (that.value));
        break;

      case 23: // TK_NUMBER
        value.move< int > (YY_MOVE (that.value));
        break;

      case 22: // TK_STRING
      case 35: // TK_IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 60: // expr
      case 61: // term
      case 62: // prod
      case 63: // factor
      case 64: // factor_p
        value.copy< Ast::Expr* > (that.value);
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // simple_stmts_p
      case 46: // func_stmt
      case 47: // while_stmt
      case 48: // for_stmt
      case 49: // if_stmt
      case 50: // if_opt
      case 51: // if_opt_p
      case 53: // assign_stmt
      case 55: // arg_list
      case 56: // arg_list_p
      case 57: // print_stmt
      case 58: // print_stmt_p
      case 59: // print_stmt_pp
        value.copy< Ast::Node * > (that.value);
        break;

      case 23: // TK_NUMBER
        value.copy< int > (that.value);
        break;

      case 22: // TK_STRING
      case 35: // TK_IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 60: // expr
      case 61: // term
      case 62: // prod
      case 63: // factor
      case 64: // factor_p
        value.move< Ast::Expr* > (that.value);
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // simple_stmts_p
      case 46: // func_stmt
      case 47: // while_stmt
      case 48: // for_stmt
      case 49: // if_stmt
      case 50: // if_opt
      case 51: // if_opt_p
      case 53: // assign_stmt
      case 55: // arg_list
      case 56: // arg_list_p
      case 57: // print_stmt
      case 58: // print_stmt_p
      case 59: // print_stmt_pp
        value.move< Ast::Node * > (that.value);
        break;

      case 23: // TK_NUMBER
        value.move< int > (that.value);
        break;

      case 22: // TK_STRING
      case 35: // TK_IDENTIFIER
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 60: // expr
      case 61: // term
      case 62: // prod
      case 63: // factor
      case 64: // factor_p
        yylhs.value.emplace< Ast::Expr* > ();
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // simple_stmts_p
      case 46: // func_stmt
      case 47: // while_stmt
      case 48: // for_stmt
      case 49: // if_stmt
      case 50: // if_opt
      case 51: // if_opt_p
      case 53: // assign_stmt
      case 55: // arg_list
      case 56: // arg_list_p
      case 57: // print_stmt
      case 58: // print_stmt_p
      case 59: // print_stmt_pp
        yylhs.value.emplace< Ast::Node * > ();
        break;

      case 23: // TK_NUMBER
        yylhs.value.emplace< int > ();
        break;

      case 22: // TK_STRING
      case 35: // TK_IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 94 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                             {root = yystack_[0].value.as < Ast::Node * > ();}
#line 937 "expr_parser.cpp"
    break;

  case 3:
#line 95 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                            {root = yystack_[0].value.as < Ast::Node * > ();}
#line 943 "expr_parser.cpp"
    break;

  case 4:
#line 98 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                {
                                                    // $$ = $1;
                                                    // reinterpret_cast<Ast::BlockStmt*>($$)->l.push_back($2);
                                                }
#line 952 "expr_parser.cpp"
    break;

  case 5:
#line 102 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                {
                                                    yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                                    reinterpret_cast<Ast::BlockStmt*>(yylhs.value.as < Ast::Node * > ())->l.push_back(yystack_[0].value.as < Ast::Node * > ());
                                                }
#line 961 "expr_parser.cpp"
    break;

  case 6:
#line 106 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                { 
                                                    Ast::NodeVector stmts;
                                                    yylhs.value.as < Ast::Node * > () = new Ast::BlockStmt(stmts);
                                                }
#line 970 "expr_parser.cpp"
    break;

  case 8:
#line 115 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                        {
                                                            std::string kind = yystack_[1].value.as < Ast::Node * > ()->getKindName();
                                                            if(kind=="AssignStmt"){
                                                                yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                                                reinterpret_cast<Ast::AssignStmt*>(yylhs.value.as < Ast::Node * > ())->id = yystack_[2].value.as < std::string > ();
                                                            }else if(kind == "FuncCall"){
                                                                yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                                                reinterpret_cast<Ast::FuncCall*>(yylhs.value.as < Ast::Node * > ())->name = yystack_[2].value.as < std::string > ();
                                                            }
                                                        }
#line 985 "expr_parser.cpp"
    break;

  case 9:
#line 125 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();}
#line 991 "expr_parser.cpp"
    break;

  case 10:
#line 126 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 997 "expr_parser.cpp"
    break;

  case 11:
#line 127 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 1003 "expr_parser.cpp"
    break;

  case 12:
#line 128 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 1009 "expr_parser.cpp"
    break;

  case 13:
#line 132 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                            {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 1015 "expr_parser.cpp"
    break;

  case 14:
#line 133 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                            {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 1021 "expr_parser.cpp"
    break;

  case 15:
#line 136 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                            {yylhs.value.as < Ast::Node * > () = new Ast::FuncCall("",reinterpret_cast<Ast::ArgList*>(yystack_[1].value.as < Ast::Node * > ()));}
#line 1027 "expr_parser.cpp"
    break;

  case 16:
#line 140 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
            {
                yylhs.value.as < Ast::Node * > () = new Ast::WhileStmt(yystack_[4].value.as < Ast::Expr* > (),reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()));
            }
#line 1035 "expr_parser.cpp"
    break;

  case 17:
#line 146 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
            {
                yylhs.value.as < Ast::Node * > () = new Ast::ForStmt(yystack_[9].value.as < std::string > (), reinterpret_cast<Ast::ArgList*>(yystack_[5].value.as < Ast::Node * > ()),reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()));
            }
#line 1043 "expr_parser.cpp"
    break;

  case 18:
#line 151 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                            { yylhs.value.as < Ast::Node * > () = new Ast::IfStmt(yystack_[4].value.as < Ast::Expr* > (),reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()), reinterpret_cast<Ast::Stmt*>(yystack_[0].value.as < Ast::Node * > ()));}
#line 1049 "expr_parser.cpp"
    break;

  case 19:
#line 154 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 1055 "expr_parser.cpp"
    break;

  case 20:
#line 155 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                {yylhs.value.as < Ast::Node * > () = nullptr;}
#line 1061 "expr_parser.cpp"
    break;

  case 21:
#line 158 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                                {yylhs.value.as < Ast::Node * > () = new Ast::IfStmt(yystack_[4].value.as < Ast::Expr* > (),reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()),reinterpret_cast<Ast::Stmt*>(yystack_[0].value.as < Ast::Node * > ()));}
#line 1067 "expr_parser.cpp"
    break;

  case 22:
#line 159 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                                {yylhs.value.as < Ast::Node * > () = new Ast::ElseStmt(reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()));}
#line 1073 "expr_parser.cpp"
    break;

  case 23:
#line 160 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                                {yylhs.value.as < Ast::Node * > () = nullptr;}
#line 1079 "expr_parser.cpp"
    break;

  case 26:
#line 167 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                      {yylhs.value.as < Ast::Node * > () = new Ast::AssignStmt("",yystack_[0].value.as < Ast::Expr* > ());}
#line 1085 "expr_parser.cpp"
    break;

  case 29:
#line 174 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                            reinterpret_cast<Ast::ArgList*>(yylhs.value.as < Ast::Node * > ())->args.push_back(yystack_[0].value.as < Ast::Expr* > ());
                                        }
#line 1094 "expr_parser.cpp"
    break;

  case 30:
#line 179 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            yylhs.value.as < Ast::Node * > () = yystack_[2].value.as < Ast::Node * > ();
                                            reinterpret_cast<Ast::ArgList*>(yylhs.value.as < Ast::Node * > ())->args.push_back(yystack_[1].value.as < Ast::Expr* > ());
                                        }
#line 1103 "expr_parser.cpp"
    break;

  case 31:
#line 183 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            Ast::NodeVector args;
                                            yylhs.value.as < Ast::Node * > () = new Ast::ArgList(args);
                                        }
#line 1112 "expr_parser.cpp"
    break;

  case 32:
#line 189 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                            {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 1118 "expr_parser.cpp"
    break;

  case 33:
#line 192 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                            {
                                                yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                                reinterpret_cast<Ast::PrintList*>(yylhs.value.as < Ast::Node * > ())->vals.push_back(new Ast::PrintExpr(yystack_[0].value.as < Ast::Expr* > ()));
                                            }
#line 1127 "expr_parser.cpp"
    break;

  case 34:
#line 196 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                            {
                                                yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                                reinterpret_cast<Ast::PrintList*>(yylhs.value.as < Ast::Node * > ())->vals.push_back(new Ast::PrintString(yystack_[0].value.as < std::string > ()));
                                            }
#line 1136 "expr_parser.cpp"
    break;

  case 35:
#line 202 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                        }
#line 1144 "expr_parser.cpp"
    break;

  case 36:
#line 205 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            Ast::NodeVector vals;
                                            yylhs.value.as < Ast::Node * > () = new Ast::PrintList(vals);
                                        }
#line 1153 "expr_parser.cpp"
    break;

  case 37:
#line 211 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                         {yylhs.value.as < Ast::Expr* > () = new Ast::AddExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1159 "expr_parser.cpp"
    break;

  case 38:
#line 212 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::SubExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1165 "expr_parser.cpp"
    break;

  case 39:
#line 213 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                          {yylhs.value.as < Ast::Expr* > () = new Ast::GTExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1171 "expr_parser.cpp"
    break;

  case 40:
#line 214 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                          {yylhs.value.as < Ast::Expr* > () = new Ast::LTExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1177 "expr_parser.cpp"
    break;

  case 41:
#line 215 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::GEExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1183 "expr_parser.cpp"
    break;

  case 42:
#line 216 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::LEExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1189 "expr_parser.cpp"
    break;

  case 43:
#line 217 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                          {yylhs.value.as < Ast::Expr* > () = new Ast::EqExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1195 "expr_parser.cpp"
    break;

  case 44:
#line 218 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::NotExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1201 "expr_parser.cpp"
    break;

  case 45:
#line 219 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
               {yylhs.value.as < Ast::Expr* > () = yystack_[0].value.as < Ast::Expr* > ();}
#line 1207 "expr_parser.cpp"
    break;

  case 46:
#line 222 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                         {yylhs.value.as < Ast::Expr* > () = new Ast::MulExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1213 "expr_parser.cpp"
    break;

  case 47:
#line 223 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::DivExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1219 "expr_parser.cpp"
    break;

  case 48:
#line 224 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
               { yylhs.value.as < Ast::Expr* > () = yystack_[0].value.as < Ast::Expr* > ();}
#line 1225 "expr_parser.cpp"
    break;

  case 49:
#line 227 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::ModExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1231 "expr_parser.cpp"
    break;

  case 50:
#line 228 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                             {yylhs.value.as < Ast::Expr* > () = new Ast::PwdExpr(yystack_[2].value.as < Ast::Expr* > (), yystack_[0].value.as < Ast::Expr* > ());}
#line 1237 "expr_parser.cpp"
    break;

  case 51:
#line 229 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                 {yylhs.value.as < Ast::Expr* > () = yystack_[0].value.as < Ast::Expr* > ();}
#line 1243 "expr_parser.cpp"
    break;

  case 52:
#line 232 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                      {yylhs.value.as < Ast::Expr* > () = new Ast::NumExpr(yystack_[0].value.as < int > ());}
#line 1249 "expr_parser.cpp"
    break;

  case 53:
#line 233 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                          { yylhs.value.as < Ast::Expr* > () = yystack_[1].value.as < Ast::Expr* > ();}
#line 1255 "expr_parser.cpp"
    break;

  case 54:
#line 234 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                     {                      
                                        std::string kind = yystack_[0].value.as < Ast::Expr* > ()->getKindName();
                                        if(kind=="FuncCall"){
                                            yylhs.value.as < Ast::Expr* > () = yystack_[0].value.as < Ast::Expr* > ();
                                            reinterpret_cast<Ast::FuncCall*>(yylhs.value.as < Ast::Expr* > ())->name = yystack_[1].value.as < std::string > ();
                                        }else if(kind == "IdExpr"){
                                            yylhs.value.as < Ast::Expr* > () = yystack_[0].value.as < Ast::Expr* > ();
                                            reinterpret_cast<Ast::IdExpr*>(yylhs.value.as < Ast::Expr* > ())->id = yystack_[1].value.as < std::string > ();
                                        }
                                    }
#line 1270 "expr_parser.cpp"
    break;

  case 55:
#line 244 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                        {yylhs.value.as < Ast::Expr* > () = new Ast::InputExpr(yystack_[1].value.as < std::string > ());}
#line 1276 "expr_parser.cpp"
    break;

  case 56:
#line 247 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                            {yylhs.value.as < Ast::Expr* > () = new Ast::FuncCall("",reinterpret_cast<Ast::ArgList*>(yystack_[1].value.as < Ast::Node * > ()));}
#line 1282 "expr_parser.cpp"
    break;

  case 58:
#line 249 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                   {yylhs.value.as < Ast::Expr* > () = new Ast::IdExpr("");}
#line 1288 "expr_parser.cpp"
    break;


#line 1292 "expr_parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

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
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
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
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
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
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
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
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
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
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
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


  const signed char Parser::yypact_ninf_ = -37;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -32,   -37,     7,   175,   175,   -37,   -20,   -37,    34,    34,
     -18,     2,   -37,   -37,   -37,   -37,   -15,    13,   -37,    19,
      -2,    34,   -37,    20,   -12,    60,     5,    17,   -37,    76,
      21,    34,   -37,   -15,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   183,   168,    -3,   -37,    34,   -37,    34,    34,    34,
      34,    34,    34,    34,    34,     8,    34,    34,    34,    34,
      11,    25,   183,    44,    34,   -37,    45,   -37,    48,    49,
     127,     5,     5,     5,     5,     5,     5,     5,     5,   -37,
      17,    17,   -37,   -37,   -37,    51,   -37,   114,    47,   -37,
     -37,   -37,     3,   120,   -37,   -37,    38,   -37,    24,   -37,
     -37,    65,   -37,    34,    56,   -37,    63,   129,    95,    54,
      55,   -37,    58,   -37,   -37,   -37,    16,   138,     3,   -37,
     -37,   -37,   -37,   -37
  };

  const signed char
  Parser::yydefact_[] =
  {
       6,     6,     0,     3,     2,     1,     0,    36,     0,     0,
       0,     0,     5,    12,    11,    10,    28,     0,     4,    32,
       0,     0,    52,     0,    58,     0,    45,    48,    51,     0,
       0,     0,    31,    28,    14,    13,    27,     9,    31,    35,
      34,    33,     0,     0,    31,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     8,     0,    53,     0,     0,
       0,    37,    38,    39,    40,    41,    42,    43,    44,     6,
      46,    47,    49,    50,     6,     0,    15,    29,     0,    55,
      56,    57,     0,     0,    31,    30,     0,    20,    23,    18,
      16,     0,     6,     0,     0,    19,     0,     0,     0,     0,
       0,     7,     0,     6,     6,     6,     0,     0,     0,    25,
      24,    22,    17,    21
  };

  const short
  Parser::yypgoto_[] =
  {
     -37,   -37,    -1,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -33,   -37,   -37,   -37,    61,   -36,   -37,   -37,   -37,   -37,
      -8,   164,   -25,   -14,   -37
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,    18,    12,    33,    34,    13,    14,    15,
      99,   105,   121,    35,    37,    63,    64,    16,    19,    20,
      25,    26,    27,    28,    46
  };

  const signed char
  Parser::yytable_[] =
  {
       4,    29,    66,    97,    44,     1,    45,     5,    69,    31,
      56,    57,    41,    42,    21,    17,   119,    30,    32,    68,
      40,    22,    36,    62,    23,    58,    59,     6,     7,    38,
       8,    80,    81,    24,     9,    10,    43,    70,    11,    39,
       6,     7,    98,     8,    82,    83,    79,     9,    10,    84,
      21,    11,   103,   104,    61,   120,    87,    22,   101,    85,
      23,    86,    88,    47,    48,    89,    90,    94,    96,    24,
      49,    50,    51,    52,    53,    54,   102,   109,    92,    47,
      48,    55,   106,    93,   110,   123,    49,    50,    51,    52,
      53,    54,   113,   114,    65,   108,   115,    60,    47,    48,
       0,   107,     0,     0,     0,    49,    50,    51,    52,    53,
      54,     0,   116,   117,   118,     0,   112,    47,    48,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      47,    48,     0,     0,    95,     0,     0,    49,    50,    51,
      52,    53,    54,     0,     6,     7,    91,     8,     0,     0,
       0,     9,    10,     6,     7,    11,     8,     0,     0,   100,
       9,    10,     6,     7,    11,     8,     0,     0,   111,     9,
      10,    47,    48,    11,     0,     0,     0,   122,    49,    50,
      51,    52,    53,    54,     0,    67,    47,    48,     0,     0,
       0,     0,     0,    49,    50,    51,    52,    53,    54,     6,
       7,     0,     8,     0,     0,     0,     9,    10,     0,     0,
      11,    71,    72,    73,    74,    75,    76,    77,    78
  };

  const signed char
  Parser::yycheck_[] =
  {
       1,     9,    38,     0,    16,    37,    18,     0,    44,     7,
       5,     6,    20,    21,    16,    35,     0,    35,    16,    22,
      22,    23,    37,    31,    26,     8,     9,    24,    25,    16,
      27,    56,    57,    35,    31,    32,    16,    45,    35,    20,
      24,    25,    39,    27,    58,    59,    38,    31,    32,    38,
      16,    35,    28,    29,    33,    39,    64,    23,    94,    34,
      26,    17,    17,     3,     4,    17,    17,    16,    21,    35,
      10,    11,    12,    13,    14,    15,    38,    21,    79,     3,
       4,    21,    17,    84,    21,   118,    10,    11,    12,    13,
      14,    15,    38,    38,    33,   103,    38,    21,     3,     4,
      -1,   102,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    -1,   113,   114,   115,    -1,    21,     3,     4,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
       3,     4,    -1,    -1,    20,    -1,    -1,    10,    11,    12,
      13,    14,    15,    -1,    24,    25,    19,    27,    -1,    -1,
      -1,    31,    32,    24,    25,    35,    27,    -1,    -1,    39,
      31,    32,    24,    25,    35,    27,    -1,    -1,    39,    31,
      32,     3,     4,    35,    -1,    -1,    -1,    39,    10,    11,
      12,    13,    14,    15,    -1,    17,     3,     4,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    24,
      25,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    47,    48,    49,    50,    51,    52,    53,    54
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    37,    41,    42,    42,     0,    24,    25,    27,    31,
      32,    35,    44,    47,    48,    49,    57,    35,    43,    58,
      59,    16,    23,    26,    35,    60,    61,    62,    63,    60,
      35,     7,    16,    45,    46,    53,    37,    54,    16,    20,
      22,    60,    60,    16,    16,    18,    64,     3,     4,    10,
      11,    12,    13,    14,    15,    21,     5,     6,     8,     9,
      21,    33,    60,    55,    56,    54,    55,    17,    22,    55,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    38,
      62,    62,    63,    63,    38,    34,    17,    60,    17,    17,
      17,    19,    42,    42,    16,    20,    21,     0,    39,    50,
      39,    55,    38,    28,    29,    51,    17,    42,    60,    21,
      21,    39,    21,    38,    38,    38,    42,    42,    42,     0,
      39,    52,    39,    50
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    40,    41,    41,    42,    42,    42,    43,    44,    44,
      44,    44,    44,    45,    45,    46,    47,    48,    49,    50,
      50,    51,    51,    51,    52,    52,    53,    54,    54,    55,
      56,    56,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    62,
      62,    62,    63,    63,    63,    63,    64,    64,    64
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     1,     3,     2,     0,     8,     3,     2,
       1,     1,     1,     1,     1,     3,     6,    11,     6,     2,
       1,     6,     5,     0,     1,     1,     2,     1,     0,     2,
       3,     0,     2,     2,     2,     2,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     1,     3,     2,     4,     3,     3,     0
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "TK_EOF", "error", "$undefined", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"=\"", "\"%\"", "\"**\"", "\">\"", "\"<\"", "\">=\"", "\"<=\"",
  "\"==\"", "\"!=\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\",\"", "\":\"",
  "TK_STRING", "TK_NUMBER", "KW_DEF", "KW_PRINT", "KW_INPUT", "KW_IF",
  "KW_ELIF", "KW_ELSE", "KW_RETURN", "KW_WHILE", "KW_FOR", "KW_IN",
  "KW_RANGE", "TK_IDENTIFIER", "TK_ERROR", "NewLine", "Indent", "Dedent",
  "$accept", "input", "complex_stmts", "func_decl", "simple_stmts",
  "simple_stmts_p", "func_stmt", "while_stmt", "for_stmt", "if_stmt",
  "if_opt", "if_opt_p", "if_opt_pp", "assign_stmt", "stmt_end_nl",
  "arg_list", "arg_list_p", "print_stmt", "print_stmt_p", "print_stmt_pp",
  "expr", "term", "prod", "factor", "factor_p", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    94,    94,    95,    98,   102,   106,   112,   115,   125,
     126,   127,   128,   132,   133,   136,   139,   145,   151,   154,
     155,   158,   159,   160,   163,   164,   167,   170,   171,   174,
     179,   183,   189,   192,   196,   202,   205,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   222,   223,   224,   227,
     228,   229,   232,   233,   234,   244,   247,   248,   249
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
    };
    const int user_token_number_max_ = 294;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 8 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
} // Expr
#line 1822 "expr_parser.cpp"

