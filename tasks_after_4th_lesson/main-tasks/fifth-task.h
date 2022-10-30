#ifndef fifth_task_h
#define fifth_task_h

#include "../core-file.h"
#include "../utils/enums/calculator-utils.h"

using namespace std;

namespace mainTasks {
    
    void initializeCalculator();


    void initializeCalculator() {
        
        double firstValue = inputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input first value \t: ");
        char operation = inputValidatorsUtils::getNumericOrCharValidatedInput<char>("| Enter operation (+, -, /, *) \t: ");
        double secondValue = inputValidatorsUtils::getNumericOrCharValidatedInput<double>("| Input second value \t: ");

        double result = 0;

        switch (static_cast<calculatorUtils::calculatorOperations>(operation))
        {
            case calculatorUtils::ADD:
                    programUtils::Print(firstValue + secondValue);
                break;
            
            case calculatorUtils::MINUS:
                    programUtils::Print(firstValue - secondValue);
                break;

            case calculatorUtils::MULTIPLY:
                    programUtils::Print(firstValue * secondValue);
                break;

            case calculatorUtils::DIVIDE:
                    if(secondValue == 0)
                        programUtils::Print("+ infinity");
                    else
                        programUtils::Print(firstValue / secondValue);
                break;

            default:
                programUtils::Print("Operation for entered operator is not found!");
                break;
        }
    }
}

#endif