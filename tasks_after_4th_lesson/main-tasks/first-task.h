#ifndef first_task_h
#define first_task_h

#include "../core-file.h"

using namespace std;

namespace mainTasks {
    
    void displayReversedString();
    void reverseStr(std::string &str);

    void displayReversedString() {
        string txt = programUtils::getInputInString("Enter text to reverse");
        reverseStr(txt);
        
        programUtils::displayData(txt);
    }

    void reverseStr(string &str) {
        StringUtils::reverseStr(str);
    }
} // namespace mainTasks


#endif