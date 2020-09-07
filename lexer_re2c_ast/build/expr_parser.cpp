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
      case 58: // expr
      case 59: // term
      case 60: // prod
      case 61: // factor
        value.move< Ast::Expr* > (std::move (that.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // while_stmt
      case 46: // for_stmt
      case 47: // if_stmt
      case 48: // if_opt
      case 49: // if_opt_p
      case 51: // assign_stmt
      case 53: // arg_list
      case 54: // arg_list_p
      case 55: // print_stmt
      case 56: // print_stmt_p
      case 57: // print_stmt_pp
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
      case 58: // expr
      case 59: // term
      case 60: // prod
      case 61: // factor
        value.copy< Ast::Expr* > (YY_MOVE (that.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // while_stmt
      case 46: // for_stmt
      case 47: // if_stmt
      case 48: // if_opt
      case 49: // if_opt_p
      case 51: // assign_stmt
      case 53: // arg_list
      case 54: // arg_list_p
      case 55: // print_stmt
      case 56: // print_stmt_p
      case 57: // print_stmt_pp
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
      case 58: // expr
      case 59: // term
      case 60: // prod
      case 61: // factor
        value.move< Ast::Expr* > (YY_MOVE (s.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // while_stmt
      case 46: // for_stmt
      case 47: // if_stmt
      case 48: // if_opt
      case 49: // if_opt_p
      case 51: // assign_stmt
      case 53: // arg_list
      case 54: // arg_list_p
      case 55: // print_stmt
      case 56: // print_stmt_p
      case 57: // print_stmt_pp
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
      case 58: // expr
      case 59: // term
      case 60: // prod
      case 61: // factor
        value.YY_MOVE_OR_COPY< Ast::Expr* > (YY_MOVE (that.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // while_stmt
      case 46: // for_stmt
      case 47: // if_stmt
      case 48: // if_opt
      case 49: // if_opt_p
      case 51: // assign_stmt
      case 53: // arg_list
      case 54: // arg_list_p
      case 55: // print_stmt
      case 56: // print_stmt_p
      case 57: // print_stmt_pp
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
      case 58: // expr
      case 59: // term
      case 60: // prod
      case 61: // factor
        value.move< Ast::Expr* > (YY_MOVE (that.value));
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // while_stmt
      case 46: // for_stmt
      case 47: // if_stmt
      case 48: // if_opt
      case 49: // if_opt_p
      case 51: // assign_stmt
      case 53: // arg_list
      case 54: // arg_list_p
      case 55: // print_stmt
      case 56: // print_stmt_p
      case 57: // print_stmt_pp
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
      case 58: // expr
      case 59: // term
      case 60: // prod
      case 61: // factor
        value.copy< Ast::Expr* > (that.value);
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // while_stmt
      case 46: // for_stmt
      case 47: // if_stmt
      case 48: // if_opt
      case 49: // if_opt_p
      case 51: // assign_stmt
      case 53: // arg_list
      case 54: // arg_list_p
      case 55: // print_stmt
      case 56: // print_stmt_p
      case 57: // print_stmt_pp
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
      case 58: // expr
      case 59: // term
      case 60: // prod
      case 61: // factor
        value.move< Ast::Expr* > (that.value);
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // while_stmt
      case 46: // for_stmt
      case 47: // if_stmt
      case 48: // if_opt
      case 49: // if_opt_p
      case 51: // assign_stmt
      case 53: // arg_list
      case 54: // arg_list_p
      case 55: // print_stmt
      case 56: // print_stmt_p
      case 57: // print_stmt_pp
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
      case 58: // expr
      case 59: // term
      case 60: // prod
      case 61: // factor
        yylhs.value.emplace< Ast::Expr* > ();
        break;

      case 42: // complex_stmts
      case 43: // func_decl
      case 44: // simple_stmts
      case 45: // while_stmt
      case 46: // for_stmt
      case 47: // if_stmt
      case 48: // if_opt
      case 49: // if_opt_p
      case 51: // assign_stmt
      case 53: // arg_list
      case 54: // arg_list_p
      case 55: // print_stmt
      case 56: // print_stmt_p
      case 57: // print_stmt_pp
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
#line 93 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                             {root = yystack_[0].value.as < Ast::Node * > ();}
#line 913 "expr_parser.cpp"
    break;

  case 3:
#line 94 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                            {root = yystack_[0].value.as < Ast::Node * > ();}
#line 919 "expr_parser.cpp"
    break;

  case 4:
#line 97 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                {
                                                    // $$ = $1;
                                                    // reinterpret_cast<Ast::BlockStmt*>($$)->l.push_back($2);
                                                }
#line 928 "expr_parser.cpp"
    break;

  case 5:
#line 101 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                {
                                                    yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                                    reinterpret_cast<Ast::BlockStmt*>(yylhs.value.as < Ast::Node * > ())->l.push_back(yystack_[0].value.as < Ast::Node * > ());
                                                }
#line 937 "expr_parser.cpp"
    break;

  case 6:
#line 105 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                { 
                                                    Ast::NodeVector stmts;
                                                    yylhs.value.as < Ast::Node * > () = new Ast::BlockStmt(stmts);
                                                }
#line 946 "expr_parser.cpp"
    break;

  case 8:
#line 114 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();}
#line 952 "expr_parser.cpp"
    break;

  case 9:
#line 115 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();}
#line 958 "expr_parser.cpp"
    break;

  case 10:
#line 116 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 964 "expr_parser.cpp"
    break;

  case 11:
#line 117 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 970 "expr_parser.cpp"
    break;

  case 12:
#line 118 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 976 "expr_parser.cpp"
    break;

  case 13:
#line 123 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
            {
                yylhs.value.as < Ast::Node * > () = new Ast::WhileStmt(yystack_[4].value.as < Ast::Expr* > (),reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()));
            }
#line 984 "expr_parser.cpp"
    break;

  case 14:
#line 129 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
            {
                yylhs.value.as < Ast::Node * > () = new Ast::ForStmt(yystack_[9].value.as < std::string > (), reinterpret_cast<Ast::ArgList*>(yystack_[5].value.as < Ast::Node * > ()),reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()));
            }
#line 992 "expr_parser.cpp"
    break;

  case 15:
#line 134 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                            { yylhs.value.as < Ast::Node * > () = new Ast::IfStmt(yystack_[4].value.as < Ast::Expr* > (),reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()), reinterpret_cast<Ast::Stmt*>(yystack_[0].value.as < Ast::Node * > ()));}
#line 998 "expr_parser.cpp"
    break;

  case 16:
#line 137 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 1004 "expr_parser.cpp"
    break;

  case 17:
#line 138 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                {yylhs.value.as < Ast::Node * > () = nullptr;}
#line 1010 "expr_parser.cpp"
    break;

  case 18:
#line 141 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                                {yylhs.value.as < Ast::Node * > () = new Ast::IfStmt(yystack_[4].value.as < Ast::Expr* > (),reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()),reinterpret_cast<Ast::Stmt*>(yystack_[0].value.as < Ast::Node * > ()));}
#line 1016 "expr_parser.cpp"
    break;

  case 19:
#line 142 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                                {yylhs.value.as < Ast::Node * > () = new Ast::ElseStmt(reinterpret_cast<Ast::Stmt*>(yystack_[1].value.as < Ast::Node * > ()));}
#line 1022 "expr_parser.cpp"
    break;

  case 20:
#line 143 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                                {yylhs.value.as < Ast::Node * > () = nullptr;}
#line 1028 "expr_parser.cpp"
    break;

  case 23:
#line 150 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                    {yylhs.value.as < Ast::Node * > () = new Ast::AssignStmt(yystack_[2].value.as < std::string > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1034 "expr_parser.cpp"
    break;

  case 26:
#line 157 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                            reinterpret_cast<Ast::ArgList*>(yylhs.value.as < Ast::Node * > ())->args.push_back(yystack_[0].value.as < Ast::Expr* > ());
                                        }
#line 1043 "expr_parser.cpp"
    break;

  case 27:
#line 162 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            yylhs.value.as < Ast::Node * > () = yystack_[2].value.as < Ast::Node * > ();
                                            reinterpret_cast<Ast::ArgList*>(yylhs.value.as < Ast::Node * > ())->args.push_back(yystack_[1].value.as < Ast::Expr* > ());
                                        }
#line 1052 "expr_parser.cpp"
    break;

  case 28:
#line 166 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            Ast::NodeVector args;
                                            yylhs.value.as < Ast::Node * > () = new Ast::ArgList(args);
                                        }
