#ifndef program_utils_h
#define program_utils_h

#include <string>
#include <vector>
#include <stack>
#include <queue>

namespace programUtils {

    std::string getInputInString(std::string txt);

    char *getInputInCharArray(std::string description, int length);

    void Print(std::string txt);

    void Print(int data);

    void Print(double data);

    void Print(char data);

    void Print(char *data);

    void Print(int *data, int size);
}


#endif