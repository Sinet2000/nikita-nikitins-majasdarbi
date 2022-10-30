#ifndef math_utils_h
#define math_utils_h

#include "program_utils.h"
#include "enums/calculator-utils.h"
#include <iostream>
#include <string>
#include <stack>
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

    template<typename T, typename U>
    typename std::common_type<T, U>::type min(T const& a, U const& b) {
        return (a < b) ? a : b;
    }

    template<typename T, typename U>
    typename std::common_type<T, U>::type max(T const& a, U const& b) {
        return (a > b) ? a : b;
    }

    template<typename T>
    T min(vector<T> const& a) {
        return *min_element(a.begin(), a.end());
    }


    template<typename T>
    T max(vector<T> const& a) {
        return *max_element(a.begin(), a.end());
    }

    calculatorUtils::operatorsPriority getMathOperatorPriority(char opr){
        calculatorUtils::calculatorOperations operatorEnum = static_cast<calculatorUtils::calculatorOperations>(opr);

        if(operatorEnum == calculatorUtils::ADD || operatorEnum == calculatorUtils::MINUS)
            return calculatorUtils::operatorsPriority::LOW;

        if(operatorEnum == calculatorUtils::MULTIPLY || operatorEnum == calculatorUtils::DIVIDE)
            return calculatorUtils::operatorsPriority::HIGH;

        return calculatorUtils::operatorsPriority::NOT_OPERAND;
    }

    int getAppliedOperationValue(int a, int b, char opr) {
        switch (static_cast<calculatorUtils::calculatorOperations>(opr))
        {
            case calculatorUtils::ADD:
                    return a + b;
            
            case calculatorUtils::MINUS:
                    return a - b;

            case calculatorUtils::MULTIPLY:
                    return a * b;

            case calculatorUtils::DIVIDE:
                    return a / b;
        }
    }

    int getNumberBeforeAlphaCharFromString(string txtValue, int &index) {
        int value = 0;
        while(index < txtValue.length() && isdigit(txtValue[index]))
        {
            value = (value*10) + (txtValue[index]-'0');
            index++;
        }

        index--; // becase after last operation it is pointed on next operation

        return value;
    }   

    // must be trimmed
    int getEvaluatedExpressionValue(string expressionStr) {
        stack <int> expressionValues;
        
        stack <char> expressionOperands;

        for (int i = 0; i < expressionStr.length(); i++) {
            // in case if it wasn't trimmed
            if(expressionStr[i] == ' ')
                continue;

            if (static_cast<calculatorUtils::calculatorOperations>(expressionStr[i]) == calculatorUtils::OPENING_BRACE) {
                expressionOperands.push(expressionStr[i]);
            }
            else if (isdigit(expressionStr[i])) {
                int valueFromExpr = getNumberBeforeAlphaCharFromString(expressionStr, i);
                expressionValues.push(valueFromExpr);
            }
            else if (static_cast<calculatorUtils::calculatorOperations>(expressionStr[i]) == calculatorUtils::CLOSED_BRACE) {
                while(!expressionOperands.empty() && static_cast<calculatorUtils::calculatorOperations>(expressionOperands.top()) != calculatorUtils::OPENING_BRACE)
                {
                    int valueSecond = expressionValues.top();
                    expressionValues.pop();
                    
                    int valueFirst = expressionValues.top();
                    expressionValues.pop();
                    
                    char op = expressionOperands.top();
                    expressionOperands.pop();
                    
                    expressionValues.push(getAppliedOperationValue(valueFirst, valueSecond, op));

                    // remove opening brace
                    if(!expressionOperands.empty())
                        expressionOperands.pop();
                }
            } // next case is operand
            else {
                while(!expressionOperands.empty() 
                        && static_cast<int>(getMathOperatorPriority(expressionOperands.top())) 
                            >= static_cast<int>(getMathOperatorPriority(expressionStr[i]))
                        
                ){
                    int val2 = expressionValues.top();
                    expressionValues.pop();
                    
                    int val1 = expressionValues.top();
                    expressionValues.pop();
                    
                    char opr = expressionOperands.top();
                    expressionOperands.pop();
                    
                    expressionValues.push(getAppliedOperationValue(val1, val2, opr));
                }
                
                // Push current token to 'ops'.
                expressionOperands.push(expressionStr[i]);
            }
        }

        while(!expressionOperands.empty()){
            int val2 = expressionValues.top();
            expressionValues.pop();
                    
            int val1 = expressionValues.top();
            expressionValues.pop();
                    
            char opr = expressionOperands.top();
            expressionOperands.pop();
                    
            expressionValues.push(getAppliedOperationValue(val1, val2, opr));
        }

        return expressionValues.top();
        
    }

    int countNumbersSumRecursive(int n) {
        if (n == 0) return 0;
        
        return n + countNumbersSumRecursive(n-1);
    }
};

#endif