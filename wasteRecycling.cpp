#include <iostream>
#include "Garbages/Garbage.h"
#include "Garbages/PaperGarbage.h"
#include "Garbages/PlasticGarbage.h"
#include "Dustbins/Dustbin.h"
#include "Dustbins/Dustbin9000.h"
#include "Garbages/MetalGarbage.h"
#include "Garbages/BottleCap.h"
#include "Tester/Tester.hpp"

using namespace std;

int main() {
    Tester tester;
    tester.run();
//    Garbage garbage("szemét");
//    /*
//    garbage.printName();
//    garbage.setName("ggg");
//    garbage.printName();
//    PaperGarbage paperGarbage;
//    paperGarbage.setName("papírszemét");
//    paperGarbage.printName();
//    cout << paperGarbage.getIsSqueezed() << endl;
//    paperGarbage.squeeze();
//    cout << paperGarbage.getIsSqueezed() << endl;
//    */
//    PaperGarbage paperGarbage("papír");
//    PaperGarbage paperGarbage2("papír2");
//    paperGarbage2.squeeze();
//    //paperGarbage2.printName();
//
//
//    PlasticGarbage plasticGarbage("mert ez műanyag");
//    plasticGarbage.clean();
//    PlasticGarbage plasticGarbage2("műanyag2");
//    plasticGarbage2.clean();
//    PlasticGarbage plasticGarbage3("műanyag3");
//    plasticGarbage3.clean();
//    MetalGarbage metalGarbage("fémkosz");
//    //cout << metalGarbage.getName() << endl;
//    /*
//    plasticGarbage.printName();
//    cout << plasticGarbage.getIsClean() << endl;
//    plasticGarbage.clean();
//    cout << plasticGarbage.getIsClean() << endl;
//    */
//
//    Dustbin dustbin("green");
//    Dustbin9000 dustbin9000("red");
//    cout << dustbin9000.getColor() << endl;
//    //dustbin9000.throwOutGarbage(garbage);
//
//    //cout << dustbin.getColor() << endl;
//    //dustbin.paperContent[0] = paperGarbage;
//    //cout << dustbin.paperContent[0].getName();
//    BottleCap bottleCap("első_kupak", "pink");
//    BottleCap bottleCap2("második_kupak", "kék");
//    cout << bottleCap.getName() << ": " << bottleCap.getColor() << endl;
//    try {
//        //dustbin.emptyContents();
//        dustbin9000.throwOutBottleCap(bottleCap);
//        dustbin9000.throwOutBottleCap(bottleCap);
//        dustbin9000.emptyContents();
//        dustbin9000.throwOutMetalGarbage(metalGarbage);
//        //dustbin9000.throwOutMetalGarbage(metalGarbage);
//        //dustbin9000.throwOutMetalGarbage(metalGarbage);
//        dustbin9000.throwOutGarbage(garbage);
//        dustbin9000.throwOutPaperGarbage(paperGarbage2);
//        dustbin9000.throwOutPlasticGarbage(plasticGarbage);
//        dustbin9000.throwOutPlasticGarbage(plasticGarbage2);
//        //dustbin.throwOutPlasticGarbage(plasticGarbage3);
//        dustbin9000.emptyContents();
//        dustbin9000.throwOutPlasticGarbage(plasticGarbage);
//        dustbin9000.throwOutPlasticGarbage(plasticGarbage2);
//        dustbin9000.throwOutPlasticGarbage(plasticGarbage3);
//    } catch(exception &err) {
//        cout << err.what();
//    }
    return 0;
}