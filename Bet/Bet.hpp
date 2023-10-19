#ifndef BET_H
#define BET_H

#include "../Outcome/Outcome.hpp"
#include <string>
using namespace std;

class Bet{

    int playerId;
    int amountBet;
    Outcome betOutcome;

    public:
        Bet(int id,int amnt,Outcome o);
        int getBetAmount() const;
        Outcome getBetOutcome() const;
        int getPlayerId() const;
        int winAmount();
        int loseAmount();
        string to_string();
        bool operator<(const Bet& other) const;

};

#endif