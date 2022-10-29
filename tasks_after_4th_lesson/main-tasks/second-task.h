#ifndef second_task_h
#define second_task_h

#include "../core-file.h"

using namespace std;

namespace mainTasks {

    void displayNumSumInRecursion();
    int countNumbersSumRecursive(int n);

    void displayNumSumInRecursion() {
        int n = inputValidatorsUtils::getNumericOrCharValidatedInput<int>();
        programUtils::Print(countNumbersSumRecursive(n));
    }

    int countNumbersSumRecursive(int n) {
        if (n == 0) return 0;
        
        return n + countNumbersSumRecursive(n-1);
    }

}

#endif