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
    #include "expr_ast.h"
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
%token TK_OPENBCKT "["
%token TK_CLOSEBCKT "]"
%token TK_COMMA ","
%token TK_COLON ":"
%token<std::string> TK_STRING
%token<int> TK_NUMBER
%token KW_DEF
%token KW_PRINT
%token KW_INPUT
%token KW_IF
%token KW_ELIF
%token KW_ELSE
%token KW_RETURN
%token KW_WHILE
%token KW_FOR
%token KW_IN
%token KW_RANGE
%token<std::string> TK_IDENTIFIER
%token TK_ERROR
%token TK_EOF 0

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
                |/**/
;

simple_stmts: TK_IDENTIFIER simple_stmts_p stmt_end_nl
            | print_stmt stmt_end_nl
            | return_stmt stmt_end_nl
            | if_stmt
            | while_stmt 
            | for_stmt
;

simple_stmts_p: assign_stmt 
                | array_stmt
                | func_stmt
;

func_stmt: "(" arg_list ")"
;

array_stmt: "[" expr "]" "=" expr
;

assign_stmt: "=" assign_stmt_op
;

assign_stmt_op: expr
                | "[" arg_list "]"
;

stmt_end_nl: NewLine
            | /**/
;

for_stmt: KW_FOR TK_IDENTIFIER KW_IN KW_RANGE TK_OPENPAR arg_list TK_CLOSEPAR TK_COLON Indent complex_stmts Dedent
;

while_stmt: KW_WHILE expr TK_COLON Indent complex_stmts Dedent
;

return_stmt: KW_RETURN expr
;

if_stmt:    KW_IF expr TK_COLON Indent complex_stmts if_opt
;

if_opt:      Dedent if_opt_p
            | TK_EOF    
;

if_opt_p:   KW_ELIF expr TK_COLON Indent complex_stmts if_opt
            | KW_ELSE TK_COLON Indent complex_stmts if_opt_pp
            | /**/
;

if_opt_pp:  Dedent      
            | TK_EOF    
;

print_stmt: KW_PRINT print_stmt_p
;

print_stmt_p: print_stmt_pp expr 
                | print_stmt_pp TK_STRING 
;

print_stmt_pp: print_stmt_p TK_COMMA
                | /**/
;

func_decl:  TK_IDENTIFIER TK_OPENPAR arg_list TK_CLOSEPAR TK_COLON Indent complex_stmts Dedent
;

arg_list:   arg arg_list_p 
;
arg_list_p: TK_COMMA arg arg_list_p 
            | /**/
;

arg:    expr
;

expr:   expr OP_ADD term {/*$$ = $1 + $3;*/}
        | expr OP_SUB term {/*$$ = $1 - $3;*/}
        | expr OP_GT term {/*$$ = $1 > $3;*/}
        | expr OP_LT term {/*$$ = $1 < $3;*/}
        | expr OP_GET term {/*$$ = $1 >= $3;*/}
        | expr OP_LET term {/*$$ = $1 <= $3;*/}
        | expr OP_EQ term {/*$$ = $1 == $3;*/}
        | expr OP_NEQ term {/*$$ = $1 != $3;*/}
        | term {/*$$ = $1;*/}
;   

term:   term OP_MUL prod {/*$$ = $1 * $3;*/}
        | term OP_DIV prod {/*$$ = $1 / $3;*/}
        | prod {/* $$ = $1;*/}
;

prod:   prod OP_MOD factor {/*/*$$ = $1 % $3;*/}
        | prod OP_PWD factor {/*$$ = pow($1,$3);*/}
        | factor {/* $$ = $1;*/}
;

factor:     TK_NUMBER {/*$$ = $1;*/}
            | TK_OPENPAR expr TK_CLOSEPAR {/* $$ = $2;*/}
            | TK_IDENTIFIER factor_p 
            | KW_INPUT TK_OPENPAR TK_STRING TK_CLOSEPAR {/*std::cout<<$3; std::cin>>$$;*/}
;

factor_p:   TK_OPENPAR arg_list TK_CLOSEPAR {/*std::cout<<"funcion\n";*/}
            | "[" expr "]" 
            | /**/ {/*std::cout<<"identificador\n";*/}
;