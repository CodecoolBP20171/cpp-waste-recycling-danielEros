//
// Created by eros on 20/10/17.
//

#ifndef CPP_WASTE_RECYCLING_DANIELEROS_USERINTERFACE_HPP
#define CPP_WASTE_RECYCLING_DANIELEROS_USERINTERFACE_HPP

#include "../Dustbins/Dustbin.h"
#include "../Dustbins/Dustbin9000.h"

class UserInterface {
public:
    void run() {
        cout << "Press 'q' any time to exit the program!" << endl;
        string dustbinType = getDustbinTypeFromUser();
        if (dustbinType == "q") {
            exitProgram();
        }
        string dustbinColor = getColorFromUser("dustbin");
        if (dustbinColor == "q") {
            exitProgram();
        }
        Dustbin dustbin(dustbinColor);
        Dustbin9000 dustbin9000(dustbinColor);
        while (true) {
            string garbageType;
            if (dustbinType == "Dustbin") {
                garbageType = getGarbageTypeFromUserForDustbin();
            } else if (dustbinType == "Dustbin9000") {
                garbageType = getGarbageTypeFromUserForDustbin9000();
            }
            string doSomethingWithTheGarbage;
            string bottleCapColor;
            if (garbageType == "q") {
                exitProgram();
                break;
            } else if(garbageType == "paper") {
                doSomethingWithTheGarbage = getBooleanInfoFromUser("paper");
            } else if(garbageType == "plastic") {
                doSomethingWithTheGarbage = getBooleanInfoFromUser("plastic");
            } else if(garbageType == "bottle cap") {
                bottleCapColor = getColorFromUser("bottle cap");
                if (bottleCapColor == "q") {
                    exitProgram();
                    break;
                }
            }
            cout << "Thank you, I have all neccesary input, here are the results: " << endl;
            if(dustbinType == "Dustbin"){
                processDustbin(dustbin, garbageType, doSomethingWithTheGarbage);
            } else if(dustbinType == "Dustbin9000") {
                processDustbin9000(dustbin9000, garbageType, doSomethingWithTheGarbage, bottleCapColor);
            }
        }
    }

private:
    string getDustbinTypeFromUser() {
        string dustbinType;
        do {
            cout << "Select dustbin type (Dustbin or Dustbin9000): " << endl;
            getline(cin, dustbinType);
        } while(dustbinType != "Dustbin" && dustbinType != "Dustbin9000" && dustbinType != "q");
        return dustbinType;
    }

    string getGarbageTypeFromUserForDustbin() {
        string garbageType;
        do {
            cout << "Select garbage type (house waste, paper or plastic): " << endl;
            getline(cin, garbageType);
        } while(garbageType != "house waste" && garbageType != "paper" && garbageType != "q"
             && garbageType != "plastic");
        return garbageType;
    }

    string getGarbageTypeFromUserForDustbin9000() {
        string garbageType;
        do {
            cout << "Select garbage type (house waste, paper, plastic, metal or bottle cap): " << endl;
            getline (cin, garbageType);
        } while(garbageType != "house waste" && garbageType != "paper" && garbageType != "q"
                && garbageType != "plastic" && garbageType != "metal" && garbageType != "bottle cap");
        return garbageType;
    }

    string getColorFromUser(const string &object) {
        string color;
        cout << "Specify the color of your " << object << ": " << endl;
        getline(cin, color);
        return color;
    }

    void exitProgram() {
        cout << "Exiting program, good-bye!" << endl;
    }

    string getBooleanInfoFromUser(const string &objectToManipulate) {
        string result;
        string operation;
        if(objectToManipulate == "paper"){
            operation = "squeeze";
        } else if(objectToManipulate == "plastic"){
            operation = "clean";
        } else if(objectToManipulate == "dustbin"){
            operation = "empty";
        }
        do {
            cout << "Do you want to " << operation << " the " << objectToManipulate << "? " << endl;
            getline(cin, result);
        } while(result != "yes" && result !="no");
        return result;
    }

    void processDustbin(Dustbin &dustbin, const string &garbageType,
                        const string &doSomethingWithTheGarbage) {
        string dustbinMessage = "";
        if(garbageType == "house waste") {
            Garbage garbage(garbageType);
            dustbinMessage = dustbin.tryToThrowOut(garbage);
            cout << dustbinMessage << endl << endl;
        } else if(garbageType == "paper"){
            PaperGarbage paperGarbage(garbageType);
            if(doSomethingWithTheGarbage == "yes"){
                paperGarbage.squeeze();
            }
            dustbinMessage = dustbin.tryToThrowOutPaper(paperGarbage);
            cout << dustbinMessage << endl << endl;
        } else if(garbageType == "plastic"){
            PlasticGarbage plasticGarbage(garbageType);
            if(doSomethingWithTheGarbage == "yes"){
                plasticGarbage.clean();
            }
            dustbinMessage = dustbin.tryToThrowOutPlastic(plasticGarbage);
            cout << dustbinMessage << endl << endl;
        }
        if(dustbinMessage == "The dustbin is full!"){
            string userAnswerAboutEmptyTheDustbin = getBooleanInfoFromUser("dustbin");
            if(userAnswerAboutEmptyTheDustbin == "yes"){
                cout << dustbin.emptyContents() << endl;
            }
        }
    }

    void processDustbin9000(Dustbin9000 &dustbin, const string &garbageType,
                        const string &doSomethingWithTheGarbage, const string bottlecapColor) {
        string dustbinMessage = "";
        if(garbageType == "house waste" || garbageType == "paper" || garbageType == "plastic") {
            processDustbin(dustbin, garbageType, doSomethingWithTheGarbage);
        } else if(garbageType == "metal") {
            MetalGarbage metalGarbage(garbageType);
            dustbinMessage = dustbin.tryToThrowOutMetal(metalGarbage);
            cout << dustbinMessage << endl << endl;
        } else if(garbageType == "bottle cap") {
            BottleCap bottleCap(garbageType, bottlecapColor);
            dustbinMessage = dustbin.tryToThrowOutBottleCap(bottleCap);
            cout << dustbinMessage << endl << endl;
        }
        if(dustbinMessage == "The dustbin is full!"){
            string userAnswerAboutEmptyTheDustbin = getBooleanInfoFromUser("dustbin");
            if(userAnswerAboutEmptyTheDustbin == "yes"){
                cout << dustbin.emptyContents() << endl;
            }
        }
    }
};


#endif //CPP_WASTE_RECYCLING_DANIELEROS_USERINTERFACE_HPP
