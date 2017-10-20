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
    string getColor();
    void setColor();
    string tryToThrowOut(const Garbage &garbage);
    string tryToThrowOutPaper(const PaperGarbage &paperGarbage);
    string tryToThrowOutPlastic(const PlasticGarbage &plasticGarbage);
    string emptyContents();
protected:
    const int MAX_CONTAINER_SIZE = 2;
    string color;
    unique_ptr<PaperGarbage[]> paperContent;
    unique_ptr<PlasticGarbage[]> plasticContent;
    unique_ptr<Garbage[]> houseWasteContent;
    string throwOutPaperGarbage(const PaperGarbage &paperGarbage);
    string throwOutPlasticGarbage(const PlasticGarbage &plasticGarbage);
    string throwOutGarbage(const Garbage &garbage);
    int getIndexOfLastPaper();
    int getIndexOfLastPlastic();
    int getIndexOfLastGarbage();
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN_H
