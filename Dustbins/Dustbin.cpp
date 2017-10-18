//
// Created by eros on 17/10/17.
//

#include "Dustbin.h"

Dustbin::Dustbin() : paperContent(new PaperGarbage[MAX_CONTAINER_SIZE]),
                     plasticContent(new PlasticGarbage[MAX_CONTAINER_SIZE]),
                     houseWasteContent(new Garbage[MAX_CONTAINER_SIZE]){}

Dustbin::Dustbin(string color) : paperContent(new PaperGarbage[MAX_CONTAINER_SIZE]),
                                 plasticContent(new PlasticGarbage[MAX_CONTAINER_SIZE]),
                                 houseWasteContent(new Garbage[MAX_CONTAINER_SIZE]){
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
        if(indexOfLastElement < MAX_CONTAINER_SIZE - 1) {
            paperContent[indexOfLastElement + 1] = paperGarbage;
            cout << paperGarbage.getName() << " was thrown into the paper container of dustbin." << endl;
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
        if(indexOfLastElement < MAX_CONTAINER_SIZE - 1) {
            plasticContent[indexOfLastElement + 1] = plasticGarbage;
            cout << plasticGarbage.getName() << " was thrown into the plastic container of dustbin." << endl;
        } else {
            throw DustbinIsFull();
        }
    } else {
        throw DustbinContentError();
    }
}

void Dustbin::throwOutGarbage(const Garbage &garbage) {
    //TODO EXTRA: max weight -> leads to far from here
    if(!garbage.getName().empty()){
        int indexOfLastElement = getIndexOfLastGarbage();
        if(indexOfLastElement < MAX_CONTAINER_SIZE - 1) {
            houseWasteContent[indexOfLastElement + 1] = garbage;
            cout << garbage.getName() << " was thrown into the house waste container of dustbin." << endl;
        } else {
            throw DustbinIsFull();
        }
    } else {
        throw DustbinContentError();
    }
}

int Dustbin::getIndexOfLastPaper() {
    int result = -1;
    for(int i=0; i<MAX_CONTAINER_SIZE; i++){
        if(!paperContent[i].getName().empty()){
            result = i;
        }
    }
    return result;
}

int Dustbin::getIndexOfLastPlastic() {
    int result = -1;
    for(int i=0; i<MAX_CONTAINER_SIZE; i++){
        if(!plasticContent[i].getName().empty()){
            result = i;
        }
    }
    return result;
}

int Dustbin::getIndexOfLastGarbage() {
    int result = -1;
    for(int i=0; i<MAX_CONTAINER_SIZE; i++){
        if(!houseWasteContent[i].getName().empty()){
            result = i;
        }
    }
    return result;
}

void Dustbin::emptyContents() {
    for(int i=0; i<MAX_CONTAINER_SIZE; i++){
        paperContent[i].setName("");
        plasticContent[i].setName("");
        houseWasteContent[i].setName("");
    }
    cout << "The dustbin was successfully emptied!" << endl;
}
