#ifndef _FIFTH_ADDIT_H
#define _FIFTH_ADDIT_H

#include "../core-file.h"
#include "../utils/main_menu.h"

namespace additionalTasks {

    void displayMiddleEl();
    void displaySortedFifthTask();
    void getUserInputAndApplyFunctions();

    void taskMenuRunnerFifth() {
        MainMenu mainProgram1("5 additional");

        mainProgram1.addItem("Display middle element", &displayMiddleEl);
        mainProgram1.addItem("Display sorted", &displaySortedFifthTask);
        mainProgram1.addItem("Get user input and apply functions", &getUserInputAndApplyFunctions);

        mainProgram1.addItem("Exit", true);

        mainProgram1.runProgram();
    }

    void displayMiddleEl() {
        int numArr[] = { 79, 3, 6, 97, 89, 5, 1, 5, 4, 8, 9, 10, 47, 132, 90, 100, 23, 56, 47};
        const size_t  numArrSize = sizeof(numArr) / sizeof(int);
        programUtils::Print(numArr, numArrSize);

        int *middleEl = statisticsUtils::getMiddleElement<int>(numArr, numArrSize);
        cout << "Middle Element: "<< *middleEl << endl;

        int numArr1[] = { 79, 3, 2};
        const size_t numArr1Size = sizeof(numArr1) / sizeof(int);
        programUtils::Print(numArr1, numArr1Size);

        middleEl = statisticsUtils::getMiddleElement<int>(numArr1, numArr1Size);
        cout << "Middle Element: "<< *middleEl << endl;
    }

    void displaySortedFifthTask() {
        int numArr[] = { 79, 3, 6, 97, 89, 5, 1, 5, 4, 8, 9, 10, 47, 132, 90, 100, 23, 56, 47};
        const size_t numArrSize = sizeof(numArr) / sizeof(int);
        programUtils::Print(numArr, numArrSize);
        arrayUtils::IntArrayModel array1Model = {numArr, numArrSize};

        arrayUtils::displaySorted(array1Model);
    }

    void getUserInputAndApplyFunctions() {
        const size_t *userDataCount = inputValidatorsUtils::getValidatedInputPointed<size_t>("Enter the size of array:");
        int* intArr = (int*) malloc(sizeof(int) * (*userDataCount));

        int id = 0;
        for (int *intArrEl = intArr; intArrEl < intArr + *userDataCount; ++intArrEl) {
            *intArrEl = inputValidatorsUtils::getNumericOrCharValidatedInput<int>("[" + to_string(id) + "]:");
            id++;
        }

        programUtils::Print(intArr, *userDataCount);

        int *middleEl = statisticsUtils::getMiddleElement<int>(intArr, *userDataCount);
        cout << "Middle Element: "<< *middleEl << endl;

        arrayUtils::IntArrayModel array1Model = {intArr, *userDataCount};
        arrayUtils::displaySorted(array1Model);
    }
}

#endif