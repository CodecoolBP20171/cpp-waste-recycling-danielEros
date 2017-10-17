//
// Created by eros on 17/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_PAPERGARBAGE_H
#define CPP_WASTE_RECYCLING_DANIELEROS_PAPERGARBAGE_H

#include "Garbage.h"

class PaperGarbage : public Garbage {
public:
    PaperGarbage(){ isSqueezed = false; }
    PaperGarbage(string name);
    void squeeze();
    bool getIsSqueezed() const;
private:
    bool isSqueezed;
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_PAPERGARBAGE_H
