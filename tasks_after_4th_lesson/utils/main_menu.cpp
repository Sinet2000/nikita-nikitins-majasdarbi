#include "main_menu.h"
#include "input_validators.h"

#include <stdio.h>

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

void MainMenu::addItem(std::string title) {
    menuItems.push_back(new MainMenuItem(title, count));

    count++;
}

void MainMenu::addItem(std::string title, void (*funcPtr)()) {
    menuItems.push_back(new MainMenuItem(title, funcPtr, count));

    count++;
}

// Print MainMenu and allow for selection
void MainMenu::displayMenu() {
    // Initialize option
    int option = 0;

    // Print MainMenu header if supplied
    if (hasHeader) std::cout << header << "\n" << std::endl;

    // Enumerate in print options
    for (int i = 0; i < menuItems.size(); i++)
        std::cout << i << ".) " << menuItems[i]->getTitle() << std::endl;

    option = InputValidatorsUtils::getUserMenuInput();

    // Check if selection is valid
    if (option < 0 && option >= menuItems.size()) {
        // Print selection invalid and print MainMenu again
        std::cout << "Not a valid selection.  Please try again." << std::endl;
        displayMenu();
    } else {
        // Call MainMenu item's callback
        menuItems[option]->onEventCallbackPerform();

        // If global callback supplied, call that with index as parameter
        if (globalCallbackPtr != nullptr) globalCallbackPtr(option);
    }
}