#line 1061 "expr_parser.cpp"
    break;

  case 29:
#line 172 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                            {yylhs.value.as < Ast::Node * > () = yystack_[0].value.as < Ast::Node * > ();}
#line 1067 "expr_parser.cpp"
    break;

  case 30:
#line 175 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                            {
                                                yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                                reinterpret_cast<Ast::PrintList*>(yylhs.value.as < Ast::Node * > ())->vals.push_back(new Ast::PrintExpr(yystack_[0].value.as < Ast::Expr* > ()));
                                            }
#line 1076 "expr_parser.cpp"
    break;

  case 31:
#line 179 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                            {
                                                yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                                reinterpret_cast<Ast::PrintList*>(yylhs.value.as < Ast::Node * > ())->vals.push_back(new Ast::PrintString(yystack_[0].value.as < std::string > ()));
                                            }
#line 1085 "expr_parser.cpp"
    break;

  case 32:
#line 185 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            yylhs.value.as < Ast::Node * > () = yystack_[1].value.as < Ast::Node * > ();
                                        }
#line 1093 "expr_parser.cpp"
    break;

  case 33:
#line 188 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                        {
                                            Ast::NodeVector vals;
                                            yylhs.value.as < Ast::Node * > () = new Ast::PrintList(vals);
                                        }
