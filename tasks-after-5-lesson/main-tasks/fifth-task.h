#ifndef fifth_task_h
#define fifth_task_h

#include "../core-file.h"

using namespace std;

namespace mainTasks {
    void findAndDisplayMinInIntArr();

    void findAndDisplayMinInIntArr() {
        const int numArrSize = 10;
        int numArr[numArrSize];

        srand(time(NULL));
        for (int i =0; i<numArrSize; i ++) {
            int rNumber = rand()%100;
            numArr[i] = rNumber;
        }

        programUtils::Print(numArr, numArrSize);
        
        int *minValue = arrayUtils::minElement(numArr, sizeof(numArr) / sizeof(int));
        cout << "\nMin value address: " << &minValue << endl;
        cout << "\nMin value: " << *minValue << endl;
    }
    
} // namespace mainTasks


#endif