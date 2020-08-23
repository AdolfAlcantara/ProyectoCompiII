%require "3.0"
%language "c++"

%define parse.error verbose
%define api.value.type variant
%define api.parser.class {Parser}
/*%define parser_class_name {Parser}*/
%define api.namespace {Expr}

%parse-param {std::unordered_map<std::string, int>& vars}
%parse-param {ExprLexer& lexer}

%code requires{
    #include <unordered_map>
    #include <math.h>

    class ExprLexer;
}

//esto va para el cpp
%{
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
%}

%token OP_ADD "+"
%token OP_SUB "-"
%token OP_MUL "*"
%token OP_DIV "/"
%token OP_ASSIGN "="
%token OP_MOD "%"
%token OP_PWD "**"
%token OP_GT ">"
%token OP_LT "<"
%token OP_GET ">="
%token OP_LET "<="
%token OP_EQ "=="
%token OP_NEQ "!="
%token TK_OPENPAR "("
%token TK_CLOSEPAR ")"
%token TK_COMMA ","
%token<std::string> TK_STRING
%token<int> TK_NUMBER
%token KW_DEF
%token KW_PRINT
%token KW_INPUT
%token<std::string> TK_IDENTIFIER
%token TK_ERROR
%token TK_EOF

%token NewLine
%token Indent
%token Dedent
%type<int> expr term prod factor


%% 

input: NewLine complex_stmts
        | complex_stmts
;

complex_stmts: complex_stmts KW_DEF func_decl
                | complex_stmts simple_stmts
                | /**/
;

simple_stmts: assign_stmt stmt_end_nl
                | print_stmt stmt_end_nl
                
;

stmt_end_nl: NewLine
            | /**/
;

assign_stmt: TK_IDENTIFIER "=" expr {vars.insert({$1,$3});}
;

print_stmt: KW_PRINT print_stmt_p
;

print_stmt_p: print_stmt_pp expr {std::cout<<$2<<"\n";}
                | print_stmt_pp TK_STRING {std::cout<<$2<<"\n";}
;

print_stmt_pp: print_stmt_p TK_COMMA
                | /**/

func_decl:
;

expr:   expr OP_ADD term {$$ = $1 + $3;}
        | expr OP_SUB term {$$ = $1 - $3;}
        | expr OP_GT term {$$ = $1 > $3;}
        | expr OP_LT term {$$ = $1 < $3;}
        | expr OP_GET term {$$ = $1 >= $3;}
        | expr OP_LET term {$$ = $1 <= $3;}
        | expr OP_EQ term {$$ = $1 == $3;}
        | expr OP_NEQ term {$$ = $1 != $3;}
        | term {$$ = $1;}
;   

term:   term OP_MUL prod {$$ = $1 * $3;}
        | term OP_DIV prod {$$ = $1 / $3;}
        | prod { $$ = $1;}
;

prod:   prod OP_MOD factor {$$ = $1 % $3;}
        | prod OP_PWD factor {$$ = pow($1,$3);}
        | factor { $$ = $1;}
;

factor:     TK_NUMBER {$$ = $1;}
            | TK_OPENPAR expr TK_CLOSEPAR { $$ = $2;}
            | TK_IDENTIFIER {$$ = vars[$1];}
            | KW_INPUT TK_OPENPAR TK_STRING TK_CLOSEPAR {std::cout<<$3; std::cin>>$$;}
;