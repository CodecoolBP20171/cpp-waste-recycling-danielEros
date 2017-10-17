#include <iostream>
#include "Garbages/Garbage.h"
#include "Garbages/PaperGarbage.h"
#include "Garbages/PlasticGarbage.h"
#include "Dustbins/Dustbin.h"

using namespace std;

int main() {
    /*Garbage garbage("szemét");
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
    PaperGarbage paperGarbage2("papi2");
    paperGarbage2.squeeze();
    paperGarbage2.printName();

    /*
    PlasticGarbage plasticGarbage("mert ez műanyag");
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
        dustbin.throwOutPaperGarbage(paperGarbage2);
    } catch(DustbinContentError &err) {
        cout << err.what();
    }
    return 0;
}