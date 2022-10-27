#ifndef first_task_h
#define first_task_h

#include "core-file.h"

using namespace std;

void displayReversedString(bool usingIterators = false);
void reverseStr(std::string &str);

void displayReversedString(bool usingIterators) {
    string txt = programUtils::getInputInString("Enter text to reverse");
    if (usingIterators)
    {
        reverseStr(txt);
    }
    else {
        reverseStr(txt);
    }
    
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

#endif