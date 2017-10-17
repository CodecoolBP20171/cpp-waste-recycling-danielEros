#include <iostream>
#include "Garbages/Garbage.h"
using namespace std;

int main() {
    Garbage garbage("szemét");
    garbage.printName();
    garbage.setName("ggg");
    garbage.printName();
    return 0;
}