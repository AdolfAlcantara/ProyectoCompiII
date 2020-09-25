#include <iostream>
#include <fstream>
#include <unordered_map>
#include "lexer.h"

std::string getFileName(std::string path){
    std::size_t pos = path.find_last_of("/");
    path = path.substr(pos+1);
    pos = path.find(".");
    path = path.substr(0,pos);
    return path;
}

std::string createContext(Ast::SymbolTableGen symb_tbl_gen){
    std::string context =".global main\n.data\n";
    context += "true:\n\t.byte \"true\", 0\n";
    context += "false:\n\t.byte \"false\", 0\n";
    for(auto &x: symb_tbl_gen){
        if(x.second == ""){
            context += x.first +": .word 0\n";
        }else{
            context += x.first+":\n\t.byte "+x.second+", 0 \n";
        }
    }
    context += "\n.text\n";
    //print true block stmt
    context += "print_true:\n\n";
    context += "addi\t\t $sp, $sp, -4\n";
    context += "sw\t\t $ra, 0($sp)\n";
    context += "la\t\t $a0, true\n";
    context += "jal\t\t print_str\n";
    context += "lw\t\t $ra, 0($sp)\n";
    context += "addi\t\t $sp, $sp, 4\n";
    context += "jr\t\t $ra\n\n";

    context += "print_false:\n\n";
    context += "addi\t\t $sp, $sp, -4\n";
    context += "sw\t\t $ra, 0($sp)\n";
    context += "la\t\t $a0, false\n";
    context += "jal\t\t print_str\n";
    context += "lw\t\t $ra, 0($sp)\n";
    context += "addi\t\t $sp, $sp, 4\n";
    context += "jr\t\t $ra\n";
    return context;
}

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

    std::string name = getFileName(argv[1]);
    name = "../generated/"+name+".asm";
    

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
    //root->eval(symb_tbl);
    root->gen(symb_tbl_gen);

    std::string context = createContext(symb_tbl_gen);
    context+= root->code;

    std::ofstream mips_generated(name);
    mips_generated<<context;
    mips_generated.close();

    return 0;
}