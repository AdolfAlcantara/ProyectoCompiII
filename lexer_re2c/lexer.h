#ifndef _EXPR_LEXER_H_
#define _EXPR_LEXER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "expr_parser.h"

static const size_t SIZE = 50; //tamano del buffer en bytes

class ExprLexer {
    public:
        using semantic_type = Expr::Parser::semantic_type;
        using token = Expr::Parser::token;

        ExprLexer(std::ifstream &in):
         input(in),lineNo(1)
         {

         }
        ~ExprLexer(){};

        int getNextToken(semantic_type *yylval);
        std::string getText(){
            return text;
        }

        int getLineNo();

private:
    enum class FillStatus {Ok,Error,Eof};
    
    struct input_t
    {
        char *buf; //yymaxfill lo trae re2c
        char *lim;  //limite del buffer
        char *cur; //cursor de YYMARKER
        char *mark;
        char *tok; //apuntador de inicio del lexema
        bool eof; //sentineral de fin del buffer
        std::istream &input;

        input_t(std::istream& in);
        ~input_t() {delete [] buf;}

        FillStatus fill(size_t need);

        std::string tokenText(){
            return std::string(tok,cur -tok);
        }
    };
    
    int makeToken(int tk){
        text = input.tokenText();
        return tk;
    }

    int TkEof()
    {
        text = "<<EOF>>";
        return 0;
    }

    int TkError()
    {
        text = "Error";
        return token::TK_ERROR;
    }

    private:
    int lineNo;
    std::string text;
    input_t input;
    std::vector<int> spaces{0};
    std::vector<token::yytokentype> remaining_tokens;
};

#endif