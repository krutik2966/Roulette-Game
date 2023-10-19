#include "Outcome.hpp"
#include <iostream>

Outcome::Outcome(){
    name = "";
    odds = 0;
}

Outcome::Outcome(std::string name,int odds){
    this->name = name;
    this->odds = odds;
}

void Outcome::printData(){
    std::cout<<name<<" "<<odds<<std::endl;
}

std::string Outcome::getName() const{
    return name;
}

int Outcome::getOdds() const{
    return odds;
}

float Outcome::winAmount(float amount){
    return amount*odds;
}

bool Outcome::operator==(const Outcome& o1) const{
    std::string newName = o1.getName();
    if(name==newName){
        return true;
    }

    return false;
}

bool Outcome::operator!=(const Outcome& o1) const{
    if(name!=o1.getName()){
        return true;
    }

    return false;
}

//IMP operator overloading function for < should be const
bool Outcome::operator<(const Outcome& o1) const{
    return name<o1.getName();
}

std::string Outcome::to_string(){
    return name + " (" + std::to_string(odds) + ":1)";
}
