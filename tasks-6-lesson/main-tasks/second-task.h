#ifndef second_task_h
#define second_task_h

#include "../core-file.h"
#include <cstdio>

using namespace std;

namespace mainTasks {

    void manageIntArrayToFiles() {
        const size_t maxElementsInArray = 10;

        int* intArr = inputValidatorsUtils::getBoolInput("\nDo you want to use the predifined array (y) or create on your own(n)?") 
            ? new int[maxElementsInArray] {3, 5, 7, 4, 8, 6, 11, 17, 9}
            : programUtils::getUserInputToIntArray(maxElementsInArray);

        const char oddIntStorageFileName[] = "file1.txt";
        const char evenIntStorageFileName[] = "file2.txt";
        const char primeIntStorageFileName[] = "file3.txt";

        if(remove(oddIntStorageFileName) != 0 && remove(evenIntStorageFileName) != 0 && remove(primeIntStorageFileName) != 0 ) {
            for (int *intArllEl = intArr; intArllEl < intArr + maxElementsInArray ; ++intArllEl) {

                if (mathUtils::isPrimeNumber(*intArllEl))
                    fileUtils::appendToFile<int>(primeIntStorageFileName, *intArllEl);

                if (mathUtils::isOdd(*intArllEl))
                    fileUtils::appendToFile<int>(oddIntStorageFileName, *intArllEl);

                if (mathUtils::isEven(*intArllEl))
                    fileUtils::appendToFile<int>(evenIntStorageFileName, *intArllEl);
            }
        } else {
            cout << "\nAn error occurred while removing files" <<endl;
        }
    }

} // namespace mainTasks


#endif