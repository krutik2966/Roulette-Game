#ifndef BINBUILDER_H
#define BINBUILDER_H

#include <unordered_set>
#include "../Wheel/Wheel.hpp"
#include "../RouletteGame/RouletteGame.hpp"

class BinBuilder{

    RouletteGame RouletteGame;

    public:
        void buildBins(Wheel* w);

    private:
        void generateStraightBets(Wheel* w);
        void generateSplitBets(Wheel* w);
        void generateStreetBets(Wheel* w);
        void generateCornerBets(Wheel* w);
        void generateLineBets(Wheel* w);
        void generateDozenBets(Wheel* w);
        void generateColumnBets(Wheel* w);
        void generateEvenMoneyBets(Wheel* w);
        void generateFiveBets(Wheel* w);

};

#endif

