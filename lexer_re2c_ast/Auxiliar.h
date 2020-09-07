#include <sstream>
#include <cstdio>
#include <map> 

class Auxiliar
{   
public:
    Auxiliar(){}

    int getReg(){
        for(int i=0;i<10;i++){
            if(!regs[i]){
                regs[i] = true;
                return i;
            }
        }
    }

    void freeReg(int regPos){
        regs[regPos] = false;
        return;
    }

    std::string to_str(int x) {
        std::stringstream ss;
        ss << x;
        return ss.str();
    }

    std::string varGenerator(){
        return "var"+to_str(varCounter++);
    }
    
    //vars = tabla de variables
    // t = identificador o literal
    // var_type = 1: identificador
    //            2: literal
    std::string saveVar(std::unordered_map<std::string, std::string> &vars, std::string t,int varType){
        if(varType == 1){
            vars.insert({t,""});
            return nullptr;
        }else{
            std::string var = varGenerator();
            vars.insert({var,t});
            return var;
        }
    }

private:

    int varCounter = 0;
    std::map<int,bool> regs{ 
        {0,false},
        {1,false},
        {2,false},
        {3,false},
        {4,false},
        {5,false},
        {6,false},
        {7,false},
        {8,false},
        {9,false},
    };
};