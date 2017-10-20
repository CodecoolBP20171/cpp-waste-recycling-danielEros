//
// Created by eros on 17/10/17.
//

#include "PlasticGarbage.h"

PlasticGarbage::PlasticGarbage(string name) : Garbage(name) {
    this->name = name;
    isClean = false;
}

void PlasticGarbage::clean() {
    this->isClean = true;
}

bool PlasticGarbage::getIsClean() const {
    return isClean;
}