#ifndef math_utils_h
#define math_utils_h

#include "program_utils.h"
#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

namespace mathUtils {

    template<typename T, typename U>
    typename std::common_type<T, U>::type sum(T const& a, U const& b) {
        return a + b;
    }

};

#endif