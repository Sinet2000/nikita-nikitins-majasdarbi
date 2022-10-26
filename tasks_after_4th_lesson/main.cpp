#include <iostream>
#include <string>
#include <cstdio>
#include "utils/main_menu.h"
#include "utils/program_utils.h"

using namespace std;

// 1.uzd
void displayReversedString();
void reverseStr(std::string &str);

int main(int argc, const char * argv[]) {
    
    // MainMenu globalAndHeader("Tasks after 4th Lesson", &globalCallback);
    MainMenu mainProgram("Tasks after 4th Lesson");

    mainProgram.addItem("(1.uzd) Reverse string", &displayReversedString);
    mainProgram.addItem("(2.uzd) Reverse string", &displayReversedString);

    mainProgram.addItem("Exit", true);
    mainProgram.runProgram();
    
    return 0;
}


void displayReversedString() {
    string txt = ProgramUtils::getInputInString("Enter text to reverse");
    reverseStr(txt);
    ProgramUtils::displayString(txt);
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