#ifndef first_task_h
#define first_task_h

#include "../core-file.h"

using namespace std;

namespace mainTasks {
    
    void getInputAndDisplaySum();

    void getInputAndDisplaySum() {
        int *firstValue = inputValidatorsUtils::getValidatedInputPointed<int>("| Please enter first value |\t: ");
        int *secondValue = inputValidatorsUtils::getValidatedInputPointed<int>("| Please enter second value |\t: ");
        
        programUtils::Print(mathUtils::sum(*firstValue, *secondValue));
    }
} // namespace mainTasks


#endif