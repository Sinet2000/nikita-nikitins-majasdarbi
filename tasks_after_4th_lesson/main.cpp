#include <iostream>
#include <string>
#include <cstdio>
#include <type_traits>

#include "utils/main_menu.h"
// #include "utils/program_utils.h"
// #include "utils/input_validators.h"

// main tasks
#include "main-tasks/first-task.h"
#include "main-tasks/second-task.h"
#include "main-tasks/third-task.h"
#include "main-tasks/fourth-task.h"
#include "main-tasks/fifth-task.h"

using namespace std;

MainMenu initializeProgramMenu();

// Additional tasks
// 1
// 1.1
string reverseStrIterator(std::string &str);

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

// ---------------------------------****  Additional Tasks  *****--------------------------------------------
// 1.1
string reverseStrIterator(std::string &str) {
    string reversedStr;

    // crbegin - returns a read only reverse iterator  that points to the last char
    // string:: iterator it;
    string::const_reverse_iterator strIterator = str.crbegin();
    while(strIterator != str.crend()) {
        reversedStr.append(1, *(strIterator++));
    }

    return reversedStr;
}