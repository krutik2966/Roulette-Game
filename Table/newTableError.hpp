#ifndef NEWTABLEERROR_H
#define NEWTABLEERROR_H

#include <exception>
using namespace std;

class newTableError : public exception{
    public:
        const char* what(){
            return "Cannot create new table : Table already exists!!";
        }
};

#endif