#ifndef third_addit_h
#define third_addit_h

#include "../core-file.h"
#include "../utils/main_menu.h"
#include "../utils/math_utils.h"
#include "../utils/enums/input-utils.h"

namespace additionalTasks {

void createVectorOfTypeNAndDispay();

void taskMenuRunnerThird() {
    string _expressionString;

    MainMenu mainProgram1("3 additional");
    
    mainProgram1.addItem("Get Vector From Selected and Display", &createVectorOfTypeNAndDispay);

    mainProgram1.addItem("Exit", true);

    mainProgram1.runProgram();
}


void createVectorOfTypeNAndDispay() {
    inputUtils::dataTypeOptions selectedType = inputUtils::getUserSelectedDataType();

    switch (selectedType)
    {
        case inputUtils::dataTypeOptions::INT:
            inputUtils::initializeVectorAndDisplay<int>();

            break;
        
        case inputUtils::dataTypeOptions::DOUBLE:
            inputUtils::initializeVectorAndDisplay<double>();

            break;

        case inputUtils::dataTypeOptions::CHAR:
            inputUtils::initializeVectorAndDisplay<char>();

            break;

        case inputUtils::dataTypeOptions::STRING:
            inputUtils::initializeVectorAndDisplay<string>();

            break;

        default:
            programUtils::Print("Operation for entered operator is not found!");
            break;
    }
}

}  // namespace additionalTasks

#endif