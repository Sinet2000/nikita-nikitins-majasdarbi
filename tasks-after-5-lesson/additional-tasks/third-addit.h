#ifndef _THIRD_ADDIT_H
#define _THIRD_ADDIT_H

#include "../core-file.h"
#include "../utils/main_menu.h"

namespace additionalTasks {

    void capitalizeText();
    void displayTxtReversed();
    void checkContainsInTxt();

    void taskMenuRunnerThird() {
        MainMenu mainProgram1("3 additional");

        mainProgram1.addItem("Capitalize text", &capitalizeText);
        mainProgram1.addItem("Display text REVERSED", &displayTxtReversed);
        mainProgram1.addItem("Test contains symbol in txt", &checkContainsInTxt);

        mainProgram1.addItem("Exit", true);

        mainProgram1.runProgram();
    }

    void capitalizeText() {
        const int strMaxLength = 100;

        string usrInputStr = programUtils::getInputInString("Enter string: ");
        stringUtils::capitalizeText(usrInputStr);
        programUtils::Print(usrInputStr);

        char* usrInputCharArr = programUtils::getInputInCharArray("Enter char arr: ", strMaxLength);
        stringUtils::capitalizeText(usrInputCharArr);
        programUtils::Print(usrInputCharArr);
    }

    void displayTxtReversed() {
        char* charArr = programUtils::getInputInCharArray("Enter char arr: ", 100);

        stringUtils::reverseDisplay(charArr); 
    }

    void checkContainsInTxt() {
        char* charArr = programUtils::getInputInCharArray("Enter char arr: ", 100);
        char c = inputValidatorsUtils::getNumericOrCharValidatedInput<char>();

        cout << "\nContains:" << (stringUtils::containsInTxt(charArr, c) ? " Yes" : "Nope") << endl;
    }
}

#endif