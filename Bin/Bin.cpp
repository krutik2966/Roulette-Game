#include "Bin.hpp"

Bin::Bin(){
    outcomes = {};
}

Bin::Bin(vector<Outcome> outcome_list){
    for(Outcome o:outcome_list){
        outcomes.insert(o);
    }
}

Bin::Bin(const Bin& b1){
    outcomes = b1.getOutcomes();
}

set<Outcome> Bin::getOutcomes() const{
    return outcomes;
} 

string Bin::to_string(){

    string out = "";

    for(auto o:outcomes){
        out += ( "[" + o.to_string() + "], ");
    } 
    return out.substr(0,out.length()-2);
}

bool Bin::add(Outcome o1){
    try{
        outcomes.insert(o1);
        return true;
    }catch(...){
        return false;
    }
}
