@echo off
g++ ./Outcome/Outcome.cpp ./Bin/Bin.cpp ./Wheel/Wheel.cpp ./BinBuilder/BinBuilder.cpp ./Bet/Bet.cpp ./Table/InvalidBet.cpp ./Table/Table.cpp ./Player/Player.cpp ./Game/Game.cpp main.cpp -o bin.exe
bin.exe