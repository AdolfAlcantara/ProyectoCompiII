%option noyywrap


/*esto va para el cpp*/
%{
    
#include <iostream>
#include <cstdio>
#include <string.h>

int num_lines;
int num_chars;
int num_idents;
int num_dec;
int num_literals;

void Description(std::string token, std::string lexema){
    std::cout<<"Token: " << token << ", Lexema: " <<lexema <<"\n";
}
std::string FoundKw(const std::string& lexema){
    if(lexema == "print" )
        return "KwPrint";
    else
        return "Ident";
}
%}

%x comment
%x ident
%x assign

%%
= {Description("Equal",yytext);}
\+ {Description("Add",yytext);}
- {Description("Sub",yytext);}
\* {Description("Mul",yytext);}
\/ {Description("Div",yytext);}
\** {Description("Pwr",yytext);}
% {Description("Mod",yytext);}
, {Description("Comma",yytext);}
\( {Description("OpenParenthesis",yytext);}
\) {Description("CloseParenthesis",yytext);}
"\""[^(\n|\")]*"\"" {

            Description("Literal",yytext);
            }
#[^\n]*  {Description("Comment",yytext);}

[0-9]+ {Description("Decimal",yytext);}
[_a-zA-Z][_a-zA-Z0-9]* {
                        Description(FoundKw(yytext), yytext);
                        }
\n 
.  

