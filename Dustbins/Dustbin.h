//
// Created by eros on 17/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN_H
#define CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN_H

#include <iostream>
#include <memory>
#include "../ErrorHandling/DustBinExceptions.hpp"
#include "../Garbages/Garbage.h"
#include "../Garbages/PaperGarbage.h"

using namespace std;

class Dustbin {
public:
    Dustbin();
    Dustbin(string color);
    string getColor();
    void setColor();
    //TODO: Should be protected:
    unique_ptr<PaperGarbage[]> paperContent;
protected:
    string color;
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN_H
