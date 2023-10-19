#ifndef BIN_H
#define BIN_H

#include <set>
#include <vector>
#include <string>
#include "../Outcome/Outcome.hpp"

using namespace std;

//Cannot extend set because it is a part of STL so we are wrapping it

//For future implement iterator for the set
class Bin{

    set<Outcome> outcomes;

    public:
        
        Bin();
        Bin(vector<Outcome> outcome_list);
        Bin(const Bin& b1);
        set<Outcome> getOutcomes() const;
        bool add(Outcome o1);
        string to_string();

};

#endif