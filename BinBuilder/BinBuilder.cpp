#include "BinBuilder.hpp"

void BinBuilder::buildBins(Wheel* w){

        generateStraightBets(w);
        generateSplitBets(w);
        generateStreetBets(w);
        generateCornerBets(w);
        generateLineBets(w);
        generateDozenBets(w);
        generateColumnBets(w);
        generateEvenMoneyBets(w);
        generateFiveBets(w);

}

void BinBuilder::generateStraightBets(Wheel* w){

    for(int i=0;i<37;i++){
        (*w).addOutcome(i,Outcome("Number "+to_string(i),RouletteGame.STRAIGHT));
    }

    (*w).addOutcome(37,Outcome("Number 00",RouletteGame.STRAIGHT));
}

void BinBuilder::generateSplitBets(Wheel* w){

    for (int r=0; r<12; r++) {

        for (int i=1; i<=2; i++) {

            int n = 3*r + i;

            string name = "Split "+to_string(n)+"-"+to_string(n+1);
            Outcome split(name, RouletteGame.SPLIT);
            (*w).addOutcome(n, split);
            (*w).addOutcome(n+1, split);
        }
    }

    // Up-down split bets
    for (int n=1; n<=33; n++) {
        string name = "Split "+to_string(n)+"-"+to_string(n+3);
        Outcome split(name, RouletteGame.SPLIT);
        (*w).addOutcome(n, split);
        (*w).addOutcome(n+3, split);
    }

}

void BinBuilder::generateStreetBets(Wheel* w){

    for (int r=0; r<12; r++) {

        int n = 3*r + 1;

        string name = "Street "+to_string(n)+"-"+to_string(n+1)+"-"+to_string(n+2);
        Outcome street(name, RouletteGame.STREET);
        (*w).addOutcome(n, street);
        (*w).addOutcome(n+1, street);
        (*w).addOutcome(n+2, street);

    }

}

void BinBuilder::generateCornerBets(Wheel* w){

    for (int r=0; r<11; r++) {
        for (int i=1; i<=2; i++) {

            int n = 3*r + i;

            string name = "Corner "+to_string(n)+"-"+to_string(n+1)+"-"+to_string(n+3)+"-"+to_string(n+4);
            Outcome corner(name, RouletteGame.CORNER);
            (*w).addOutcome(n, corner);
            (*w).addOutcome(n+1, corner);
            (*w).addOutcome(n+3, corner);
            (*w).addOutcome(n+4, corner);

        }
    }

}

void BinBuilder::generateLineBets(Wheel* w){

    for (int r=0; r<11; r++) {

        int n = 3*r + 1;

        string name = "Line "+to_string(n)+"-"+to_string(n+1)+"-"+to_string(n+2)+"-"+to_string(n+3)+"-"+to_string(n+4)+"-"+to_string(n+5);
        Outcome line(name, RouletteGame.LINE);

        for (int i=0; i<6; i++)
            (*w).addOutcome(n+i, line);
    }

}

void BinBuilder::generateDozenBets(Wheel* w){

    for (int d=0; d<3; d++) {

        Outcome dozen("Dozen " + to_string(d+1), RouletteGame.DOZEN);
        for (int m=0; m<12; m++)
            (*w).addOutcome(12*d+m+1, dozen);
    }

}

void BinBuilder::generateColumnBets(Wheel* w){
    for (int c=0; c<3; c++) {
        Outcome column("Column " + to_string(c+1), RouletteGame.COLUMN);
        for (int r=0; r<12; r++)
            (*w).addOutcome(3*r+c+1, column);
    }
}

void BinBuilder::generateEvenMoneyBets(Wheel* w){

    // --- Even-Money bets ---
		Outcome red("Red", RouletteGame.EVEN_MONEY);
		Outcome black("Black", RouletteGame.EVEN_MONEY);
		Outcome even("Even", RouletteGame.EVEN_MONEY);
		Outcome odd("Odd", RouletteGame.EVEN_MONEY);
		Outcome high("High", RouletteGame.EVEN_MONEY);
		Outcome low("Low", RouletteGame.EVEN_MONEY);

        unordered_set<int> lred = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};

        for (int n=1; n<=36; n++) {
            if (n <= 18)
                (*w).addOutcome(n, low);
            else
                (*w).addOutcome(n, high);
            if (n % 2 == 0)
                (*w).addOutcome(n, even);
            else
                (*w).addOutcome(n, odd);

            if (lred.count(n))
                (*w).addOutcome(n, red);
            else
                (*w).addOutcome(n, black);
        }

}

void BinBuilder::generateFiveBets(Wheel* wheel){

    	// --- Five number bet ---
		Outcome fiveNumber("Five number", RouletteGame.FIVE_NUMBER);
		(*wheel).addOutcome(0, fiveNumber);
		(*wheel).addOutcome(1, fiveNumber);
		(*wheel).addOutcome(2, fiveNumber);
		(*wheel).addOutcome(3, fiveNumber);
		(*wheel).addOutcome(37, fiveNumber);

}