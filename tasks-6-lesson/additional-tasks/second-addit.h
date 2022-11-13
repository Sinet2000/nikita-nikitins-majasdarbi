#ifndef _SECOND_ADDIT_H
#define _SECOND_ADDIT_H

#include "../core-file.h"

using namespace std;
namespace additionalTasks {

    void getRandomNumbersAndFindDivisibleBy3n5();

    void taskMenuRunnerSecond() {
        MainMenu mainProgram("Tasks after 6th Lesson");

        mainProgram.addItem("(1.Extra)", &additionalTasks::taskMenuRunnerFirst);

        mainProgram.addItem("(1.uzd) Save entered txt", &mainTasks::saveUserEnteredTxt);
        mainProgram.addItem("(2.uzd) Integer manager", &mainTasks::manageIntArrayToFiles);
        mainProgram.addItem("(3.uzd) Count letters of a file text", &mainTasks::countLettersInFileTxt);
        mainProgram.addItem("(4.uzd) Replace and save content", &mainTasks::readAndSaveReplaced);
        mainProgram.addItem("(5.uzd) Datetime manager (Binary)", &mainTasks::datetimeManagerInBinFile);

        mainProgram.addItem("Exit", true);
    } 

    void getRandomNumbersAndFindDivisibleBy3n5() {
        vector<int> readData = fileUtils::readArrFromFile<int>(ProgramConstants::SECOND_PROGRAM_FILENAME);
        int sum = 0;

        for (int &readInt : readData) {
            if (readInt % 3 == 0 && readInt % 5 ==0)
            sum += readInt; 
        }
        if (!fileUtils::fileExists(ProgramConstants::SECOND_ADDITIONAL_TASK_FILENAME))
            remove((ProgramConstants::SECOND_ADDITIONAL_TASK_FILENAME);

        fileUtils::appendToFile<int>((ProgramConstants::SECOND_ADDITIONAL_TASK_FILENAME, sum);
    }

}
#endif