#include "./Wheel/Wheel.hpp"
#include "./Game/Game.hpp"
#include "./Player/Player.hpp"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

        Wheel* w = new Wheel();

        int tableLimit = 1000;
        int minimumBet = 125;
        Table* t = new Table(tableLimit,minimumBet);

        int playerLimit = 10;

        Game g(playerLimit,w,t);

        int playerId = 1;
        int stake = 1000;

        Player p1(playerId,stake,t,*w);

        g.addPlayer(p1);

        g.cycle();

        // cout<<(*w).to_string()<<endl;
}       