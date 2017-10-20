//
// Created by eros on 17/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_GARBAGE_H
#define CPP_WASTE_RECYCLING_DANIELEROS_GARBAGE_H


#include <iostream>
using namespace std;

class Garbage {
public:
    Garbage(){};
    Garbage(string name);
    void printName();
    string getName() const;
    void setName(string);
protected:
    string name;
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_GARBAGE_H
