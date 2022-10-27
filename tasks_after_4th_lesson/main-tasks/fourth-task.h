#ifndef fourth_task_h
#define fourth_task_h

#include "core-file.h"

using namespace std;

// (available since C++11)   https://en.cppreference.com/w/cpp/types/common_type
template<typename T, typename U>
typename std::common_type<T, U>::type min(T const& a, U const& b);

void getNDisplayMin();


template<typename T, typename U>
typename std::common_type<T, U>::type min(T const& a, U const& b) {
    return (a < b) ? a : b;
}

void getNDisplayMin() {
    int intData = inputValidatorsUtils::getNumericOrCharValidatedInput<int>("| Input first value (int) \t: ");
    
    double doubleData = inputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input second value (double) \t: ");
    auto minValue = min<int, double>(intData, doubleData);

    programUtils::displayData(minValue);
}

#endif