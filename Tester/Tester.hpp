//
// Created by eros on 18/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_TESTER_HPP
#define CPP_WASTE_RECYCLING_DANIELEROS_TESTER_HPP
#include "../Dustbins/Dustbin.h"
#include "../Dustbins/Dustbin9000.h"

class Tester {
public:
    void run()
    {
        failedTests = 0;
        TestCase1();
        TestCase2();
        TestCase3();
        TestCase4();
        TestCase5();
        TestCase6();
        TestCase7();
        TestCase8();
        TestCase9();
        TestCase10();
        TestCase11();
        evaluateTestOutcomes();
    }

private:
    int failedTests;

    void TestCase1() {
        // throw out "general garbage" in the Dustbin
        Dustbin dustbin("green");
        Garbage garbage("general garbage");
        string expectedResult = "general garbage was thrown into the house waste container of dustbin.";
        string actualResult = dustbin.tryToThrowOut(garbage);
        checkResult(expectedResult, actualResult);
    }

    void TestCase2() {
        // try to throw out unnamed garbage
        Dustbin dustbin("green");
        Garbage garbage;
        string expectedResult = "This garbage cannot be put in the dustbin in this form!";
        string actualResult = dustbin.tryToThrowOut(garbage);
        checkResult(expectedResult, actualResult);
    }

    void TestCase3() {
        // throw out squeezed paper
        Dustbin dustbin("green");
        PaperGarbage paperGarbage("paper garbage");
        paperGarbage.squeeze();
        string expectedResult = "paper garbage was thrown into the paper container of dustbin.";
        string actualResult = dustbin.tryToThrowOutPaper(paperGarbage);
        checkResult(expectedResult, actualResult);
    }

    void TestCase4() {
        // try to throw out not squeezed paper
        Dustbin dustbin("green");
        PaperGarbage paperGarbage("paper garbage");
        string expectedResult = "This garbage cannot be put in the dustbin in this form!";
        string actualResult = dustbin.tryToThrowOutPaper(paperGarbage);
        checkResult(expectedResult, actualResult);
    }

    void TestCase5() {
        // throw out clean plastic
        Dustbin dustbin("green");
        PlasticGarbage plasticGarbage("plastic garbage");
        plasticGarbage.clean();
        string expectedResult = "plastic garbage was thrown into the plastic container of dustbin.";
        string actualResult = dustbin.tryToThrowOutPlastic(plasticGarbage);
        checkResult(expectedResult, actualResult);
    }

    void TestCase6() {
        // try to throw out unclean plastic
        Dustbin dustbin("green");
        PlasticGarbage plasticGarbage("plastic garbage");
        string expectedResult = "This garbage cannot be put in the dustbin in this form!";
        string actualResult = dustbin.tryToThrowOutPlastic(plasticGarbage);
        checkResult(expectedResult, actualResult);
    }

    void TestCase7() {
        // throw out metal
        Dustbin9000 dustbin9000("green");
        MetalGarbage metalGarbage("metal garbage");
        string expectedResult = "metal garbage was thrown into the metal container of dustbin.";
        string actualResult = dustbin9000.tryToThrowOutMetal(metalGarbage);
        checkResult(expectedResult, actualResult);
    }

    void TestCase8() {
        // try to throw out more metal items than capacity (2)
        Dustbin9000 dustbin9000("green");
        MetalGarbage metalGarbage("metal garbage");
        MetalGarbage metalGarbage2("metal garbage2");
        MetalGarbage metalGarbage3("metal garbage3");
        string expectedResult = "metal garbage was thrown into the metal container of dustbin. "
                                "metal garbage2 was thrown into the metal container of dustbin. "
                                "The dustbin is full!";
        string actualResult = dustbin9000.tryToThrowOutMetal(metalGarbage)  + " ";
        actualResult += dustbin9000.tryToThrowOutMetal(metalGarbage2) + " ";
        actualResult += dustbin9000.tryToThrowOutMetal(metalGarbage3);
        checkResult(expectedResult, actualResult);
    }

    void TestCase9() {
        // throw out maximum number of metal, then empty dustbin, then throw other metal
        Dustbin9000 dustbin9000("green");
        MetalGarbage metalGarbage("metal garbage");
        MetalGarbage metalGarbage2("metal garbage2");
        MetalGarbage metalGarbage3("metal garbage3");
        string expectedResult = "metal garbage was thrown into the metal container of dustbin. "
                                "metal garbage2 was thrown into the metal container of dustbin. "
                                "The dustbin was successfully emptied! "
                                "metal garbage3 was thrown into the metal container of dustbin.";
        string actualResult = dustbin9000.tryToThrowOutMetal(metalGarbage)  + " ";
        actualResult += dustbin9000.tryToThrowOutMetal(metalGarbage2) + " ";
        actualResult += dustbin9000.emptyContents() + " ";
        actualResult += dustbin9000.tryToThrowOutMetal(metalGarbage3);
        checkResult(expectedResult, actualResult);
    }

    void TestCase10() {
        // throw out pink bottle cap
        Dustbin9000 dustbin9000("green");
        BottleCap bottleCap("bottle cap","pink");
        string expectedResult = "bottle cap was thrown into the bottle cap container of dustbin.";
        string actualResult = dustbin9000.tryToThrowOutBottleCap(bottleCap);
        checkResult(expectedResult, actualResult);
    }

    void TestCase11() {
        // throw out !pink bottle cap
        Dustbin9000 dustbin9000("green");
        BottleCap bottleCap("bottle cap2","red");
        string expectedResult = "This bottle cap is not pink and/or do not have a name!";
        string actualResult = dustbin9000.tryToThrowOutBottleCap(bottleCap);
        checkResult(expectedResult, actualResult);
    }

    void checkResult(const string expected, const string actual)
    {
        if( actual == expected) {
            cout << "Test ran OK. Message: " << actual << endl;
        } else {
            cout << "Invalid result! Expected: " << expected << " actual: " << actual << endl;
            ++failedTests;
        }
    }

    void evaluateTestOutcomes(){
        if(0 != failedTests){
            cout << failedTests << " tests failed." << endl;
        } else {
            cout << "All tests passed!" << endl;
        }
    }
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_TESTER_HPP
