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

#if __cplusplus < 201703L
  #error This file needs at least a C++17 compliant compiler, try using:
  #error    $ g++ -std=c++17 ..
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
  MainMenu mainProgram("Tasks after 6th Lesson");

  mainProgram.addItem("(1.uzd) Save entered txt", &mainTasks::saveUserEnteredTxt);
  mainProgram.addItem("(2.uzd) Integer manager", &mainTasks::manageIntArrayToFiles);
  mainProgram.addItem("(3.uzd) Count letters of a file text", &mainTasks::countLettersInFileTxt);
  mainProgram.addItem("(4.uzd) Replace and save content", &mainTasks::readAndSaveReplaced);
  mainProgram.addItem("(5.uzd) Datetime manager (Binary)", &mainTasks::datetimeManagerInBinFile);

  mainProgram.addItem("Exit", true);

  return mainProgram;
}