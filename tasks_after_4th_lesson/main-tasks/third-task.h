#ifndef third_task_h
#define third_task_h

#include "../core-file.h"

using namespace std;

namespace mainTasks {

    void getNDisplayDiffTypeValues();

    void getNDisplayDiffTypeValues() {
        int intData = inputValidatorsUtils::getNumericOrCharValidatedInput<int>("| Input int value \t: ");
        programUtils::Print(intData);
        
        double doubleData = inputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input double type value \t: ");
        programUtils::Print(doubleData);

        char charData = inputValidatorsUtils::getNumericOrCharValidatedInput<char>("| Input char type value \t: ");
        programUtils::Print(charData);

        string stringData;
        cout << "| Input string type value \t: ";
        cin.ignore();
        getline(cin, stringData);
        
        programUtils::Print(stringData);
    }
}


#endif