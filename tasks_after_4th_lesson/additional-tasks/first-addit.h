#ifndef first_addit_h
#define first_addit_h

#include "../core-file.h"

namespace additionalTasks
{
    void displayReversedString();
    void displayReversedCharArr();
    void reverseStr(std::string &str);
    void reverseStr(char *charArray);

    void displayReversedString() {
        string txt = programUtils::getInputInString("Enter text to reverse");
        reverseStr(txt);
        
        programUtils::displayData(txt);
    }

    void displayReversedCharArr() {
        int maxTxtLength = 255;
        char txt[maxTxtLength];
        programUtils::getInputInCharArray("Enter text to reverse", txt, maxTxtLength);
        reverseStr(txt);
        
        programUtils::displayData(txt);
    }

    void reverseStr(std::string &str) {
        string initialString = str;
        str.clear();

        // crbegin - returns a read only reverse iterator  that points to the last char
        // string:: iterator it;
        string::const_reverse_iterator strIterator = initialString.crbegin();
        while(strIterator != str.crend()) {
            str.append(1, *(strIterator++));
        }
    }

    void reverseStr(char *charArray) {
        const int len = strlen(charArray); // or strlen ?
        
        for(int i = 0; i<len/2; i++) {
            std::swap(charArray[i], charArray[len-i-1]); 
        }
    }

} // namespace additionalTasks


#endif