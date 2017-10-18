//
// Created by eros on 18/10/17.
//

#include "BottleCap.h"

BottleCap::BottleCap(string name, string color) : Garbage(name), color(color){}

string BottleCap::getColor() const {
    return color;
}

void BottleCap::setColor(string color) {
    this->color = color;
}
