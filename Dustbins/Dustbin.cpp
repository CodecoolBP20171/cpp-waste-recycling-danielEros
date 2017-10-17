//
// Created by eros on 17/10/17.
//

#include "Dustbin.h"
#include "../ErrorHandling/DustBinExceptions.hpp"

Dustbin::Dustbin() : paperContent(new PaperGarbage[10]){}

Dustbin::Dustbin(string color) : paperContent(new PaperGarbage[10]) {
    this->color = color;
}

string Dustbin::getColor() {
    return color;
}

void Dustbin::setColor() {
    this->color = color;
}

void Dustbin::throwOutPaperGarbage(const PaperGarbage &paperGarbage) {
    //TODO:
    // 1. Add to the end of paperContent, and not to the 0th element
    // 2. only if the paperGarbage is squeezed (if not, raise a DustbinContentError exception)
    // 3. and if there is still room for the paperGarage (i.e. paperContent.size() < 11)
    //  if there is no room, throw a DustbinIsFull exception
    // 4. MAX_SIZE should be a const variable, or a macro instead of the hard coded 10
    // 5. EXTRA: max weight -> leads to far from here
    if(paperGarbage.getIsSqueezed()){
        paperContent[0] = paperGarbage;
        paperContent[1].setName("kkk");
        cout << paperContent[1].getName() << endl;
    } else {
        throw DustbinContentError();
    }
}
