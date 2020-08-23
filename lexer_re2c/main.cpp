#include <iostream>
#include <fstream>
#include <unordered_map>
#include "lexer.h"

int main(int argc, char* argv[])
{

    std::unordered_map<std::string, int> vars;

    if(argc != 2)
    {
        std::cerr<<"Usage: "<< argv[0] << "<input file>\n";
        return 1;
    }

    std::ifstream in(argv[1], std::ios::in);
    if(!in.is_open()){
        fprintf(stderr, "Cannot open file %s\n",argv[1]);
        return 1;
    }

    ExprLexer lexer(in);
    Expr::Parser p(vars,lexer);
    try{
        p.parse();
    }catch(std::string &err){
        std::cerr<<err<<"\n";
    }

    return 0;
}

