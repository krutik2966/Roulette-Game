#include "Player.hpp"
#include <iostream>

Player::Player() : table(nullptr){}

Player::Player(Table* t):table(t){}

Player::Player(int id,int stake, Table* t,Wheel w): table(t){
    Player::ID = id;
    Player::stake = stake;
    black = w.getOutcome("Black");
}


Player::Player(const Player& other) : table(other.table){
    ID = other.ID;
    stake = other.stake;
    black = other.black;
}

void Player::placeBets(){
    Bet b(ID,150,black);
    (*table).placeBet(b);

    stake -= b.getBetAmount();
}

void Player::win(Bet bet){
    stake += bet.winAmount();
}

void Player::lose(Bet bet){
    
}

int Player::getPlayerID() const{
    return ID;
}
