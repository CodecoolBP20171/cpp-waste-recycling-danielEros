//
// Created by eros on 17/10/17.
//

#include "Garbage.h"

Garbage::Garbage(string name) {
    this->name = name;
}

void Garbage::printName() {
    cout << name << endl;
}

string Garbage::getName() const {
    return name;
}

void Garbage::setName(string name) {
    this->name = name;
}