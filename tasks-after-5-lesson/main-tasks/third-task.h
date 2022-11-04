#ifndef third_task_h
#define third_task_h

#include "../core-file.h"

using namespace std;

namespace mainTasks {
    void getEnteredStringLength();

    void getEnteredStringLength() {
        const int strMaxLength = 100;

        string usrInputStr = programUtils::getInputInString("Enter string:\t");
        cout << "\n| User Input String Length:\t" << stringUtils::strLength(usrInputStr) << endl;

        char *usrInputCharArr = programUtils::getInputInCharArray("Enter char arr:\t", strMaxLength);
        cout << "\n| User Input Char arr Length:\t" << stringUtils::strLength(usrInputCharArr) << endl;
    }
} 


#endif