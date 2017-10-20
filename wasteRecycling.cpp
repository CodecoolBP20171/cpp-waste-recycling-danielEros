#include <iostream>
#include "Tester/Tester.hpp"
#include "UserInterface/UserInterface.hpp"

using namespace std;

int main() {
    cout << "Performing dustbin tests..." << endl;
    Tester tester;
    tester.run();
    cout << endl << "Hello, I am the User Interface of the Dustbins! I am here to help you :)" << endl;
    UserInterface UI;
    UI.run();
    return 0;
}