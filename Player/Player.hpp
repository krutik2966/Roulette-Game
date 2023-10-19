#ifndef PLAYER_H
#define PLAYER_H
#include "../Outcome/Outcome.hpp"
#include "../Table/Table.hpp"
#include "../Wheel/Wheel.hpp"

class Player{

    int ID;
    int stake;
    Outcome black;
    Table* table;

    public:
        Player();
        Player(Table* t);
        Player(int id,int stake, Table* t,Wheel w);
        Player(const Player& other);
        void placeBets();
        void win(Bet b);
        void lose(Bet b);
        int getPlayerID() const;
        // Player& operator=(const Player& other);

};

#endif