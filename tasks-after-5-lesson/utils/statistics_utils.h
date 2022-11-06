#ifndef __STATISTICS_UTILS_H
#define __STATISTICS_UTILS_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#include "array_utils.h"
#include "math_utils.h"

using namespace std;

namespace statisticsUtils
{
    template <typename T>
    T *getMiddleElement(T *dataArr, const size_t &size);

    template <typename T>
    T *getMiddleElement(T *dataArr, const size_t &size) {
        if (size == 1)
            return dataArr;
        
        return dataArr + size/2;
    }
} // namespace statisticsUtils


#endif