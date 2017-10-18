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
#include "../Garbages/PlasticGarbage.h"

using namespace std;

class Dustbin {
public:
    Dustbin();
    Dustbin(string color);
    string tryToThrowOut(const Garbage &garbage);
protected:
    const int MAX_CONTAINER_SIZE = 2;
    string color;
    string getColor();
    void setColor();
    void throwOutPaperGarbage(const PaperGarbage &paperGarbage);
    void throwOutPlasticGarbage(const PlasticGarbage &plasticGarbage);
    string throwOutGarbage(const Garbage &garbage);
    void emptyContents();
    unique_ptr<PaperGarbage[]> paperContent;
    unique_ptr<PlasticGarbage[]> plasticContent;
    unique_ptr<Garbage[]> houseWasteContent;
    int getIndexOfLastPaper();
    int getIndexOfLastPlastic();
    int getIndexOfLastGarbage();
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN_H
