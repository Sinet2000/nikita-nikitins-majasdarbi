#include <iostream>
#include <string>
#include <cstdio>
#include "utils/main_menu.h"
#include "utils/program_utils.h"
#include "utils/input_validators.h"

using namespace std;

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

int main(int argc, const char * argv[]) {
    
    // MainMenu globalAndHeader("Tasks after 4th Lesson", &globalCallback);
    MainMenu mainProgram("Tasks after 4th Lesson");

    mainProgram.addItem("(1.uzd) Reverse string", &displayReversedString);
    mainProgram.addItem("(2.uzd) Sum of 1..n", &displayNumSumInRecursion);
    mainProgram.addItem("(3.uzd) Different data type input and output", &getNDisplayDiffTypeValues);

    mainProgram.addItem("Exit", true);
    mainProgram.runProgram();
    
    return 0;
}

// 1.uzd
// -------------------------------------------------------
void displayReversedString() {
    string txt = ProgramUtils::getInputInString("Enter text to reverse");
    reverseStr(txt);
    ProgramUtils::displayData(txt);
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
    int n = InputValidatorsUtils::getNumericOrCharValidatedInput<int>();
    ProgramUtils::displayData(countNumbersSumRecursive(n));
}

int countNumbersSumRecursive(int n) {
    if (n == 0) return 0;
    
    return n + countNumbersSumRecursive(n-1);
}
// -------------------------------------------------------

// 3.uzd
// -------------------------------------------------------
void getNDisplayDiffTypeValues() {
    int intData = InputValidatorsUtils::getNumericOrCharValidatedInput<int>("| Input int value \t: ");
    Print(intData);
    
    double doubleData = InputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input double type value \t: ");
    Print(doubleData);

    char charData = InputValidatorsUtils::getNumericOrCharValidatedInput<char>("| Input char type value \t: ");
    Print(charData);

    string stringData;
    cout << "| Input string type value \t: ";
    cin.ignore();
    getline(cin, stringData);
    
    Print(stringData);
}

void Print(int value) {
    ProgramUtils::displayData(value);
}

void Print(double value) {
    ProgramUtils::displayData(value);
}

void Print(string value) {
    ProgramUtils::displayData(value);
}

void Print(char value) {
    ProgramUtils::displayData(value);
}

// -------------------------------------------------------