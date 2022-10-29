#ifndef math_utils_h
#define math_utils_h

#include "program_utils.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

namespace MathUtils {

    int getSumOfDigitsOfInt(int number) {
        if (number == 0) return 0;

        return (number % 10 + getSumOfDigitsOfInt(number / 10));
    }
    
    // 9543 => 9[1]  543 => 9[1]5[2] 43 => 9[1]5[2]4[3] 3 ...
    int getCountOfDigitsInInt(int number) {
        if (number == 0) return 0;

        return (1 + getCountOfDigitsInInt(number / 10));
    }
};

#endif