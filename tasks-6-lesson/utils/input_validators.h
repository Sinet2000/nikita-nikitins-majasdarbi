#ifndef input_validators_h
#define input_validators_h

#include <iostream>
#include <string>
#include <optional>
#include <limits>


using namespace std;

namespace inputValidatorsUtils {
    unsigned int getUserMenuInput(string text = "| Please select |\t>> ");

    string getTextInput(
        string text,
        optional<string> defaultValue = optional<string>(nullopt)
    );

    double getDoubleInput(
        string text,
        optional<double> defaultValue = optional<double>(nullopt)
    );

    int getIntInput(
        string text,
        optional<int> defaultValue = optional<int>(nullopt)
    );

    bool getBoolInput(
        string text,
        optional<bool> defaultValue = optional<bool>(nullopt)
    );

    char *getInputInCharArray(string description, int length);


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

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        return userInput;
    }
}

#endif