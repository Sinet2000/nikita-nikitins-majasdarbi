#include <iostream>
#include <string>
#include <cstdio>
#include <type_traits>

#include "utils/main_menu.h"
#include "utils/program_utils.h"
#include "utils/input_validators.h"

using namespace std;

namespace calculatorUtils {

    enum calculatorOperations {
        ADD = '+',
        MINUS = '-',
        MULTIPLY = '*',
        DIVIDE = '/'
    };
}

MainMenu initializeProgramMenu();

// 1.uzd
void displayReversedString();
void reverseStr(std::string &str);

// 2.uzd
void displayNumSumInRecursion();
int countNumbersSumRecursive(int n);

// 3.uzd
void getNDisplayDiffTypeValues();
void Print(int value);
void Print(double value);
void Print(string value);
void Print(char value);

// 4.uzd
// (available since C++11)   https://en.cppreference.com/w/cpp/types/common_type
template<typename T, typename U>
typename std::common_type<T, U>::type min(T const& a, U const& b);

void getNDisplayMin();


// 5.uzd
void initializeCalculator();


// -----------------------------------------  ***** MAIN PROGRAM  **** -------------------------------------------------------------------

int main(int argc, const char * argv[]) {
    
    MainMenu mainProgram = initializeProgramMenu();
    mainProgram.runProgram();
    
    return 0;
}

// -------------------------------------------------------------------------------------------------------------------------------------


MainMenu initializeProgramMenu() {
    MainMenu mainProgram("Tasks after 4th Lesson");

    mainProgram.addItem("(1.uzd) Reverse string", &displayReversedString);
    mainProgram.addItem("(2.uzd) Sum of 1..n", &displayNumSumInRecursion);
    mainProgram.addItem("(3.uzd) Different data type input and output", &getNDisplayDiffTypeValues);
    mainProgram.addItem("(4.uzd) Get Minimum", &getNDisplayMin);
    mainProgram.addItem("(5.uzd) Calculator", &initializeCalculator);

    mainProgram.addItem("Exit", true);

    return mainProgram;
}


// 1.uzd
// -------------------------------------------------------
void displayReversedString() {
    string txt = programUtils::getInputInString("Enter text to reverse");
    reverseStr(txt);
    programUtils::displayData(txt);
}

void reverseStr(string &str) {
    int txtLength = str.length();
    int rightSideCharIndex = txtLength-1;
    int leftSideCharIndex = 0;

    while(leftSideCharIndex <= rightSideCharIndex) {

        swap(str[leftSideCharIndex], str[rightSideCharIndex]);

        leftSideCharIndex++;
        rightSideCharIndex--;
    }
}
// -------------------------------------------------------

// 2.uzd
// -------------------------------------------------------
void displayNumSumInRecursion() {
    int n = inputValidatorsUtils::getNumericOrCharValidatedInput<int>();
    programUtils::displayData(countNumbersSumRecursive(n));
}

int countNumbersSumRecursive(int n) {
    if (n == 0) return 0;
    
    return n + countNumbersSumRecursive(n-1);
}
// -------------------------------------------------------

// 3.uzd
// -------------------------------------------------------
void getNDisplayDiffTypeValues() {
    int intData = inputValidatorsUtils::getNumericOrCharValidatedInput<int>("| Input int value \t: ");
    Print(intData);
    
    double doubleData = inputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input double type value \t: ");
    Print(doubleData);

    char charData = inputValidatorsUtils::getNumericOrCharValidatedInput<char>("| Input char type value \t: ");
    Print(charData);

    string stringData;
    cout << "| Input string type value \t: ";
    cin.ignore();
    getline(cin, stringData);
    
    Print(stringData);
}

void Print(int value) {
    programUtils::displayData(value);
}

void Print(double value) {
    programUtils::displayData(value);
}

void Print(string value) {
    programUtils::displayData(value);
}

void Print(char value) {
    programUtils::displayData(value);
}

// -------------------------------------------------------

// 4.uzd
// -------------------------------------------------------

template<typename T, typename U>
typename std::common_type<T, U>::type min(T const& a, U const& b) {
    return (a < b) ? a : b;
}

void getNDisplayMin() {
    int intData = inputValidatorsUtils::getNumericOrCharValidatedInput<int>("| Input first value (int) \t: ");
    
    double doubleData = inputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input second value (double) \t: ");
    auto minValue = min<int, double>(intData, doubleData);

    programUtils::displayData(minValue);
}
// -------------------------------------------------------


// 5.uzd
// ------------------------------------------------------------------------------------------------------

void initializeCalculator() {
    
    double firstValue = inputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input first value \t: ");
    char operation = inputValidatorsUtils::getNumericOrCharValidatedInput<char>("| Enter operation (+, -, /, *) \t: ");
    double secondValue = inputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input second value \t: ");

    double result = 0;

    switch (static_cast<calculatorUtils::calculatorOperations>(operation))
    {
        case calculatorUtils::ADD:
                programUtils::displayData(firstValue + secondValue);
            break;
        
        case calculatorUtils::MINUS:
                programUtils::displayData(firstValue - secondValue);
            break;

        case calculatorUtils::MULTIPLY:
                programUtils::displayData(firstValue * secondValue);
            break;

        case calculatorUtils::DIVIDE:
                if(secondValue == 0)
                    programUtils::displayData("+ infinity");
                else
                    programUtils::displayData(firstValue / secondValue);
            break;

        default:
            programUtils::displayData("Operation for entered operator is not found!");
            break;
    }
}

// -------------------------------------------------------------------------------------------------
