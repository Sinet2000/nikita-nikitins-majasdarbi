#ifndef fourth_task_h
#define fourth_task_h

#include "../core-file.h"
#include "../utils/math_utils.h"

using namespace std;

namespace mainTasks {

    void getNDisplayMin();

    void getNDisplayMin() {
        int intData = inputValidatorsUtils::getNumericOrCharValidatedInput<int>("| Input first value (int) \t: ");
        
        double doubleData = inputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input second value (double) \t: ");
        auto minValue = MathUtils::min<int, double>(intData, doubleData);

        programUtils::Print(minValue);
    }

}

#endif