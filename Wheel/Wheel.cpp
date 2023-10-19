#include "Wheel.hpp"

Wheel::Wheel() : dist(0,37) {

    vector<Outcome> temp;
    Bin tempBin(temp);
    random_device rd;
    generator = mt19937(rd());

    bins.resize(38,tempBin);
    
    return;
}

Bin Wheel::choose(){

    // cout<<generator<<endl;
    int randomNumber = dist(generator);

    return bins[randomNumber];
}

Bin Wheel::get(int bin_id) const{
    return bins[bin_id];
}

void Wheel::addOutcome(int bin_id,Outcome outcome){
    bins[bin_id].add(outcome);
    all_outcomes[outcome.getName()] = outcome;
}

Outcome Wheel::getOutcome(string name){
    return all_outcomes[name];
}

string Wheel::to_string(){
    
    string ans = "[ ";
    for(auto b:bins){
        
        ans += b.to_string();
        ans += ", ";
    }

    ans += " ]";
    return ans;
}