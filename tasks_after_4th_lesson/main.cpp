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


// Additional Tasks
#include "additional-tasks/first-addit.h"

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
    MainMenu mainProgram("Tasks after 4th Lesson");

    mainProgram.addItem("(1-additional.uzd) ", &additionalTasks::taskMenuRunner);
    mainProgram.addItem("(1.uzd) Reverse string", &mainTasks::displayReversedString);
    mainProgram.addItem("(2.uzd) Sum of 1..n", &mainTasks::displayNumSumInRecursion);
    mainProgram.addItem("(3.uzd) Different data type input and output", &mainTasks::getNDisplayDiffTypeValues);
    mainProgram.addItem("(4.uzd) Get Minimum", &mainTasks::getNDisplayMin);
    mainProgram.addItem("(5.uzd) Calculator", &mainTasks::initializeCalculator);

    mainProgram.addItem("Exit", true);

    return mainProgram;
}