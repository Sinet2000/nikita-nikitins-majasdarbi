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
    MainMenu mainProgram("Tasks after nth Lesson");


    mainProgram.addItem("Exit", true);

    return mainProgram;
}