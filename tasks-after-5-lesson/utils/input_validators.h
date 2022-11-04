#ifndef input_validators_h
#define input_validators_h

#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h> /* malloc, free, rand */

using namespace std;

namespace inputValidatorsUtils {
    
    template<typename T>
    T getNumericOrCharValidatedInput(string text = "| Please enter value |\t>> ") {
        T userInput;
        
        cout << text;
        cin >> userInput;

        while (1) {
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "| !!! Incorrect value! Enter value|\t>>";
                cin >> userInput;
            }

            if (!cin.fail()) break;
        }

        return userInput;
    }

    template<typename T>
    T* getValidatedInputPointed(string text = "| Please enter value |\t>> "){
        T* valuePtr = (T*) malloc(sizeof(T));
        cout << text;

        cin >> *valuePtr;

        while (1) {
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "| !!! Incorrect value! Enter value|\t>>";
                cin >> *valuePtr;
            }

            if (!cin.fail()) break;
        }

        return valuePtr;
    }
} 

#endif