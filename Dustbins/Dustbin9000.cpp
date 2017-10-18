//
// Created by eros on 18/10/17.
//

#include "Dustbin9000.h"

Dustbin9000::Dustbin9000(string color) : Dustbin(color),
                                         metalContent(new MetalGarbage[MAX_CONTAINER_SIZE]){}

Dustbin9000::Dustbin9000() : Dustbin(),
                             metalContent(new MetalGarbage[MAX_CONTAINER_SIZE]){}

void Dustbin9000::throwOutMetalGarbage(const MetalGarbage &metalGarbage) {
    if(!metalGarbage.getName().empty()){
        int indexOfLastElement = getIndexOfLastMetalGarbage();
        if(indexOfLastElement < MAX_CONTAINER_SIZE - 1) {
            metalContent[indexOfLastElement + 1] = metalGarbage;
            cout << metalGarbage.getName() << " was thrown into the metal container of dustbin." << endl;
        } else {
            throw DustbinIsFull();
        }
    } else {
        throw DustbinContentError();
    }
}

int Dustbin9000::getIndexOfLastMetalGarbage() {
    int result = -1;
    for(int i=0; i<MAX_CONTAINER_SIZE; i++){
        if(!metalContent[i].getName().empty()){
            result = i;
        }
    }
    return result;
}

void Dustbin9000::emptyContents() {
    for(int i=0; i<MAX_CONTAINER_SIZE; i++){
        metalContent[i].setName("");
    }
    Dustbin::emptyContents();
}
