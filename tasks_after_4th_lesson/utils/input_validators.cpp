#include "input_validators.h"
#include <iostream>
#include <limits>
#include <string>

namespace InputValidatorsUtils
{
    int getUserMenuInput(std::string text = "| Please select |\t>> ") {

        int userInput;
        std::cout << "| Please select |\t>> ";
        std::cin >> userInput;

        while (1) {
            
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "| !!! Incorrect selection! Enter int value|\t>>";
                std::cin >> userInput;
            }

            if (!std::cin.fail()) break;
        }

        return userInput;
    }
} 
