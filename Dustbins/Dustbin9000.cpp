//
// Created by eros on 18/10/17.
//

#include "Dustbin9000.h"

Dustbin9000::Dustbin9000(string color) : Dustbin(color),
                                         metalContent(new MetalGarbage[MAX_CONTAINER_SIZE]),
                                         bottleCapContent(new BottleCap[MAX_CONTAINER_SIZE]){}

Dustbin9000::Dustbin9000() : Dustbin(),
                             metalContent(new MetalGarbage[MAX_CONTAINER_SIZE]),
                             bottleCapContent(new BottleCap[MAX_CONTAINER_SIZE]){}

string Dustbin9000::throwOutMetalGarbage(const MetalGarbage &metalGarbage) {
    if(!metalGarbage.getName().empty()){
        int indexOfLastElement = getIndexOfLastMetalGarbage();
        if(indexOfLastElement < MAX_CONTAINER_SIZE - 1) {
            metalContent[indexOfLastElement + 1] = metalGarbage;
            return metalGarbage.getName() + " was thrown into the metal container of dustbin.";
        } else {
            throw DustbinIsFull();
        }
    } else {
        throw DustbinContentError();
    }
}

void Dustbin9000::throwOutBottleCap(const BottleCap &bottleCap) {
    if(bottleCap.getColor() == "pink" && !bottleCap.getName().empty()){
    int indexOfLastElement = getIndexOfLastBottleCap();
        if(indexOfLastElement < MAX_CONTAINER_SIZE - 1) {
            bottleCapContent[indexOfLastElement + 1] = bottleCap;
            cout << bottleCap.getName() << " was thrown into the bottle cap container of dustbin." << endl;
        } else {
            throw DustbinIsFull();
        }
    } else {
        throw BottleCapException();
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

int Dustbin9000::getIndexOfLastBottleCap() {
    int result = -1;
    for(int i=0; i<MAX_CONTAINER_SIZE; i++){
        if(!bottleCapContent[i].getName().empty()){
            result = i;
        }
    }
    return result;
}

string Dustbin9000::emptyContents() {
    for(int i=0; i<MAX_CONTAINER_SIZE; i++){
        metalContent[i].setName("");
        bottleCapContent[i].setName("");
        bottleCapContent[i].setColor("");
    }
    return Dustbin::emptyContents();
}

string Dustbin9000::tryToThrowOutMetal(const MetalGarbage &metalGarbage) {
    string result;
    try {
        result = throwOutMetalGarbage(metalGarbage);
    } catch (exception &message) {
        result = message.what();
    }
    return result;
}

