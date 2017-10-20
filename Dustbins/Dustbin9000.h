//
// Created by eros on 18/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN9000_H
#define CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN9000_H


#include "Dustbin.h"
#include "../Garbages/MetalGarbage.h"
#include "../Garbages/BottleCap.h"

class Dustbin9000 : public Dustbin {
// TODO: most members can be private after finishing Tester!
public:
    Dustbin9000();
    Dustbin9000(string color);
    string tryToThrowOutMetal(const MetalGarbage &metalGarbage);
    string tryToThrowOutBottleCap(const BottleCap &bottleCap);
    string emptyContents();
private:
    unique_ptr<MetalGarbage[]> metalContent;
    unique_ptr<BottleCap[]> bottleCapContent;
    string throwOutMetalGarbage(const MetalGarbage &metalGarbage);
    string throwOutBottleCap(const BottleCap &bottleCap);
    int getIndexOfLastMetalGarbage();
    int getIndexOfLastBottleCap();
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN9000_H
