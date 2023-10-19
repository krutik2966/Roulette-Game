#include "Game.hpp"

Game::Game(int pl,Wheel* w,Table* t){
    playerLimit = pl;
    wheel = w;

    BinBuilder b;
    b.buildBins(wheel);

    table = t;
}

void Game::addPlayer(Player p){

    if(playerList.size()==playerLimit){
        cout<<"Player Limit Reached!!"<<endl;
        return;
    }

    playerList[p.getPlayerID()] = p;
}

void Game::cycle(){

    for(auto p:playerList){
        p.second.placeBets();
    }

    Bin winningBin = (*wheel).choose();
    set<Outcome> winningOutcomes = winningBin.getOutcomes();
    cout<<"---------------Winning Bin----------------------"<<endl;
    cout<<winningBin.to_string()<<endl;
    cout<<"------------------------------------------------"<<endl;
    for(auto bet:(*table)){

        Outcome betOutcome = bet.getBetOutcome();

        int playerId = bet.getPlayerId();

        if(winningOutcomes.find(betOutcome)!=winningOutcomes.end()){

            cout<<"------------WINNING BET------------"<<endl;
            cout<<"Player ID : "<<playerId<<endl;
            cout<<"Winning Amount : "<<bet.winAmount()<<endl;

            playerList[playerId].win(bet);
        }else{
            
            cout<<"------------LOSING BET------------"<<endl;
            cout<<"Player ID : "<<playerId<<endl;
            cout<<"Lossing Amount : "<<bet.loseAmount()<<endl;

        }

    }

}