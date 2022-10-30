#ifndef fourth_addit_h
#define fourth_addit_h

#include "../core-file.h"
#include "../utils/main_menu.h"
#include "../utils/math_utils.h"
#include "../utils/enums/input-utils.h"

namespace additionalTasks {

void displayMinFromSelectedAndEnteredValues();
void displayMaxFromSelectedAndEnteredValues();
void displayMaxFromEnteredValuesToVector();
void displayMinFromEnteredValuesToVector();

void taskMenuRunnerFourth() {
    string _expressionString;

    MainMenu mainProgram1("5 additional");
    
    mainProgram1.addItem("Get Min From Selected", &displayMinFromSelectedAndEnteredValues);
    mainProgram1.addItem("Get Max From Selected", &displayMaxFromSelectedAndEnteredValues);

    mainProgram1.addItem("Get Min From Entered to Vector", &displayMinFromEnteredValuesToVector);
    mainProgram1.addItem("Get Max From Entered to Vector", &displayMaxFromEnteredValuesToVector);
    mainProgram1.addItem("Exit", true);

    mainProgram1.runProgram();
}


void displayMinFromSelectedAndEnteredValues() {
    inputUtils::dataTypeOptions selectedType = inputUtils::getUserSelectedDataType();

    switch (selectedType)
    {
        case inputUtils::dataTypeOptions::INT:
            inputUtils::displayMinValueFromInput<int>();

            break;
        
        case inputUtils::dataTypeOptions::DOUBLE:
            inputUtils::displayMinValueFromInput<double>();

            break;

        case inputUtils::dataTypeOptions::CHAR:
            inputUtils::displayMinValueFromInput<char>();

            break;

        case inputUtils::dataTypeOptions::STRING:
            inputUtils::displayMinValueFromInput<string>();
            break;

        default:
            programUtils::Print("Operation for entered operator is not found!");
            break;
    }
}

void displayMaxFromSelectedAndEnteredValues() {
    inputUtils::dataTypeOptions selectedType = inputUtils::getUserSelectedDataType();

    switch (selectedType)
    {
        case inputUtils::dataTypeOptions::INT:
            inputUtils::displayMaxValueFromInput<int>();

            break;
        
        case inputUtils::dataTypeOptions::DOUBLE:
            inputUtils::displayMaxValueFromInput<double>();

            break;

        case inputUtils::dataTypeOptions::CHAR:
            inputUtils::displayMaxValueFromInput<char>();

            break;

        case inputUtils::dataTypeOptions::STRING:
            inputUtils::displayMaxValueFromInput<string>();
            break;

        default:
            programUtils::Print("Operation for entered operator is not found!");
            break;
    }
}

void displayMaxFromEnteredValuesToVector() {
    vector<int> initialData = {};
    inputUtils::initializeVectorFromInput(initialData);
    int maxValue = MathUtils::max(initialData);
    programUtils::Print("Max Value:");
    programUtils::Print(maxValue);
}

void displayMinFromEnteredValuesToVector() {
    vector<int> initialData = {};
    inputUtils::initializeVectorFromInput(initialData);
    int minValue = MathUtils::min(initialData);
    programUtils::Print("Min Value:");
    programUtils::Print(minValue);
}


}  // namespace additionalTasks

#endif