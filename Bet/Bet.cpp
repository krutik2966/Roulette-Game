#include "Bet.hpp"

Bet::Bet(int id,int amnt,Outcome o){
    playerId = id;
    amountBet = amnt;
    betOutcome = o;
}

int Bet::winAmount(){
    return amountBet + amountBet*betOutcome.getOdds();
}

int Bet::loseAmount(){
    return amountBet;
}

string Bet::to_string(){
    return std::to_string(amountBet) + " on " + betOutcome.getName(); 
}

int Bet::getBetAmount() const{
    return amountBet;
}

Outcome Bet::getBetOutcome() const{
    return betOutcome;
}

int Bet::getPlayerId() const{
    return playerId;
}

bool Bet::operator<(const Bet& other) const{
    return amountBet<other.amountBet;
}