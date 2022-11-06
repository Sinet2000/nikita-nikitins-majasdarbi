#ifndef string_utils_h
#define string_utils_h

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

#include "program_utils.h"

using namespace std;

namespace stringUtils {

int strLength(char *str);
int strLength(string &str);

void capitalizeText(char *str);
void capitalizeText(string &str);

void reverseDisplay(char *charArr);
bool containsInTxt(char *charArr, char toFind);

int strLength(char *str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }

    return length;
}

int strLength(string &str) {
    const char *string_ptr = str.c_str();
    int length = 0;

    while (*string_ptr != '\0') {
        length++;
        string_ptr++;
    }

    return length;
}

void capitalizeText(char *str) {
    int length = 0;

    while (*str != '\0') {
        if (length == 0) {  // first letter
            *str = toupper(*str);
        } else if (*(str + 1) != '\0' && *(str - 1) == ' ') {
            *str = toupper(*str);
        }
        str++;
        length++;
    }
}

void capitalizeText(string &str) {
    for (int x = 0; x < str.length(); x++) {
        if (x == 0) {
            str[x] = toupper(str[x]);
        } else if (str[x - 1] == ' ') {
            str[x] = toupper(str[x]);
        }
    }
}

void reverseDisplay(char *charArr) {

    for (char *endCharPtr = charArr + strlen(charArr) - 1;  endCharPtr >= charArr;--endCharPtr){
                cout << *endCharPtr;
    }

    cout << endl;
}


bool containsInTxt(char *charArr, char toFind) {

    for (char *txtCharPtr = charArr;  txtCharPtr < charArr + strlen(charArr); ++txtCharPtr){
        if (*txtCharPtr == toFind) {
            return true;
        }
    }

    return false;
}
};  // namespace stringUtils

#endif