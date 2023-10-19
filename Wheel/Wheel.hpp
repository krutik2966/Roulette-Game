#ifndef WHEEL_H
#define WHEEL_H

#include <vector>
#include <random>
#include <unordered_map>
#include <string>

#include "../Outcome/Outcome.hpp"
#include "../Bin/Bin.hpp"

using namespace std;

class Wheel{

    vector<Bin> bins;
    unordered_map<string,Outcome> all_outcomes;
    mt19937 generator;
    uniform_int_distribution<int> dist;

    public:

        Wheel();
        void addOutcome(int bin_id,Outcome outcome);
        Bin choose();
        Bin get(int bin_id) const;
        Outcome getOutcome(string name);
        string to_string();
    
};

#endif