#include <iostream>
#include "Garbages/Garbage.h"
#include "Garbages/PaperGarbage.h"
using namespace std;

int main() {
    Garbage garbage("szemét");
    garbage.printName();
    garbage.setName("ggg");
    garbage.printName();
    PaperGarbage paperGarbage;
    paperGarbage.setName("papírszemét");
    paperGarbage.printName();
    cout << paperGarbage.getIsSqueezed() << endl;
    paperGarbage.squeeze();
    cout << paperGarbage.getIsSqueezed() << endl;
    PaperGarbage paperGarbage2("papi2");
    paperGarbage2.printName();
    return 0;
}