#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <set>
#include <string>
#include "../Bet/Bet.hpp"
#include "InvalidBet.hpp"

using namespace std;

class Iterator{
            
    set<Bet>::iterator current;
    public:
        Iterator();
        Iterator(set<Bet>::iterator ptr);
        const Bet& operator*() const;
        Iterator& operator++();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

};

class Table{

    int limit;
    int minBet;
    set<Bet> bets;
    string errorMessage;

    public:
        Table();
        Table(int l,int m);
        Table(vector<Bet> arr);
        Table(set<Bet> betSet);

        void placeBet(Bet bet);
        string to_string();
        bool isValid(Bet bet);

        Iterator begin();
        Iterator end();

        void operator=(const Table& other);

};

#endif