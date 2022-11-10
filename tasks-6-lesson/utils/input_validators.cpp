#include "input_validators.h"

#include <iostream>
#include <string>
#include <optional>
#include <limits>

namespace inputValidatorsUtils {
    unsigned int getUserMenuInput(std::string text) {

        int userInput;
        std::cout << text;
        std::cin >> userInput;

        while (1) {
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "| !!! Incorrect value!\t:";
                std::cin >> userInput;
            }

            if (!std::cin.fail()) break;
        }

        // Clear anything left after reading, otherwise std::getline is wonky
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return userInput;
    }

    std::string getTextInput(std::string text, std::optional<std::string> defaultValue) {
        std::cout << text;

        std::string str;
        std::getline(std::cin, str);

        if (defaultValue.has_value() && str == "") return defaultValue.value();

        return str;
    }

    double getDoubleInput(std::string text, std::optional<double> defaultValue) {
        while (true) {
            std::string str = getTextInput(text);

            if (defaultValue.has_value() && str == "") return defaultValue.value();

            try {
                return std::stod(str);
            } catch (...) {
                std::cout << "Incorrect value\n";
            }
        }
    }

    int getIntInput(std::string text, std::optional<int> defaultValue) {
        while (true) {
            std::string str = getTextInput(text);

            if (defaultValue.has_value() && str == "") return defaultValue.value();

            try {
                return std::stoi(str);
            } catch (...) {
                std::cout << "Incorrect value\n";
            }
        }
    }

    bool getBoolInput(std::string text, std::optional<bool> defaultValue) {
        while (true) {
            std::string str = getTextInput(text);

            if (defaultValue.has_value() && str == "") {
                return defaultValue.value();
            }

            if (str == "y" || str == "yes" || str == "Y" || str == "Yes" || str == "YES") {
                return true;
            }
            
            if (str == "n" || str == "no" || str == "N" || str == "No" || str == "NO") {
                return false;
            }

            std::cout << "Incorrect value\n";
        }
    }

    char *getInputInCharArray(string &description, const size_t &length) {
        char *charArr = (char*)malloc((length + 1) * sizeof(char)); // length + 1, cause the last one is '\0'
        cout << "\n| " << description << " |\t>>";
        cin.getline(charArr, length);

        return charArr;
    }
}