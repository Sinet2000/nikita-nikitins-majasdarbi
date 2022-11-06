#ifndef _FOURTH_ADDIT_H
#define _FOURTH_ADDIT_H

#include "../core-file.h"
#include "../utils/main_menu.h"

namespace additionalTasks {

    void displayPrimeNumbers();
    void displaySorted();
    void displayEverySecond();
    void combinedFourthTaskFunc();

    void taskMenuRunnerFourth() {
        MainMenu mainProgram1("4 additional");

        mainProgram1.addItem("Display prime numbers", &displayPrimeNumbers);
        mainProgram1.addItem("Display sorted", &displaySorted);
        mainProgram1.addItem("Display every second", &displayEverySecond);
        mainProgram1.addItem("Combined", &combinedFourthTaskFunc);

        mainProgram1.addItem("Exit", true);

        mainProgram1.runProgram();
    }

    void displayPrimeNumbers() {
        int numArr[] = { 79, 3, 6, 97, 89, 5, 1, 5, 4, 8, 9, 10, 47, 132, 90, 100, 23, 56, 47};
        const size_t  numArrSize = sizeof(numArr) / sizeof(int);
        programUtils::Print(numArr, numArrSize);
        arrayUtils::IntArrayModel array1Model = {numArr, numArrSize};

        arrayUtils::displayPrimes(array1Model);
    }

    void displaySorted() {
        int numArr[] = { 79, 3, 6, 97, 89, 5, 1, 5, 4, 8, 9, 10, 47, 132, 90, 100, 23, 56, 47};
        const size_t  numArrSize = sizeof(numArr) / sizeof(int);
        programUtils::Print(numArr, numArrSize);
        arrayUtils::IntArrayModel array1Model = {numArr, numArrSize};

        arrayUtils::displaySorted(array1Model);
    }

    void displayEverySecond() {
        int numArr[] = { 79, 3, 6, 97, 89, 5, 1, 5, 4, 8, 9, 10, 47, 132, 90, 100, 23, 56, 47};
        const size_t numArrSize = sizeof(numArr) / sizeof(int);
        programUtils::Print(numArr, numArrSize);
        arrayUtils::IntArrayModel array1Model = {numArr, numArrSize};

        arrayUtils::displayEverySecondIntInArr(array1Model);
    }

    void combinedFourthTaskFunc() {
        int numArr[] = { 79, 3, 6, 97, 89, 5, 1, 5, 4, 8, 9, 10, 47, 132, 90, 100, 23, 56, 47};
        const size_t  numArrSize = sizeof(numArr) / sizeof(int);
        programUtils::Print(numArr, numArrSize);
        arrayUtils::IntArrayModel array1Model = {numArr, numArrSize};

        arrayUtils::displayPrimes(array1Model);
        arrayUtils::displaySorted(array1Model);
        arrayUtils::displayEverySecondIntInArr(array1Model);
    }
}

#endif