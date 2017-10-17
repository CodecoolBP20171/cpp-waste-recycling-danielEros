//
// Created by eros on 17/10/17.
//

#include "Dustbin.h"

namespace dustbinParameters {
    const int MAX_CONTAINER_SIZE = 10;
}

Dustbin::Dustbin() : paperContent(new PaperGarbage[dustbinParameters::MAX_CONTAINER_SIZE]){}

Dustbin::Dustbin(string color) : paperContent(new PaperGarbage[dustbinParameters::MAX_CONTAINER_SIZE]) {
    this->color = color;
}

string Dustbin::getColor() {
    return color;
}

void Dustbin::setColor() {
    this->color = color;
}

void Dustbin::throwOutPaperGarbage(const PaperGarbage &paperGarbage) {
    //TODO
    // 1. and if there is still room for the paperGarage (i.e. paperContent.size() < 11)
    //  if there is no room, throw a DustbinIsFull exception
    // 2. EXTRA: max weight -> leads to far from here
    if(paperGarbage.getIsSqueezed() && !paperGarbage.getName().empty()){
        int indexOfLastElement = getIndexOfLastElement();
        // IF indexOfLastElement >= (?) dustbinParameters::MAX_CONTAINER_SIZE throw DustbinIsFull exception
        paperContent[indexOfLastElement+1] = paperGarbage;
    } else {
        throw DustbinContentError();
    }
}

int Dustbin::getIndexOfLastElement() {
    int result = -1;
    for(int i=0; i<dustbinParameters::MAX_CONTAINER_SIZE; i++){
        if(!paperContent[i].getName().empty()){
            result = i;
        }
    }
    return result;
}
