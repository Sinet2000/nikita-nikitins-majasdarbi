#ifndef array_utils_h
#define array_utils_h

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace arrayUtils {

struct FindResult {
    bool found = false;
    int index = -1;
};

struct IntArrayModel {
    int *arr;
    const size_t size;
};

void displayReversed(int *data, int size);
int *minElement(int *arr, int arrSize);
void bubbleSort(int *data, int size);
bool containsDuplicate(int *data, int size);
FindResult findInArray(int *data, int size, int toFind);
void displayDistinctInTwo(IntArrayModel &arrModel1, IntArrayModel &arrModel2);
bool checkArrayConsistency(IntArrayModel &arrModel1);
void displayPrimes(IntArrayModel &arrModel1);
void displaySorted(IntArrayModel &arrModel1);

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
        if (*p < *minValue) *minValue = *p;
    }

    return minValue;
}

void bubbleSort(int *data, int size) {
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        
        for (int i = 0; i < size - 1; i++) {
            if (*(data + i) > *(data + i + 1)) {
                programUtils::swap((data + i), (data + i + 1));
                sorted = false;
            }
        }
    }
}

bool containsDuplicate(int *data, int size) {
    bool containsDuplicate = false;

    arrayUtils::bubbleSort(data, size);

    for (int i = 0; i < size - 1; i++) {
        if (*(data + i) == *(data + i + 1)) {
            return true;
        }
    }

    return false;
}

FindResult findInArray(int *data, int size, int toFind) {
    arrayUtils::FindResult findResult;

    for (int i = 0; i < size - 1; i++) {
        if (*(data + i) == toFind) {
            findResult.index = i;
            findResult.found = true;
            break;
        }
    }

    return findResult;
}

void displayDistinctInTwo(IntArrayModel &arrModel1, IntArrayModel &arrModel2) {
    set<int> distinctDataSet;

    for (int *arr1El = arrModel1.arr; arr1El < arrModel1.arr + arrModel1.size;
         ++arr1El) {
        distinctDataSet.insert(*arr1El);
    }

    for (int *arr2El = arrModel2.arr; arr2El < arrModel2.arr + arrModel2.size;
         ++arr2El) {
        distinctDataSet.insert(*arr2El);
    }

    cout << "\nDistinct Values from two: ";
    for (auto &setEl : distinctDataSet) {
        std::cout << setEl << ' ';
    }
    cout << endl;
}

bool checkArrayConsistency(IntArrayModel &arrModel1) {
    if (*arrModel1.arr != 1) {
        cout << "\nFirst number must be 1!" << endl;
        return false;
    }

    for (int *arr1El = arrModel1.arr; arr1El < arrModel1.arr + arrModel1.size; ++arr1El) {

        if (*arr1El != *(arr1El + 1) - 1 && arr1El != arrModel1.arr + arrModel1.size - 1) {

            cout << "\nIncorrect sequence! After (" << *arr1El << ") must be("
                 << *arr1El + 1 << "), but (" << *(arr1El + 1) << ")found"
                 << endl;
            return false;
        }
    }

    cout << "\nSequence is correct!" << endl;
    return true;
}

void displayPrimes(IntArrayModel &arrModel1) {
    cout << "\nPrime Numbers: ";
    for (int *arr1El = arrModel1.arr; arr1El < arrModel1.arr + arrModel1.size; ++arr1El) {
        
        if (mathUtils::isPrimeNumber(*arr1El))
            cout << *arr1El << " ";
    }

    cout << endl;
}

void displaySorted(IntArrayModel &arrModel1) {
    cout << "\nSorted: ";
    int *intArrNew = (int*)malloc(arrModel1.size);
    
    for (int i = 0; i < arrModel1.size; i++) {
        *(intArrNew + i) = *(arrModel1.arr + i);
    }

    arrayUtils::bubbleSort(intArrNew, arrModel1.size);

    for (int *intArrNewEl = intArrNew; intArrNewEl < intArrNew + arrModel1.size ; ++intArrNewEl) {

        cout << *intArrNewEl << " ";
    }

    cout << endl;
}

void displayEverySecondIntInArr(IntArrayModel &arrModel1) {
    cout << "\nEvery Second: ";

    if (arrModel1.size <= 1)
        return;

    for (int *intArrNewEl = arrModel1.arr + 1; intArrNewEl < arrModel1.arr + arrModel1.size - 1; intArrNewEl+=2) {

        cout << *intArrNewEl << " ";
    }

    cout << endl;
}

// void getDistictValuesFromArr(vector<int*> &distictValues, IntArrayModel
// &arrModel) {
//     for (int *p = arrModel.arr; p < arrModel.arr + arrModel.size; ++p) {
//         if (std::find(distictValues.begin(), distictValues.end(), *p) !=
//         distictValues.end()) {
//             distictValues.push_back(p);
//         }
//     }
// }
}  // namespace arrayUtils

#endif