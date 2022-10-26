#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <typeinfo>

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
} 