#ifndef string_utils_h
#define string_utils_h

#include "program_utils.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

namespace stringUtils {

    int strLength(char *str);
    int strLength(string &str);
    
    int strLength(char *str) {
        int length = 0;

        while (*str != '\0') {
            length++;
            str++;
        }
    
        return length;
    }

    int strLength(string &str) {
        const char* string_ptr = str.c_str();
        int length = 0;

        while (*string_ptr != '\0') {
            length++;
            string_ptr++;
        }

        return length;
    }
};

#endif