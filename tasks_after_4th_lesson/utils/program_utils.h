#ifndef program_utils_h
#define program_utils_h

#include <string>

namespace ProgramUtils {

    std::string getInputInString(std::string txt);
    void displayData(std::string txt);
    void displayData(int data);
    void displayData(double data);
    void displayData(char data);
    void swap(char *a, char *b);
}


#endif