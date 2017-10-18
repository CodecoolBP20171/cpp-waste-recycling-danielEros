//
// Created by eros on 18/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_BOTTLECAP_H
#define CPP_WASTE_RECYCLING_DANIELEROS_BOTTLECAP_H


#include "Garbage.h"

class BottleCap : public Garbage {
public:
    BottleCap(){}
    BottleCap(string name, string color);
    string getColor();
private:
    string color;
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_BOTTLECAP_H
