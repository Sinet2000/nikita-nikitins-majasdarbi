#ifndef first_addit_h
#define first_addit_h
#define MAX_TXT_LENGTH 255
#include "../core-file.h"

namespace additionalTasks {

// main chunks
void getInputToCharArr(char * txt, bool & isStringDataLastAdded);
void getInputToString(string &txtData, bool & isStringDataLastAdded);
void displayReversedStandardCurrentData(char *charArray, string &str, bool & isStringDataLastAdded);
void displayReversedWithIteratorsCurrentData(char *charArray, string &str, bool & isStringDataLastAdded);
void displayCurrentStateStringOrCharArrayData(char *charArray, string &str, bool & isStringDataLastAdded);

void taskMenuRunner() {
    char _txtArrayMain[MAX_TXT_LENGTH];
    string _txtStringMain;
    bool isStringDataLastAdded;

    MainMenu mainProgram1("1 additional");
    
    mainProgram1.addItem("Enter string", &additionalTasks::getInputToString, _txtStringMain, isStringDataLastAdded);

    mainProgram1.addItem("Enter char array", &additionalTasks::getInputToCharArr, _txtArrayMain, isStringDataLastAdded);

    mainProgram1.addItem("Standard Reverse", &additionalTasks::displayReversedStandardCurrentData, _txtArrayMain, _txtStringMain, isStringDataLastAdded);

    mainProgram1.addItem("Iterators Reverse", &additionalTasks::displayReversedWithIteratorsCurrentData, _txtArrayMain, _txtStringMain, isStringDataLastAdded);

    mainProgram1.addItem("Display data", &additionalTasks::displayCurrentStateStringOrCharArrayData , _txtArrayMain, _txtStringMain, isStringDataLastAdded);

    mainProgram1.addItem("Exit", true);

    mainProgram1.runProgram();
}


// main
// ********************************************************************************************************************************************************
void getInputToString(string &txtData, bool & isStringDataLastAdded) {
    isStringDataLastAdded = true;
    txtData = programUtils::getInputInString("Enter string");
}

void getInputToCharArr(char * txt, bool & isStringDataLastAdded) {
    isStringDataLastAdded = false;
    programUtils::getInputInCharArray("Enter char array", txt, MAX_TXT_LENGTH);
    cout << "Result1:" <<txt<< endl;
    programUtils::displayData(txt);
}

void displayReversedStandardCurrentData(char *charArray, string &str, bool & isStringDataLastAdded) {
    cout << "isStringDataLastAdded" << isStringDataLastAdded << endl;
    if (isStringDataLastAdded) {
        StringUtils::reverseStrAndDisplay(str);
    } else {
        StringUtils::reverseCharArrayAndDisplay(charArray);
    }
}

void displayReversedWithIteratorsCurrentData(char *charArray, string &str, bool &isStringDataLastAdded) {
    if (isStringDataLastAdded) {
        StringUtils::reverseStrAndDisplay(str, true);
    } else {
        // iterators for [] ??, there is only re
        StringUtils::reverseCharArrayAndDisplay(charArray, true);
    }
}

void displayCurrentStateStringOrCharArrayData(char *charArray, string &str, bool &isStringDataLastAdded) {
    programUtils::displayData((isStringDataLastAdded ? str : charArray));
}

}  // namespace additionalTasks

#endif

// #include "first-addit.h"

// #include "../utils/main_menu.h"

// namespace additionalTasks {

// // ********************************************** ___PRIVATE
// //
// FUNCITONS________*******************************************************************************************

// void FirstAdditionalTaskAdapter::reverseStr(std::string &str) {
//     string initialString = str;
//     str.clear();

//     // crbegin - returns a read only reverse iterator  that points to the
//     last
//     // char string:: iterator it;
//     string::const_reverse_iterator strIterator = initialString.crbegin();
//     while (strIterator != str.crend()) {
//         str.append(1, *(strIterator++));
//     }
// }

// void FirstAdditionalTaskAdapter::reverseStr(char *charArray) {
//     const int len = strlen(charArray);

//     for (int i = 0; i < len / 2; i++) {
//         std::swap(charArray[i], charArray[len - i - 1]);
//     }
// }

// //
// ⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆

// // ********************************************** _____CONSTRUCTORS and
// //
// initializators_____*******************************************************************************************

// FirstAdditionalTaskAdapter::FirstAdditionalTaskAdapter(){}

// void FirstAdditionalTaskAdapter::initAndRunApp() {
//     MainMenu _appMenu("1 additional");
//     _appMenu.addItem("Enter string", &getInputToString);

//     _appMenu.addItem("Display string", &displayString);

//     _appMenu.addItem("Exit", true);

//     _appMenu.runProgram();
// }

// //
// ⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆

// // ********************************************** ___PUBLIC
// //
// FUNCITONS________*******************************************************************************************

// void FirstAdditionalTaskAdapter::displayReversedString() {
//     string txt = programUtils::getInputInString("Enter text to reverse");
//     reverseStr(txt);

//     programUtils::displayData(txt);
// }

// void FirstAdditionalTaskAdapter::displayReversedCharArr() {
//     char txt[_maxTxtLength];
//     programUtils::getInputInCharArray("Enter text to reverse", txt,
//                                       _maxTxtLength);
//     reverseStr(txt);

//     programUtils::displayData(txt);
// }

// void FirstAdditionalTaskAdapter::getInputToString() {
//     _txtStringGlobal = programUtils::getInputInString("Enter string");
// }

// void FirstAdditionalTaskAdapter::displayString() {
//     programUtils::displayData(_txtStringGlobal);
// }

// //
// ⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆v⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆

// };  // namespace additionalTasks