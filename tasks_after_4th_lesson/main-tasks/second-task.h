#ifndef second_task_h
#define second_task_h

#include "../core-file.h"
#include "../utils/math_utils.h"

using namespace std;

namespace mainTasks {

    void displayNumSumInRecursion();
    int countNumbersSumRecursive(int n);

    void displayNumSumInRecursion() {
        int n = inputValidatorsUtils::getNumericOrCharValidatedInput<int>();
        programUtils::Print(MathUtils::countNumbersSumRecursive(n));
    }

}

#endif