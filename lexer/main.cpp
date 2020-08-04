#include <cstdio>
#include <iostream>
// #include "count.h"

extern FILE *yyin;
extern int num_lines;
extern int num_chars;
extern int num_idents;
extern int num_dec;
extern int num_literals;

int yylex();

int main(int argc, char *argv[]) {

    if(argc != 2)
    {
        std::cerr<<"Usage: "<< argv[0] << "<input file>\n";
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin  == nullptr){
        std::cerr<<"Cannot open file\n";
        return 1;
    }

    yylex();
    printf("Lines: %d, Chars: %d\n", num_lines, num_chars);
    printf("Idents:%d, Decimals: %d\n", num_idents, num_dec);
    printf("Literals: %d\n", num_literals);
    return 0;

}