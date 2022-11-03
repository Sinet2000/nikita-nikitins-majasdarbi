#include <iostream>
#include <string>
#include <cstdio>
#include <type_traits>

#include "utils/main_menu.h"
// #include "utils/program_utils.h"
// #include "utils/input_validators.h"

// main tasks

#if __cplusplus <= 199711L
  #error This file needs at least a C++11 compliant compiler, try using:
  #error    $ g++ -std=c++11 ..
#endif

using namespace std;

MainMenu initializeProgramMenu();

// void initAndRunFirstAdditionalTask();


// -----------------------------------------  ***** MAIN PROGRAM  **** -------------------------------------------------------------------

int main(int argc, const char * argv[]) {
    
    MainMenu mainProgram = initializeProgramMenu();
    mainProgram.runProgram();
    
    return 0;
}

// -------------------------------------------------------------------------------------------------------------------------------------


MainMenu initializeProgramMenu() {
    MainMenu mainProgram("Tasks 6 Lesson");

    mainProgram.addItem("Exit", true);

    return mainProgram;
}
