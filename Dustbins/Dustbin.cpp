//
// Created by eros on 17/10/17.
//

#include "Dustbin.h"

namespace dustbinParameters {
    const int MAX_CONTAINER_SIZE = 2;
}

Dustbin::Dustbin() : paperContent(new PaperGarbage[dustbinParameters::MAX_CONTAINER_SIZE]),
                     plasticContent(new PlasticGarbage[dustbinParameters::MAX_CONTAINER_SIZE]){}

Dustbin::Dustbin(string color) : paperContent(new PaperGarbage[dustbinParameters::MAX_CONTAINER_SIZE]),
                                 plasticContent(new PlasticGarbage[dustbinParameters::MAX_CONTAINER_SIZE]){
    this->color = color;
}

string Dustbin::getColor() {
    return color;
}

void Dustbin::setColor() {
    this->color = color;
}

void Dustbin::throwOutPaperGarbage(const PaperGarbage &paperGarbage) {
    //TODO EXTRA: max weight -> leads to far from here
    if(paperGarbage.getIsSqueezed() && !paperGarbage.getName().empty()){
        int indexOfLastElement = getIndexOfLastPaper();
        if(indexOfLastElement < dustbinParameters::MAX_CONTAINER_SIZE - 1) {
            paperContent[indexOfLastElement + 1] = paperGarbage;
            cout << paperGarbage.getName() << " was thrown into the paper dustbin." << endl;
        } else {
            throw DustbinIsFull();
        }
    } else {
        throw DustbinContentError();
    }
}

void Dustbin::throwOutPlasticGarbage(const PlasticGarbage &plasticGarbage) {
    //TODO EXTRA: max weight -> leads to far from here
    if(plasticGarbage.getIsClean() && !plasticGarbage.getName().empty()){
        int indexOfLastElement = getIndexOfLastPlastic();
        if(indexOfLastElement < dustbinParameters::MAX_CONTAINER_SIZE - 1) {
            plasticContent[indexOfLastElement + 1] = plasticGarbage;
            cout << plasticGarbage.getName() << " was thrown into the plastic dustbin." << endl;
        } else {
            throw DustbinIsFull();
        }
    } else {
        throw DustbinContentError();
    }
}

int Dustbin::getIndexOfLastPaper() {
    int result = -1;
    for(int i=0; i<dustbinParameters::MAX_CONTAINER_SIZE; i++){
        if(!paperContent[i].getName().empty()){
            result = i;
        }
    }
    return result;
}

int Dustbin::getIndexOfLastPlastic() {
    int result = -1;
    for(int i=0; i<dustbinParameters::MAX_CONTAINER_SIZE; i++){
        if(!plasticContent[i].getName().empty()){
            result = i;
        }
    }
    return result;
}
