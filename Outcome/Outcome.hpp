#ifndef OUTCOME_H
#define OUTCOME_H

#include <string>

class Outcome{

    std::string name;
    int odds;
    
    public:

        Outcome();
        Outcome(std::string name,int odds);

        std::string getName() const;
        int getOdds() const;

        float winAmount(float amount);
    
        bool operator == (const Outcome& o1) const;
        bool operator != (const Outcome& o1) const;
        bool operator < (const Outcome& o1) const;
        void printData();
        std::string to_string();

};

#endif