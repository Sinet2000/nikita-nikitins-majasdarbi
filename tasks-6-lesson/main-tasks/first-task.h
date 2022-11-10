#ifndef first_task_h
#define first_task_h

#include "../core-file.h"

using namespace std;

namespace mainTasks {

    void saveUserEnteredTxt() {
        string fileName = "file-task1.txt";
        string userTxt = inputValidatorsUtils::getTextInput("\nEnter your txt to save in a file: ");
        const int txtArrLength = userTxt.length() + 1;
        char *charArr = (char*)malloc((txtArrLength) * sizeof(char));
        strcpy(charArr, userTxt.c_str());        

        fileUtils::writeArrToFile<char>(fileName, charArr, txtArrLength-1); // we don't need '\0'
    }

} // namespace mainTasks


#endif