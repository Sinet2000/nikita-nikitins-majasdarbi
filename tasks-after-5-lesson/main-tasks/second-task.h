#ifndef second_task_h
#define second_task_h

#include "../core-file.h"

using namespace std;

namespace mainTasks {
    void findNumInData();

    void findNumInData() {
        int numArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        const int numArrSize = sizeof(numArr) / sizeof(int);

        programUtils::Print(numArr, numArrSize);
        int *valueToFind = inputValidatorsUtils::getValidatedInputPointed<int>("| Please enter value to find |\t: ");
        
        arrayUtils::FindResult findRes1= arrayUtils::findInArray(numArr, numArrSize, *valueToFind);
        programUtils::Print(findRes1.found ? "Found" : "Not Found");
    }
} // namespace mainTasks


#endif