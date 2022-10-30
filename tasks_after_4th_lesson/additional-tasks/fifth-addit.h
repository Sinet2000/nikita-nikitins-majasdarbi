#ifndef fifth_addit_h
#define fifth_addit_h
#define MAX_TXT_LENGTH 255
#include "../core-file.h"
#include "../utils/main_menu.h"
#include "../utils/math_utils.h"

namespace additionalTasks {

void getInputToString(string &strExpression);
void calculateExpression(string &strExpression);
void displayExpression(string &strExpression);

void taskMenuRunnerFifth() {
    string _expressionString;

    MainMenu mainProgram1("5 additional");
    
    mainProgram1.addItem("Enter expression", &getInputToString, _expressionString);
    mainProgram1.addItem("Calculate expression", &calculateExpression, _expressionString);
    mainProgram1.addItem("Display expression", &displayExpression, _expressionString);

    mainProgram1.addItem("Exit", true);

    mainProgram1.runProgram();
}

void getInputToString(string &strExpression) {
    strExpression = programUtils::getInputInString("Enter expression");
    StringUtils::stringTrim(strExpression);
}

void calculateExpression(string &strExpression) {
    int result = MathUtils::getEvaluatedExpressionValue(strExpression);
    programUtils::Print(result);
}

void displayExpression(string &strExpression) {
    programUtils::Print(strExpression);
}


}  // namespace additionalTasks

#endif