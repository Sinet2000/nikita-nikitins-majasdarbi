#include <iostream>
#include <string>
#include <cstdio>
#include <type_traits>

#include "utils/main_menu.h"

#include "main-tasks/first-task.h"
#include "main-tasks/second-task.h"
#include "main-tasks/third-task.h"
#include "main-tasks/fourth-task.h"
#include "main-tasks/fifth-task.h"

#include "additional-tasks/first-addit.h"
#include "additional-tasks/second-addit.h"
#include "additional-tasks/third-addit.h"
#include "additional-tasks/fourth-addit.h"
#include "additional-tasks/fifth-addit.h"

#if __cplusplus <= 199711L
  #error This file needs at least a C++11 compliant compiler, try using:
  #error    $ g++ -std=c++11 ..
#endif

using namespace std;

MainMenu initializeProgramMenu();



// -----------------------------------------  ***** MAIN PROGRAM  **** -------------------------------------------------------------------

int main(int argc, const char * argv[]) {
    
    MainMenu mainProgram = initializeProgramMenu();
    mainProgram.runProgram();
    
    return 0;
}

// -------------------------------------------------------------------------------------------------------------------------------------


MainMenu initializeProgramMenu() {
    MainMenu mainProgram("Tasks after 5th Lesson");

    mainProgram.addItem("(1-additional.uzd)", &additionalTasks::taskMenuRunnerFirst);
    mainProgram.addItem("(2-additional.uzd)", &additionalTasks::taskMenuRunnerSecond);
    mainProgram.addItem("(3-additional.uzd)", &additionalTasks::taskMenuRunnerThird);
    mainProgram.addItem("(4-additional.uzd)", &additionalTasks::taskMenuRunnerFourth);
    mainProgram.addItem("(5-additional.uzd)", &additionalTasks::taskMenuRunnerFifth);

    mainProgram.addItem("(1.uzd) Input / pointers", &mainTasks::getInputAndDisplaySum);
    mainProgram.addItem("(2.uzd) Find in array", &mainTasks::findNumInData);
    mainProgram.addItem("(3.uzd) Enter Char arr/ string length", &mainTasks::getEnteredStringLength);
    mainProgram.addItem("(4.uzd) Reverse Display", &mainTasks::reverseDisplayNumArr);
    mainProgram.addItem("(5.uzd) Find and display min value", &mainTasks::findAndDisplayMinInIntArr);
    mainProgram.addItem("Exit", true);

    return mainProgram;
}