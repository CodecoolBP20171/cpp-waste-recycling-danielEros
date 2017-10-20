//
// Created by eros on 17/10/17.
//

#include "PaperGarbage.h"

PaperGarbage::PaperGarbage(string name) : Garbage(name) {
    isSqueezed = false;
}

void PaperGarbage::squeeze() {
    this->isSqueezed = true;
}

bool PaperGarbage::getIsSqueezed() const {
    return isSqueezed;
}
