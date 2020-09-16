#include <sstream>
#include <cstdio>
#include <vector>
#include <map> 

class Auxiliar
{   
public:
    Auxiliar(){}

    int getReg(){
        // for(int i=0;i<10;i++){
        //     std::cout<<to_str(i)+": "<<regs[i]<<"\n";
        // }
        for(int i=0;i<10;i++){
            if(!regs[i]){
                regs[i] = true;
                return i;
            }
        }
        std::cout<<"Oh oh, no registers avaialable\n";
        throw std::exception();
    }

    int getArg(){
        for(int i=0;i<4;i++){
            if(!args[i]){
                args[i]=true;
                return i;
            }
        }
        std::cout<<"Oh oh, no arguments avaialable\n";
        throw std::exception();
    }

    void freeReg(int regPos){
        regs[regPos] = false;
        return;
    }

    void freeArg(int argPos){
        args[argPos] = false;
        return;
    }

    void freeArgs(){
       for(int i=0;i<4;i++){
            args[i]=false;
        }
    }

    std::string to_str(int x) {
        std::stringstream ss;
        ss << x;
        return ss.str();
    }

    std::string varGenerator(){
        return "var"+to_str(varCounter++);
    }

    std::string labelGenerator(std::string modifier){
        if(modifier!=""){
            return "label_"+modifier+"_"+to_str(labelCounter++);
        }else{
            return "label_"+to_str(labelCounter++);
        }
    }
    
    //vars = tabla de variables
    // t = identificador o literal
    // var_type = 1: identificador
    //            2: literal
    std::string saveVar(std::unordered_map<std::string, std::string> &vars, std::string t,int varType){
        if(varType == 1){
            vars.insert({t,""});
            return "";
        }else{
            std::string var = varGenerator();
            vars.insert({var,t});
            return var;
        }
    }

    void saveLabel(std::string name, std::string label){
        functions.insert(std::pair<std::string,std::string>(name, label));
    }

    std::string getLabel(std::string name){
        std::map<std::string,std::string>::iterator it;

        it = functions.find(name);
        if(it != functions.end()){
            return it->second;
        }else{
            std::cout<<"No se encontro etiqueta para "+name+"\n";
            return nullptr;
        }

    }

    void saveArrayRange(int spaces){
        arraySizes.push_back(spaces);
    }

    int removeArrayRange(){
        int size = arraySizes.back();
        arraySizes.pop_back();
        return size;
    }

private:
    std::vector<int> arraySizes;
    int varCounter = 0,labelCounter=0;
    std::map<std::string, std::string> functions;
    std::map<int, bool> args{
        {0,false},
        {1,false},
        {2,false},
        {3,false}
    };
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