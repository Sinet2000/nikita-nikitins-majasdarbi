
#ifndef calucaltor_utils_h
#define calucaltor_utils_h

namespace calculatorUtils {

    enum calculatorOperations {
        ADD = '+',
        MINUS = '-',
        MULTIPLY = '*',
        DIVIDE = '/' ,
        OPENING_BRACE = '(',
        CLOSED_BRACE = ')'
    };

    enum operatorsPriority {
        NOT_OPERAND = 0,
        LOW = 1,
        HIGH = 2
    };
}

#endif