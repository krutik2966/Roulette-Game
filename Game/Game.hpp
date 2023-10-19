#ifndef GAME_H
#define GAME_H

#include "../Table/Table.hpp"
#include "../Wheel/Wheel.hpp"
#include "../Player/Player.hpp"
#include "../BinBuilder/BinBuilder.hpp"

#include <iostream>

using namespace std;
class Game{

    Wheel* wheel;
    Table* table;
    int playerLimit;
    unordered_map<int,Player> playerList;

    public:
        Game(int pl,Wheel* w,Table* t);
        void addPlayer(Player p);
        void cycle();  
};

#endif