#line 1102 "expr_parser.cpp"
    break;

  case 34:
#line 194 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                         {yylhs.value.as < Ast::Expr* > () = new Ast::AddExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1108 "expr_parser.cpp"
    break;

  case 35:
#line 195 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::SubExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1114 "expr_parser.cpp"
    break;

  case 36:
#line 196 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                          {yylhs.value.as < Ast::Expr* > () = new Ast::GTExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1120 "expr_parser.cpp"
    break;

  case 37:
#line 197 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                          {yylhs.value.as < Ast::Expr* > () = new Ast::LTExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1126 "expr_parser.cpp"
    break;

  case 38:
#line 198 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::GEExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1132 "expr_parser.cpp"
    break;

  case 39:
#line 199 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::LEExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1138 "expr_parser.cpp"
    break;

  case 40:
#line 200 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                          {yylhs.value.as < Ast::Expr* > () = new Ast::EqExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1144 "expr_parser.cpp"
    break;

  case 41:
#line 201 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::NotExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1150 "expr_parser.cpp"
    break;

  case 42:
#line 202 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
               {yylhs.value.as < Ast::Expr* > () = yystack_[0].value.as < Ast::Expr* > ();}
#line 1156 "expr_parser.cpp"
    break;

  case 43:
#line 205 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                         {yylhs.value.as < Ast::Expr* > () = new Ast::MulExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1162 "expr_parser.cpp"
    break;

  case 44:
#line 206 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::DivExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1168 "expr_parser.cpp"
    break;

  case 45:
#line 207 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
               { yylhs.value.as < Ast::Expr* > () = yystack_[0].value.as < Ast::Expr* > ();}
#line 1174 "expr_parser.cpp"
    break;

  case 46:
#line 210 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                           {yylhs.value.as < Ast::Expr* > () = new Ast::ModExpr(yystack_[2].value.as < Ast::Expr* > (),yystack_[0].value.as < Ast::Expr* > ());}
#line 1180 "expr_parser.cpp"
    break;

  case 47:
#line 211 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                             {yylhs.value.as < Ast::Expr* > () = new Ast::PwdExpr(yystack_[2].value.as < Ast::Expr* > (), yystack_[0].value.as < Ast::Expr* > ());}
#line 1186 "expr_parser.cpp"
    break;

  case 48:
