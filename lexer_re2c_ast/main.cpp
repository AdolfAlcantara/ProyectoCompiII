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

    Ast::Node *root;
    ExprLexer lexer(in);
    Expr::Parser p(root,lexer);
    try{
        p.parse();
    }catch(std::string &err){
        std::cerr<<err<<"\n";
        return 1;
    }
    Ast::SymbolTable symb_tbl;
    Ast::SymbolTableGen symb_tbl_gen;
    // root->eval(symb_tbl);
    root->gen(symb_tbl_gen);

    std::string context =".data\n";
    for(auto &x: symb_tbl_gen){
        if(x.second == ""){
            context += x.first +": .word 0\n";
        }else{
            context += x.first+":\n\t.byte "+x.second+", 0 \n";
        }
    }
    context += "\n.text\nmain:\n";
    context += root->code;
    std::cout<<"Codigo generado:"<<std::endl;
    std::cout<<context;


    return 0;
}

