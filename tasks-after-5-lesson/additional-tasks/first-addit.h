#ifndef _FIRST_ADDIT_H
#define _FIRST_ADDIT_H

#include "../core-file.h"
#include "../utils/main_menu.h"

namespace additionalTasks {

    void testSwapFunction();
    void dispayMinAndMaxValue();
    void checkOnDuplicate();

    void taskMenuRunnerFirst() {
        MainMenu mainProgram1("1 additional");

        mainProgram1.addItem("Swap test", &testSwapFunction);
        mainProgram1.addItem("Min/Max", &dispayMinAndMaxValue);
        mainProgram1.addItem("Check duplicate", &checkOnDuplicate);

        mainProgram1.addItem("Exit", true);

        mainProgram1.runProgram();
    }

    void testSwapFunction() {
        int numArr[] = { 1, 4, 5, 8, 9, 26, 7, 8, 19, 0};
        const int numArrSize = sizeof(numArr) / sizeof(int);

        programUtils::Print(numArr, numArrSize);
        arrayUtils::bubbleSort(numArr, numArrSize);
        programUtils::Print(numArr, numArrSize);
    }

    void dispayMinAndMaxValue() {
        vector<int*> inputValuesVector;
        inputValuesVector.push_back(inputValidatorsUtils::getValidatedInputPointed<int>("| Please enter frst value |\t: "));
        inputValuesVector.push_back(inputValidatorsUtils::getValidatedInputPointed<int>("| Please enter second value |\t: "));
        inputValuesVector.push_back(inputValidatorsUtils::getValidatedInputPointed<int>("| Please enter third value |\t: "));

        mathUtils::MinAndMaxValue<int> maxAndMinValue = mathUtils::getMinAndMax<int>(inputValuesVector);
        printf("\nMinimum value: %d", *maxAndMinValue.minValue);
        printf("\nMax value: %d", *maxAndMinValue.maxValue);
    }

    void checkOnDuplicate() {
        int numArr1[] = { 1, 4, 5, 8, 9, 26, 7, 8, 19, 0, 13, 4, 11};
        const int numArr1Size = sizeof(numArr1) / sizeof(int);
        programUtils::Print(numArr1, numArr1Size);
        bool containsDuplicate = arrayUtils::containsDuplicate(numArr1, numArr1Size);
        cout << "Contains duplicate: " << (containsDuplicate ? "Yes" : "No") << endl;

        int numArr2[] = { 1, 4, 5, 8, 9, 26, 13, 15};
        const int numArr2Size = sizeof(numArr2) / sizeof(int);
        programUtils::Print(numArr2, numArr2Size);
        containsDuplicate = arrayUtils::containsDuplicate(numArr2, numArr2Size);
        cout << "Contains duplicate: " << (containsDuplicate ? "Yes" : "No") << endl;
    }
}

#endif