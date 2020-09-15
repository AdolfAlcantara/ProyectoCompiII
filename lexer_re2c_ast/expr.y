%require "3.0"
%language "c++"

%define parse.error verbose
%define api.value.type variant
%define api.parser.class {Parser}
/*%define parser_class_name {Parser}*/
%define api.namespace {Expr}

%parse-param {Ast::Node*&root}
%parse-param {ExprLexer& lexer}

%code requires{
    #include "expr_ast.h"
    #include <unordered_map>

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
%type<Ast::Expr*> expr term factor prod factor_p
%type<Ast::Node *> complex_stmts simple_stmts simple_stmts_p print_stmt assign_stmt arg_list arg_list_p
%type<Ast::Node *> print_stmt_pp print_stmt_p
%type<Ast::Node *> if_stmt if_opt if_opt_p 
%type<Ast::Node *> for_stmt while_stmt 
%type<Ast::Node *> func_stmt func_decl return_stmt 
%type<Ast::Node *> assign_stmt_op array_stmt

%% 
input: NewLine complex_stmts {root = $2;}
        | complex_stmts     {root = $1;}
;

complex_stmts: complex_stmts KW_DEF func_decl   {
                                                    $$ = $1;
                                                    reinterpret_cast<Ast::BlockStmt*>($$)->l.push_back($3);
                                                }
                | complex_stmts simple_stmts    {
                                                    $$ = $1;
                                                    reinterpret_cast<Ast::BlockStmt*>($$)->l.push_back($2);
                                                }
                |/**/                           { 
                                                    Ast::NodeVector stmts;
                                                    $$ = new Ast::BlockStmt(stmts);
                                                }
;

func_decl:  TK_IDENTIFIER TK_OPENPAR arg_list TK_CLOSEPAR TK_COLON Indent complex_stmts Dedent
            {
                $$ = new Ast::FuncDecl($1, reinterpret_cast<Ast::ArgList*>($3),reinterpret_cast<Ast::BlockStmt*>($7));
            }
;

simple_stmts: TK_IDENTIFIER simple_stmts_p stmt_end_nl  {
                                                            std::string kind = $2->getKindName();
                                                            if(kind=="AssignStmt"){
                                                                $$ = $2;
                                                                reinterpret_cast<Ast::AssignStmt*>($$)->id = $1;
                                                            }else if(kind == "FuncCall"){
                                                                $$ = $2;
                                                                reinterpret_cast<Ast::FuncCall*>($$)->name = $1;
                                                            }else if(kind == "ArrayDecl"){
                                                                $$ = $2;
                                                                reinterpret_cast<Ast::ArrayDecl*>($$)->name = $1;
                                                            }else if(kind == "ArrayStmt"){
                                                                $$ = $2;
                                                                reinterpret_cast<Ast::ArrayStmt*>($$)->name = $1;
                                                            }
                                                        }
            | print_stmt stmt_end_nl    {$$ = $1;}
            | if_stmt                   {$$ = $1;}
            | for_stmt                  {$$ = $1;}
            | while_stmt                {$$ = $1;}
            | return_stmt stmt_end_nl   {$$ = $1;}

;

simple_stmts_p: assign_stmt {$$ = $1;}
                | func_stmt {$$ = $1;}
                | array_stmt {$$ = $1;}
;

assign_stmt: "=" assign_stmt_op {$$ = $2;}
;

assign_stmt_op: expr {$$ = new Ast::AssignStmt("",$1);}
                | "[" arg_list "]" {$$ = new Ast::ArrayDecl("",reinterpret_cast<Ast::ArgList*>($2));}
;

array_stmt: "[" expr "]" "=" expr {$$ = new Ast::ArrayStmt("",$2,$5);}
;


func_stmt: "(" arg_list ")" {$$ = new Ast::FuncCall("",reinterpret_cast<Ast::ArgList*>($2));}
;

while_stmt: KW_WHILE expr TK_COLON Indent complex_stmts Dedent
            {
                $$ = new Ast::WhileStmt($2,reinterpret_cast<Ast::Stmt*>($5));
            }
;

for_stmt: KW_FOR TK_IDENTIFIER KW_IN KW_RANGE TK_OPENPAR arg_list TK_CLOSEPAR TK_COLON Indent complex_stmts Dedent
            {
                $$ = new Ast::ForStmt($2, reinterpret_cast<Ast::ArgList*>($6),reinterpret_cast<Ast::Stmt*>($10));
            }
;

if_stmt:    KW_IF expr TK_COLON Indent complex_stmts if_opt { $$ = new Ast::IfStmt($2,reinterpret_cast<Ast::Stmt*>($5), reinterpret_cast<Ast::Stmt*>($6));}
;

if_opt:      Dedent if_opt_p    {$$ = $2;}
            | TK_EOF            {$$ = nullptr;}
;

if_opt_p:   KW_ELIF expr TK_COLON Indent complex_stmts if_opt   {$$ = new Ast::IfStmt($2,reinterpret_cast<Ast::BlockStmt*>($5),reinterpret_cast<Ast::BlockStmt*>($6));}
            | KW_ELSE TK_COLON Indent complex_stmts if_opt_pp   {$$ = new Ast::ElseStmt(reinterpret_cast<Ast::BlockStmt*>($4));}
            | /**/                                              {$$ = nullptr;}
;

if_opt_pp:  Dedent      
            | TK_EOF    
;


stmt_end_nl: NewLine
            | /**/
;

arg_list:   arg_list_p expr             {
                                            $$ = $1;
                                            reinterpret_cast<Ast::ArgList*>($$)->args.push_back($2);
                                        }
;
arg_list_p: arg_list_p  expr  TK_COMMA  {
                                            $$ = $1;
                                            reinterpret_cast<Ast::ArgList*>($$)->args.push_back($2);
                                        }
            | /**/                      {
                                            Ast::NodeVector args;
                                            $$ = new Ast::ArgList(args);
                                        }
;

return_stmt: KW_RETURN expr             {$$ = new Ast::ReturnStmt($2);}
;

print_stmt: KW_PRINT print_stmt_p           {$$ = $2;}
;

print_stmt_p: print_stmt_pp expr            {
                                                $$ = $1;
                                                reinterpret_cast<Ast::PrintList*>($$)->vals.push_back(new Ast::PrintExpr($2));
                                            }
                | print_stmt_pp TK_STRING   {
                                                $$ = $1;
                                                reinterpret_cast<Ast::PrintList*>($$)->vals.push_back(new Ast::PrintString($2));
                                            }
;

print_stmt_pp: print_stmt_p TK_COMMA    {
                                            $$ = $1;
                                        }
                | /**/                  {
                                            Ast::NodeVector vals;
                                            $$ = new Ast::PrintList(vals);
                                        }
;

expr:   expr OP_ADD term {$$ = new Ast::AddExpr($1,$3);}
        | expr OP_SUB term {$$ = new Ast::SubExpr($1,$3);}
        | expr OP_GT term {$$ = new Ast::GTExpr($1,$3);}
        | expr OP_LT term {$$ = new Ast::LTExpr($1,$3);}
        | expr OP_GET term {$$ = new Ast::GEExpr($1,$3);}
        | expr OP_LET term {$$ = new Ast::LEExpr($1,$3);}
        | expr OP_EQ term {$$ = new Ast::EqExpr($1,$3);}
        | expr OP_NEQ term {$$ = new Ast::NotExpr($1,$3);}
        | term {$$ = $1;}
;   

term:   term OP_MUL prod {$$ = new Ast::MulExpr($1,$3);}
        | term OP_DIV prod {$$ = new Ast::DivExpr($1,$3);}
        | prod { $$ = $1;}
;

prod:   prod OP_MOD factor {$$ = new Ast::ModExpr($1,$3);}
        | prod OP_PWD factor {$$ = new Ast::PwdExpr($1, $3);}
        | factor {$$ = $1;}
;

factor:     TK_NUMBER {$$ = new Ast::NumExpr($1);}
            | TK_OPENPAR expr TK_CLOSEPAR { $$ = $2;}
            | TK_IDENTIFIER factor_p {                      
                                        std::string kind = $2->getKindName();
                                        if(kind=="FuncCall"){
                                            $$ = $2;
                                            reinterpret_cast<Ast::FuncCall*>($$)->name = $1;
                                        }else if(kind == "IdExpr"){
                                            $$ = $2;
                                            reinterpret_cast<Ast::IdExpr*>($$)->id = $1;
                                        }else if(kind == "ArrayExpr"){
                                            $$ = $2;
                                            reinterpret_cast<Ast::ArrayExpr*>($$)->name = $1;
                                        }
                                    }
            | KW_INPUT TK_OPENPAR TK_STRING TK_CLOSEPAR {$$ = new Ast::InputExpr($3);}
;

factor_p:   TK_OPENPAR arg_list TK_CLOSEPAR {$$ = new Ast::FuncCall("",reinterpret_cast<Ast::ArgList*>($2));}
            | "[" expr "]" {$$ = new Ast::ArrayExpr("",$2);}
            | /**/ {$$ = new Ast::IdExpr("");}
;