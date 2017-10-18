//
// Created by eros on 18/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN9000_H
#define CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN9000_H


#include "Dustbin.h"
#include "../Garbages/MetalGarbage.h"

class Dustbin9000 : public Dustbin {
public:
    Dustbin9000();
    Dustbin9000(string color);
    void throwOutMetalGarbage(const MetalGarbage &metalGarbage);
    void emptyContents();
private:
    unique_ptr<MetalGarbage[]> metalContent;
    int getIndexOfLastMetalGarbage();
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_DUSTBIN9000_H
