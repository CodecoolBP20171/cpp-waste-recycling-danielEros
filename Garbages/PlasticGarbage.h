//
// Created by eros on 17/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_PLASTICGARBAGE_H
#define CPP_WASTE_RECYCLING_DANIELEROS_PLASTICGARBAGE_H

#include "Garbage.h"

class PlasticGarbage : public Garbage {
public:
    PlasticGarbage(){ isClean = false; }
    PlasticGarbage(string name);
    void clean();
    bool getIsClean();
private:
    bool isClean;
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_PLASTICGARBAGE_H
