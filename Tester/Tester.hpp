//
// Created by eros on 18/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_TESTER_HPP
#define CPP_WASTE_RECYCLING_DANIELEROS_TESTER_HPP
//#include "../wasteRecycling.cpp"
#include "../Dustbins/Dustbin.h"

class Tester {
public:
    void run()
    {
        failedTests = 0;
        TestCase1();
        evaluateTestOutcomes();
    }

private:
    int failedTests;

    string tryToThrowOut(Dustbin &dustbin, Garbage &garbage) {
        return dustbin.throwOutGarbage(garbage);
    }

    void TestCase1() {
        Dustbin dustbin("green");
        Garbage garbage("general garbage");
        string result = tryToThrowOut(dustbin, garbage);
        checkResult("general garbage was thrown into the house waste container of dustbin.", result);
    }


    void checkResult(const string expected, const string actual)
    {
        if( actual == expected)
        {
            cout << "Test ran OK." << endl;
        }else{
            cout << "Invalid result! Expected: " << expected << " actual: " << actual << endl;
            ++failedTests;
        }
    }

    void evaluateTestOutcomes()
    {
        if(0 != failedTests){
            cout << failedTests << " tests failed." << endl;
        }else{
            cout << "All tests passed!" << endl;
        }
    }
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_TESTER_HPP
