#include <iostream>
#include "Garbages/Garbage.h"
#include "Garbages/PaperGarbage.h"
#include "Garbages/PlasticGarbage.h"
#include "Dustbins/Dustbin.h"

using namespace std;

int main() {
    Garbage garbage("szemét");
    /*
    garbage.printName();
    garbage.setName("ggg");
    garbage.printName();
    PaperGarbage paperGarbage;
    paperGarbage.setName("papírszemét");
    paperGarbage.printName();
    cout << paperGarbage.getIsSqueezed() << endl;
    paperGarbage.squeeze();
    cout << paperGarbage.getIsSqueezed() << endl;
    */
    PaperGarbage paperGarbage("papír");
    PaperGarbage paperGarbage2("papír2");
    paperGarbage2.squeeze();
    //paperGarbage2.printName();


    PlasticGarbage plasticGarbage("mert ez műanyag");
    plasticGarbage.clean();
    PlasticGarbage plasticGarbage2("műanyag2");
    plasticGarbage2.clean();
    PlasticGarbage plasticGarbage3("műanyag3");
    plasticGarbage3.clean();
    /*
    plasticGarbage.printName();
    cout << plasticGarbage.getIsClean() << endl;
    plasticGarbage.clean();
    cout << plasticGarbage.getIsClean() << endl;
    */

    Dustbin dustbin("green");
    //cout << dustbin.getColor() << endl;
    //dustbin.paperContent[0] = paperGarbage;
    //cout << dustbin.paperContent[0].getName();
    try {
        dustbin.throwOutGarbage(garbage);
        dustbin.throwOutPaperGarbage(paperGarbage2);
        dustbin.throwOutPlasticGarbage(plasticGarbage);
        dustbin.throwOutPlasticGarbage(plasticGarbage2);
        dustbin.throwOutPlasticGarbage(plasticGarbage3);
    } catch(exception &err) {
        cout << err.what();
    }
    return 0;
}