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

    void TestCase1() {
        // TODO: refine this to work well; currently it is not good if the program throws an error
        // cout only from here, and not from the dustbin functions
        // write additional tests
        // 1. try to throw out unnamed garbage
        // 2. try to throw out more items than capacity
        // 3. throw out capacity number of garbage, then empty dustbin, then throw other garbage
        // 4. throw out squeezed paper
        // 5. try to throw out unsqueezed paper
        // 6. throw out clean plastic
        // 7. try to throw out unclean plastic
        // 8. throw out metal
        // 9. throw out pin bottle cap
        // 10. throw out !pink bottle cap
        Dustbin dustbin("green");
        Garbage garbage;
        string result;
        try {
            result = dustbin.tryToThrowOut(garbage);
        } catch (exception &err) {
            result = "This garbage cannot be put in the dustbin in this form!";
        }
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
