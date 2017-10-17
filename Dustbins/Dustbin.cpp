//
// Created by eros on 17/10/17.
//

#include "Dustbin.h"

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
