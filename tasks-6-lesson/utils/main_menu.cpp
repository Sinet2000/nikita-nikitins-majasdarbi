#include "main_menu.h"
#include "input_validators.h"

#include <stdio.h>
#include <string>
#include <iomanip>

#include <iostream>

MainMenu::MainMenu() {}

MainMenu::MainMenu(std::string initHeader) {
    hasHeader = true;
    header = initHeader;
}

MainMenu::MainMenu(std::string initHeader, void (*initCallback)(int)) {
    // Set header and header flag
    hasHeader = true;
    header = initHeader;

    // Set global callback
    globalCallbackPtr = initCallback;
}

MainMenu::MainMenu(void (*initCallback)(int)) {
    // Set global callback
    globalCallbackPtr = initCallback;
}

void MainMenu::addItem(std::string title, bool isTerminatingItem) {
    menuItems.push_back(new MainMenuItem(title, count, isTerminatingItem));

    count++;
}

void MainMenu::addItem(std::string title, void (*funcPtr)(), bool isTerminatingItem) {
    menuItems.push_back(new MainMenuItem(title, funcPtr, count, isTerminatingItem));

    count++;
}

void MainMenu::addItem(std::string title, void (*funcPtr)(int & number), int & eventParam, bool isTerminatingItem) {
    menuItems.push_back(new MainMenuItem(title, funcPtr, eventParam, count, isTerminatingItem));

    count++;
}

void MainMenu::addItem(std::string title, void (*funcPtr)(std::string & callbackParamType, bool & boolParamType), std::string & eventParam, bool & boolParam, bool isTerminatingItem) {
    menuItems.push_back(new MainMenuItem(title, funcPtr, eventParam, boolParam, count, isTerminatingItem));

    count++;
}

void MainMenu::addItem(std::string title, void (*funcPtr)(std::string & callbackParamType), std::string & eventParam, bool isTerminatingItem) {
    menuItems.push_back(new MainMenuItem(title, funcPtr, eventParam, count, isTerminatingItem));

    count++;
}

void MainMenu::addItem(std::string title, void (*funcPtr)(std::string & callbackParamType1, std::string & callbackParamType2), std::string & eventParam1, std::string & eventParam2, bool isTerminatingItem) {
    menuItems.push_back(new MainMenuItem(title, funcPtr, eventParam1, eventParam2, count, isTerminatingItem));

    count++;
}

void MainMenu::addItem(std::string title, void (*funcPtr)(char * callbackParamType), char * eventParam, bool isTerminatingItem) {
    menuItems.push_back(new MainMenuItem(title, funcPtr, eventParam, count, isTerminatingItem));

    count++;
}

void MainMenu::addItem(std::string title, void (*funcPtr)(char * callbackParamType, bool & boolParamType), char * eventParam, bool & boolParam, bool isTerminatingItem) {
    menuItems.push_back(new MainMenuItem(title, funcPtr, eventParam, boolParam, count, isTerminatingItem));

    count++;
}

void MainMenu::addItem(std::string title, void (*funcPtr)(char * callbackParamCharType, std::string & callbackParamStringType, bool & boolParamType), char * eventParamChar, std::string & eventParamString, bool & boolParam, bool isTerminatingItem) {
    menuItems.push_back(new MainMenuItem(title, funcPtr, eventParamChar, eventParamString, boolParam, count, isTerminatingItem));

    count++;
}

// void MainMenu::addItem(std::string title, void (MainMenuRunner::*funcPtr)(), bool isTerminatingItem) {
//     cout <<"title menuRunner: " << title <<endl;
//     cout << funcPtr <<endl;

//     menuItems.push_back(new MainMenuItem(title, funcPtr, count, isTerminatingItem));

//     count++;
// }

void MainMenu::runProgram() {
    int option = 0;
    bool terminateProgram = false;

    do
    {
        displayMenuStyled();

        option = getMenuSelectionAndExecute();

        if (option > -1 && option < menuItems.size())
            terminateProgram = menuItems[option]->getIsTerminatingItem();

    } while (!terminateProgram);
}

int MainMenu::getMenuSelectionAndExecute() {
    int option = inputValidatorsUtils::getIntInput("\nSelect menu item: ");

    if (option < 0 || option >= menuItems.size()) {
        std::cout << "Not a valid selection.  Please try again." << std::endl;
    } else {
        menuItems[option]->onEventCallbackPerform();

        if (globalCallbackPtr != nullptr) globalCallbackPtr(option);
    }

    return option;
}

void MainMenu::displayMenuStyled() {

    // Display header
        std::cout << std::right << std::setfill('-') << std::setw(MenuPaddings::MENU_HEADER_LEFT_WIDTH)
            << (hasHeader ? header : " ");
        std::cout << std::setfill('-') << std::left << std::setw(MenuPaddings::MENU_HEADER_RIGHT_WIDTH)
            << " " << std::setfill(' ') << std::endl;

        // Empty row with border (rigt, left)
        displayMenuRow(0, " ", true);

        for (int i = 0; i < menuItems.size(); i++)
            displayMenuRow(i, menuItems[i]->getTitle());

        displayMenuRow(0, " ", true);

        std::cout << std::setfill('-')
            << std::setw(MenuPaddings::MENU_HEADER_LEFT_WIDTH +
                    MenuPaddings::MENU_HEADER_RIGHT_WIDTH)
            << " " << std::setfill(' ') << std::endl;
        std::cout << "\n";
}

void MainMenu::displayMenuRow(int menuNumber, std::string rowTxt, bool isDescriptiveRow) {

    if (!isDescriptiveRow) {
        std::cout << "|\t" << menuNumber << "\t" << std::left
             << std::setw(MenuPaddings::TEXT_MAIN_WIDTH) << rowTxt << std::left
             << std::setw(MenuPaddings::MENU_AFTER_TEXT_WIDTH) << "|" << std::endl;
    } 
    else {
        std::cout << "|\t"
             << " "
             << "\t" << std::left << std::setw(MenuPaddings::TEXT_MAIN_WIDTH) << rowTxt
             << std::left << std::setw(MenuPaddings::MENU_AFTER_TEXT_WIDTH) << "|" << std::endl;
    }
}