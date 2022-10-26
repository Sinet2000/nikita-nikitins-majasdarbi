#include "input_validators.h"
#include <iostream>
#include <limits>

namespace InputValidatorsUtils{
    
    int getUserMenuInput(std::string text) {

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
