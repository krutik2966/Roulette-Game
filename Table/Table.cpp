#include "Table.hpp"
#include <iostream>

//Iterator
//-------------------------------------------------------------
Iterator::Iterator(){}

Iterator::Iterator(set<Bet>::iterator ptr){
    current = ptr;
}

const Bet& Iterator::operator*() const{
    return *current;
}

Iterator& Iterator::operator++(){
    ++current;
    return *this;
}

bool Iterator::operator==(const Iterator& other) const{
    return current==other.current;
}

bool Iterator::operator!=(const Iterator& other) const{
    return current!=other.current;
}

//-------------------------------------------------------------


//Table

Table::Table(){
    limit = 100;
    minBet = 10;
}

Table::Table(int l,int m){
    limit = l;
    minBet = m;
}

Table::Table(vector<Bet> arr){

    for(auto b:arr){
        bets.insert(b);
    }
};

Table::Table(set<Bet> betSet): bets(betSet) {};

void Table::placeBet(Bet bet){

    if(isValid(bet)){
        bets.insert(bet);
    }
        
}

string Table::to_string(){

    string ans = "[ ";

    for(auto b:bets){
        ans += b.to_string();
        ans += ", ";
    }
    
    ans = ans.substr(0,ans.length()-2);

    if(ans.size()>0)
        ans += "]";

    if(ans.size()==0){
        ans = "No bets placed!";
    }

    return ans;
}

bool Table::isValid(Bet bet){
    
    int total = bet.getBetAmount();

    if(bet.getBetAmount()<minBet){
        errorMessage = "Bet amount is less than minimum allowed!";
        throw InvalidBet(&errorMessage[0]);
        return false;
    }

    for(auto b:bets){
        total += b.getBetAmount();
    }

    bool overLimit = false;

    if(total>limit){
        errorMessage = "Over Limit!";
        throw InvalidBet(&errorMessage[0]);
        return false;
    }

    return true;

}

Iterator Table::begin(){
    return Iterator(bets.begin());
}

Iterator Table::end(){
    return Iterator(bets.end());
}

void Table::operator=(const Table& other){
    limit = other.limit;
    minBet = other.minBet;
    bets = other.bets;
    errorMessage = other.errorMessage;
}


