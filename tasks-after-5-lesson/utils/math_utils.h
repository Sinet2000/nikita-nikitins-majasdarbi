#ifndef math_utils_h
#define math_utils_h

#include "program_utils.h"
#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

namespace mathUtils {

    template <typename T>
    struct MinAndMaxValue {
        T *minValue;
        T *maxValue;
    };

    template<typename T, typename U>
    typename std::common_type<T, U>::type sum(T const& a, U const& b) {
        return a + b;
    }
    
    template<typename T>
    bool compareDataPtrValues(T *a, T *b) {
        return (*a < *b);
    }

    template<typename T>
    MinAndMaxValue<T> getMinAndMax(vector<T*> valueVector) {
        MinAndMaxValue<T> minAndMaxValue;

        sort(valueVector.begin(), valueVector.end(), mathUtils::compareDataPtrValues<T>);

        minAndMaxValue.minValue = valueVector.front();
        minAndMaxValue.maxValue = valueVector.back();

        return minAndMaxValue;
    }

};

#endif