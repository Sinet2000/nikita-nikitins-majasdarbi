#ifndef program_utils_h
#define program_utils_h

#include <string>

namespace programUtils {

    std::string getInputInString(std::string txt);
    void getInputInCharArray(std::string description, char *charArray, int length);
    void displayData(std::string txt);
    void displayData(int data);
    void displayData(double data);
    void displayData(char data);
    void displayData(char *data);
    void swap(char *a, char *b);
}


#endif