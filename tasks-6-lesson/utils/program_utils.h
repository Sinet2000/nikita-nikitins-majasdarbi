#include "input_validators.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace programUtils
{
    int *getUserInputToIntArray(const size_t &maxElementsInArray) {
        int* intArr = (int*) malloc(sizeof(int) * (maxElementsInArray));

        int id = 0;
        for (int *intArrEl = intArr; intArrEl < intArr + maxElementsInArray; ++intArrEl) {
            *intArrEl = inputValidatorsUtils::getNumericOrCharValidatedInput<int>("[" + to_string(id) + "]:");
            id++;
        }

        return intArr;
    }

    void printVector(std::vector<char> vectorData, bool addSpace = false) {
        for (std::vector<char>::iterator it = vectorData.begin(); it != vectorData.end(); ++it) {
            cout << *it<< (addSpace ? " " : "");
        }
    }

    template<typename T>
    void remove(std::vector<T> &v, const T &target)
    {
        v.erase(std::remove(v.begin(), v.end(), target), v.end());
    }

    template<typename T>
    T *vectorToArr(std::vector<T> &v, const size_t &length)
    {
        T *arr = (T*) malloc(sizeof(T) * (length));
        transform(v.begin(), v.end(), arr,[](const T & elem){return elem;});
        return arr;
    }

    const vector<string> &getReservedFileNames() {
        const vector<string> reservedFileNames = {"file-5uzd.bin", "file-task1.txt", "file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
        return reservedFileNames;
    }
    
} // namespace programUtils
