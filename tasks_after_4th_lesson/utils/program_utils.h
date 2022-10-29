#ifndef program_utils_h
#define program_utils_h

#include <string>
#include <vector>
#include <stack>
#include <queue>

namespace programUtils {

    std::string getInputInString(std::string txt);
    void getInputInCharArray(std::string description, char *charArray, int length);

    void Print(std::string txt);

    void Print(int data);

    void Print(double data);

    void Print(char data);

    void Print(char *data);


    void Print(std::vector<char> vectorData);

    void Print(std::stack<char> stackData);

    void Print(std::queue<char> queueData);

    void swap(char *a, char *b);
}


#endif