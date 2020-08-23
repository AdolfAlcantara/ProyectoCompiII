#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <istream>
#include "lexer.h"

/*!max:re2c*/

int ExprLexer::getNextToken(semantic_type *yylval)
{

    #define YYFILL(n) do {\
        FillStatus st = input.fill(n);\
        switch(st){\
            case FillStatus::Eof : return TkEof();\
            case FillStatus::Error : return TkError();\
            default:\
                break;\
        }\
    }while(0)

    
    if(remaining_tokens.size() > 0){
        remaining_tokens.pop_back();
        return makeToken(token::Dedent);
    }

    while(true){
    
    loop:
        input.tok = input.cur;

        /*!re2c
            re2c:define:YYCTYPE = char;
            re2c:define:YYCURSOR = input.cur;
            re2c:define:YYLIMIT = input.lim;
            re2c:define:YYMARKER = input.mark;
            re2c:define:YYFILL:naked  = 0;

            end = "\x00";
            wsp = [ \t]+;
            num = [0-9]+;
            ident = [_a-zA-Z0-9][_a-zA-Z0-9]*;
            string = ["][^(\n|")]*["];
            comment = "#"[^\n]*"\n";
            


            *       {return TkError();}
            [\n]   {   
                        //continue;
                        std::cout<<"global newline: "<<input.tokenText();
                        std::cout<<"global newline size: "<<input.tokenText().length() <<"\n";
                        //makeToken(token::TK_EOF);
                        goto indent_block;
                    }
            end     {return input.eof? TkEof(): TkError();}
            wsp     {continue;}
            
            num     {
                yylval->emplace<int>(std::strtol(std::string(input.tok, input.cur).c_str(), nullptr,10));
                return makeToken(token::TK_NUMBER);
            }
            ident   {
                yylval->emplace<std::string>(std::string(input.tok, input.cur).c_str(),std::string(input.tok, input.cur).size());
                if(input.tokenText().compare("print")==0){
                    std::cout<<"secret word: "<<input.tokenText()<<"\n";
                    std::cout<<"print token\n";
                    std::cout<<"-----"<<"\n"; 
                    return makeToken(token::KW_PRINT);
                }else if(input.tokenText().compare("input")==0){
                    std::cout<<"secret word: "<<input.tokenText()<<"\n";
                    std::cout<<"input token\n";
                    std::cout<<"-----"<<"\n"; 
                    return makeToken(token::KW_INPUT);
                }else{
                    std::cout<<"secret word: "<<input.tokenText()<<"\n";
                    std::cout<<"ident token\n";
                    std::cout<<"-----"<<"\n"; 
                    return makeToken(token::TK_IDENTIFIER);
                }
            }


            string {
                yylval->emplace<std::string>(std::string(input.tok, input.cur).c_str(),std::string(input.tok, input.cur).size());
                std::cout<<input.tokenText()<<"\n"; 
                std::cout<<"string token\n";
                std::cout<<"-----"<<"\n"; 
                return makeToken(token::TK_STRING);
                }
            comment {
                std::cout<<input.tokenText()<<"\n";
                std::cout<<"-----"<<"\n"; 
                continue;
            }
            
            "+"  { return makeToken(token::OP_ADD);}
            "-"  { return makeToken(token::OP_SUB);}
            "**"  { 
                    std::cout<<"pwd token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_PWD);
                    }
            "*"  { 
                    std::cout<<"mult token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_MUL);
                }
            "/"  { return makeToken(token::OP_DIV);}
            "%"  { 
                    std::cout<<"mod token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_MOD);}
            "="  {
                    std::cout<<"assign token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_ASSIGN);}
            "("  {
                    std::cout<<"open par token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::TK_OPENPAR);}
            ")"  {
                    std::cout<<"close par token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::TK_CLOSEPAR);}
            ","  {
                    std::cout<<"close par token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::TK_COMMA);
                }
            ">"  {
                    std::cout<<"greater than token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_GT);
                }
            "<"  {
                    std::cout<<"less than token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_LT);
                }
            ">="  {
                    std::cout<<"GET token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_GET);
                }
            "<="  {
                    std::cout<<"LET token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_LET);
                }
            "=="  {
                    std::cout<<"Equal token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_EQ);
                }
            "!="  {
                    std::cout<<"Not equal token\n"; 
                    std::cout<<"-----"<<"\n";
                    return makeToken(token::OP_NEQ);
                }
        
        */


        indent_block:
            /*!re2c

                wsp2 = [ \t]+;

                * { std::cout<<"loop text: "<<input.tokenText()<<"\n";
                    goto loop;}

                [ \t]+ {
                    //yylval->emplace<std::string>(std::string(input.tok, input.cur).c_str(),std::string(input.tok, input.cur).size());
                    std::cout<<"text: "<<input.tokenText()<<"\n";
                    std::cout<<"text: "<<input.tokenText()<<"\n";
                    int _spaces = input.tokenText().length();
                    std::cout<<"spaces entrando:" << _spaces << "\n";
                    std::cout<<"pila de espacios:" << spaces.size() << "\n";
                    for(int x = 0; x<spaces.size(); x++){
                        std::cout<<"pos:"<<x<<", text:"<<spaces[x] << "\n";
                    }
                    std::cout<<"flag2\n";

                    if(_spaces > spaces.back()){
                        std::cout<<"flag\n";
                        spaces.push_back(_spaces);
                        std::cout<<"Push:" << _spaces << "\n\n";
                        
                        return makeToken(token::Indent);

                    }else if(_spaces < spaces.back()){
                            while(_spaces != spaces.back()){
                                remaining_tokens.push_back(token::Dedent);
                                std::cout<<"Pop:" << spaces.back() << "\n\n";
                                spaces.pop_back();
                            }
                            //std::cout<<"remaining_dedents size: "<< remaining_dedents.size() << "\n";
                            remaining_tokens.pop_back();
                            return makeToken(token::Dedent);
                    }else{
                        return makeToken(token::NewLine);
                    }
                }

                [\n] {  std::cout<<"indent_b new line: "<<input.tokenText()<<"\n"; 
                        goto indent_block;
                    }

            */
    }
}

ExprLexer::input_t::input_t(std::istream &stream)
:input(stream)
{
    buf = new char[SIZE + YYMAXFILL]; //yymaxfill lo trae re2c
    lim = buf + SIZE;  //limite del buffer
    cur = lim; //cursor de YYMARKER
    tok = lim; //apuntador de inicio del lexema
    eof = false; //sentineral de fin del buffer
}

ExprLexer::FillStatus ExprLexer::input_t::fill(size_t need)
{
    if(eof){
        return FillStatus::Eof;
    }
    const size_t free = tok - buf;
    if(free < need)
        return FillStatus::Error;

    memmove(buf,tok, lim - tok);
    lim -= free;
    cur -= free;
    tok -= free;
    lim += input.read(lim,free).gcount();
    if(lim <buf +SIZE){
        eof = true;
        memset(lim,0, YYMAXFILL);
        lim += YYMAXFILL;
    }
    return FillStatus::Ok;
}