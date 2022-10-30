#ifndef second_addit_h
#define second_addit_h
#define MAX_TXT_LENGTH 255
#include "../core-file.h"
#include "../utils/main_menu.h"
#include "../utils/math_utils.h"

namespace additionalTasks {

// main chunks
void getInputToInt(int &txtData);
void displaySumOfDigitsOfInt(int &intData);
void displayCountfDigitsOfInt(int &intData);
void displayNumSumInRecursion(int &intData);

void taskMenuRunnerSecond() {
    int _intDataMain;

    MainMenu mainProgram1("2 additional");
    
    mainProgram1.addItem("Enter integer", &additionalTasks::getInputToInt, _intDataMain);
    mainProgram1.addItem("Sum", &additionalTasks::displayNumSumInRecursion, _intDataMain);
    mainProgram1.addItem("Sum of digits", &additionalTasks::displaySumOfDigitsOfInt, _intDataMain);
    mainProgram1.addItem("Count of digits", &additionalTasks::displayCountfDigitsOfInt, _intDataMain);

    mainProgram1.addItem("Exit", true);

    mainProgram1.runProgram();
}

void getInputToInt(int &intData) {
    intData = inputValidatorsUtils::getNumericOrCharValidatedInput<int>("| Enter Int Value \t: ");
}

void displaySumOfDigitsOfInt(int &intData) {
    int sum = MathUtils::getSumOfDigitsOfInt(intData);
    programUtils::Print(sum);
}

void displayCountfDigitsOfInt(int &intData) {
    int count = MathUtils::getCountOfDigitsInInt(intData);
    programUtils::Print(count);
}

void displayNumSumInRecursion(int &intData) {
    programUtils::Print(MathUtils::countNumbersSumRecursive(intData));
}


}  // namespace additionalTasks

#endif