#line 212 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                 {yylhs.value.as < Ast::Expr* > () = yystack_[0].value.as < Ast::Expr* > ();}
#line 1192 "expr_parser.cpp"
    break;

  case 49:
#line 215 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                      {yylhs.value.as < Ast::Expr* > () = new Ast::NumExpr(yystack_[0].value.as < int > ());}
#line 1198 "expr_parser.cpp"
    break;

  case 50:
#line 216 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                          { yylhs.value.as < Ast::Expr* > () = yystack_[1].value.as < Ast::Expr* > ();}
#line 1204 "expr_parser.cpp"
    break;

  case 51:
#line 217 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                            {yylhs.value.as < Ast::Expr* > () = new Ast::IdExpr(yystack_[0].value.as < std::string > ());}
#line 1210 "expr_parser.cpp"
    break;

  case 52:
#line 218 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr.y"
                                                        {yylhs.value.as < Ast::Expr* > () = new Ast::InputExpr(yystack_[1].value.as < std::string > ());}
#line 1216 "expr_parser.cpp"
    break;


#line 1220 "expr_parser.cpp"

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


  const signed char Parser::yypact_ninf_ = -35;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -27,   -35,    12,    41,    41,   -35,   -13,   -35,    29,    29,
     -12,    18,   -35,   -35,   -35,   -35,    -6,    -6,    16,   -35,
      10,    -7,    29,   -35,    23,   -35,    67,    -2,    -3,   -35,
      82,     7,    29,   -35,   -35,   -35,   -35,   -35,   -35,   163,
     148,    22,    29,    29,    29,    29,    29,    29,    29,    29,
       9,    29,    29,    29,    29,    15,    20,   163,    31,    29,
     -35,    32,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
     -35,    -3,    -3,   -35,   -35,   -35,    51,    54,   108,   -35,
       2,   100,   -35,    46,   -35,   -35,   -21,   -35,   -35,    70,
     -35,    29,    69,   -35,    83,   109,    95,    53,    75,   -35,
      76,   -35,   -35,   -35,    11,   118,     2,   -35,   -35,   -35,
     -35,   -35
  };

  const signed char
  Parser::yydefact_[] =
  {
       6,     6,     0,     3,     2,     1,     0,    33,     0,     0,
       0,     0,     5,    12,    11,    10,    25,    25,     0,     4,
      29,     0,     0,    49,     0,    51,     0,    42,    45,    48,
       0,     0,     0,    24,     8,     9,    28,    32,    31,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
      50,     0,    34,    35,    36,    37,    38,    39,    40,    41,
       6,    43,    44,    46,    47,     6,     0,     0,    26,    52,
       0,     0,    28,     0,    27,    17,    20,    15,    13,     0,
       6,     0,     0,    16,     0,     0,     0,     0,     0,     7,
       0,     6,     6,     6,     0,     0,     0,    22,    21,    19,
      14,    18
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -35,   -35,    -1,   -35,   -35,   -35,   -35,   -35,    24,   -35,
     -35,   -35,    98,    35,   -35,   -35,   -35,   -35,    -8,    14,
     -34,   -33
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,    19,    12,    13,    14,    15,    87,    93,
     109,    16,    34,    58,    59,    17,    20,    21,    26,    27,
      28,    29
  };

  const signed char
  Parser::yytable_[] =
  {
       4,    30,    85,    51,    52,    53,    54,    91,    92,    22,
       1,   107,     5,    39,    40,    38,    23,    71,    72,    24,
      73,    74,    18,    31,    57,    32,     6,     7,    25,     8,
      37,    33,    36,     9,    10,     6,     7,    11,     8,    41,
      56,    86,     9,    10,    61,    22,    11,    70,    77,    79,
     108,    78,    23,    75,    76,    24,    62,    63,    64,    65,
      66,    67,    68,    69,    25,     6,     7,    82,     8,    80,
      42,    43,     9,    10,    81,    83,    11,    44,    45,    46,
      47,    48,    49,    96,    90,    42,    43,    94,    50,    95,
      97,   101,    44,    45,    46,    47,    48,    49,    42,    43,
     104,   105,   106,    55,    98,    44,    45,    46,    47,    48,
      49,    42,    43,   102,   103,    35,   100,    89,    44,    45,
      46,    47,    48,    49,     6,     7,     0,     8,    84,     0,
     111,     9,    10,     6,     7,    11,     8,     0,     0,    88,
       9,    10,     6,     7,    11,     8,     0,     0,    99,     9,
      10,    42,    43,    11,     0,     0,     0,   110,    44,    45,
      46,    47,    48,    49,     0,    60,    42,    43,     0,     0,
       0,     0,     0,    44,    45,    46,    47,    48,    49
  };

  const signed char
  Parser::yycheck_[] =
  {
       1,     9,     0,     5,     6,     8,     9,    28,    29,    16,
      37,     0,     0,    21,    22,    22,    23,    51,    52,    26,
      53,    54,    35,    35,    32,     7,    24,    25,    35,    27,
      20,    37,    16,    31,    32,    24,    25,    35,    27,    16,
      33,    39,    31,    32,    22,    16,    35,    38,    17,    17,
      39,    59,    23,    38,    34,    26,    42,    43,    44,    45,
      46,    47,    48,    49,    35,    24,    25,    16,    27,    70,
       3,     4,    31,    32,    75,    21,    35,    10,    11,    12,
      13,    14,    15,    91,    38,     3,     4,    17,    21,    90,
      21,    38,    10,    11,    12,    13,    14,    15,     3,     4,
     101,   102,   103,    21,    21,    10,    11,    12,    13,    14,
      15,     3,     4,    38,    38,    17,    21,    82,    10,    11,
      12,    13,    14,    15,    24,    25,    -1,    27,    20,    -1,
     106,    31,    32,    24,    25,    35,    27,    -1,    -1,    39,
      31,    32,    24,    25,    35,    27,    -1,    -1,    39,    31,
      32,     3,     4,    35,    -1,    -1,    -1,    39,    10,    11,
      12,    13,    14,    15,    -1,    17,     3,     4,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    37,    41,    42,    42,     0,    24,    25,    27,    31,
      32,    35,    44,    45,    46,    47,    51,    55,    35,    43,
      56,    57,    16,    23,    26,    35,    58,    59,    60,    61,
      58,    35,     7,    37,    52,    52,    16,    20,    22,    58,
      58,    16,     3,     4,    10,    11,    12,    13,    14,    15,
      21,     5,     6,     8,     9,    21,    33,    58,    53,    54,
      17,    22,    59,    59,    59,    59,    59,    59,    59,    59,
      38,    60,    60,    61,    61,    38,    34,    17,    58,    17,
      42,    42,    16,    21,    20,     0,    39,    48,    39,    53,
      38,    28,    29,    49,    17,    42,    58,    21,    21,    39,
      21,    38,    38,    38,    42,    42,    42,     0,    39,    50,
      39,    48
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    40,    41,    41,    42,    42,    42,    43,    44,    44,
      44,    44,    44,    45,    46,    47,    48,    48,    49,    49,
      49,    50,    50,    51,    52,    52,    53,    54,    54,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    59,    60,    60,    60,    61,
      61,    61,    61
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     1,     3,     2,     0,     8,     2,     2,
       1,     1,     1,     6,    11,     6,     2,     1,     6,     5,
       0,     1,     1,     3,     1,     0,     2,     3,     0,     2,
       2,     2,     2,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     1,
       3,     1,     4
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
  "while_stmt", "for_stmt", "if_stmt", "if_opt", "if_opt_p", "if_opt_pp",
  "assign_stmt", "stmt_end_nl", "arg_list", "arg_list_p", "print_stmt",
  "print_stmt_p", "print_stmt_pp", "expr", "term", "prod", "factor", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    93,    93,    94,    97,   101,   105,   111,   114,   115,
     116,   117,   118,   122,   128,   134,   137,   138,   141,   142,
     143,   146,   147,   150,   153,   154,   157,   162,   166,   172,
     175,   179,   185,   188,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   205,   206,   207,   210,   211,   212,   215,
     216,   217,   218
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
#line 1738 "expr_parser.cpp"

