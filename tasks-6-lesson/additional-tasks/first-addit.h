#ifndef _FIRST_ADDIT_H
#define _FIRST_ADDIT_H

#include "../core-file.h"
#include "../utils/main_menu.h"

using namespace std;

namespace additionalTasks {

    void initNewFileWithContent(string &newFileName);

    void taskMenuRunnerFirst() {

        string newFileName;
        MainMenu mainProgram1("1 additional");


        mainProgram1.addItem("Exit", true);

        mainProgram1.runProgram();
    }

    void initNewFileWithContent(string &newFileName) {
        const vector<string> reservedFileNames = programUtils::getReservedFileNames();

        do
        {
            newFileName = inputValidatorsUtils::getTextInput("\nEnter the name of new file: ");
        } while (newFileName);
        
        newFileName = inputValidatorsUtils::getTextInput("\nEnter the name of new file: ");
        const vector<string> reservedFileNames = programUtils::getReservedFileNames();

        if (std::find(reservedFileNames.begin(), reservedFileNames.end(), newFileName) != reservedFileNames.end()) {

        }

     }
}

#endif