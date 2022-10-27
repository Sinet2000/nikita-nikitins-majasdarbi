#ifndef third_task_h
#define third_task_h

#include "core-file.h"

using namespace std;

void getNDisplayDiffTypeValues();
void Print(int value);
void Print(double value);
void Print(string value);
void Print(char value);

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

#endif