#ifndef fourth_task_h
#define fourth_task_h

#include "../core-file.h"

using namespace std;

namespace mainTasks {
    void reverseDisplayNumArr();

    void reverseDisplayNumArr() {
        int numArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        const int numArrSize = sizeof(numArr) / sizeof(int);

        programUtils::Print(numArr, numArrSize);
        arrayUtils::displayReversed(numArr, numArrSize);
    }
    
} // namespace mainTasks


#endif