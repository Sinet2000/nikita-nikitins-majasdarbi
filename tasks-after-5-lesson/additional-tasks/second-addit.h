#ifndef _SECOND_ADDIT_H
#define _SECOND_ADDIT_H

#include "../core-file.h"
#include "../utils/main_menu.h"

namespace additionalTasks {

    void testFindDataInArr();
    void testDisplayDistinctArrValues();
    void testCorrectNmbrsOrder();

    void taskMenuRunnerSecond() {
        MainMenu mainProgram1("2 additional");

        mainProgram1.addItem("2.1 Find data in Arr", &testFindDataInArr);
        mainProgram1.addItem("2.2 Dispaly Distinct Values", &testDisplayDistinctArrValues);
        mainProgram1.addItem("2.3 Check numbers consistency", &testCorrectNmbrsOrder);

        mainProgram1.addItem("Exit", true);

        mainProgram1.runProgram();
    }

    void testFindDataInArr() {
        int numArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        const int numArrSize = sizeof(numArr) / sizeof(int);
        programUtils::Print(numArr, numArrSize);
        int *valueToFind = inputValidatorsUtils::getValidatedInputPointed<int>("| Please enter value to find |\t: ");
    
        arrayUtils::FindResult findRes1= arrayUtils::findInArray(numArr, numArrSize, *valueToFind);
        cout << "\nSearch Result: " << (findRes1.found ? "Found =>" : "Not Found!") <<  (findRes1.found ? to_string(findRes1.index) : " ") << endl;
        delete(valueToFind);

        int numArr2[] = { 1, 4, 5, 8, 9, 26, 13, 15};
        const int numArr2Size = sizeof(numArr2) / sizeof(int);
        programUtils::Print(numArr2, numArr2Size);
        int *valueToFind1 = inputValidatorsUtils::getValidatedInputPointed<int>("| Please enter value to find |\t: ");

        arrayUtils::FindResult findRes2 = arrayUtils::findInArray(numArr2, numArr2Size, *valueToFind1);
        cout << "\nSearch Result: " << (findRes2.found ? "Found =>" : "Not Found!") <<  (findRes2.found ? to_string(findRes2.index) : " ") << endl;
        delete(valueToFind1);
    }

    void testDisplayDistinctArrValues() {
        int numArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        const int numArrSize = sizeof(numArr) / sizeof(int);
        programUtils::Print(numArr, numArrSize);

        int numArr2[] = { 1, 4, 5, 8, 9, 26, 13, 15};
        const int numArr2Size = sizeof(numArr2) / sizeof(int);
        programUtils::Print(numArr2, numArr2Size);

        arrayUtils::IntArrayModel array1Model = {numArr, numArrSize};
        arrayUtils::IntArrayModel array2Model = {numArr2, numArr2Size};

        arrayUtils::displayDistinctInTwo(array1Model, array2Model);
    }

    void testCorrectNmbrsOrder() {
        int numArr[] = { 1, 2, 3, 4, 5, 7, 9};
        const int numArrSize = sizeof(numArr) / sizeof(int);
        programUtils::Print(numArr, numArrSize);
        arrayUtils::IntArrayModel array1Model = {numArr, numArrSize};
        arrayUtils::checkArrayConsistency(array1Model);

        int numArr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
        const int numArr2Size = sizeof(numArr2) / sizeof(int);
        programUtils::Print(numArr2, numArr2Size);
        arrayUtils::IntArrayModel array2Model = {numArr2, numArr2Size};
        arrayUtils::checkArrayConsistency(array2Model);
    }

}

#endif