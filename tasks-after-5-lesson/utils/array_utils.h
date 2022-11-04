#ifndef array_utils_h
#define array_utils_h

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace arrayUtils {

    int findIdx(int *dataArr, int arrCount, int &elementTofind);
    void displayReversed(int *data, int size);
    int *minElement(int *arr, int arrSize);

    int findIdx(int *dataArr, int arrCount, int &elementTofind) {

        int i = 0;

        for (int *p = dataArr; p < dataArr + arrCount; ++p) {
            if(*p == elementTofind)
                return i;

            i++;
        }

        return 0;
    }

    void displayReversed(int *data, int size) {
        cout << "\nReversed: ";
        for (int *p = data + size - 1; p >= data; --p) {
            cout << *p << " ";
        }

        cout << endl;
    }

    int *minElement(int *arr, int arrSize) {
        int *minValue = arr;
        
        for (int *p = arr; p < arr + arrSize; ++p) {
            if(*p < *minValue)
                *minValue = *p;
        }

        return minValue;
    }
}


#endif