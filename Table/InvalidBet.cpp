#include "InvalidBet.hpp"

InvalidBet::InvalidBet(const char* msg) : message(msg){}

const char* InvalidBet::what() const noexcept{
    return message;
}

