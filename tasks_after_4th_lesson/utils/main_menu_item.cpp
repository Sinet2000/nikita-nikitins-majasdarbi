#include "main_menu_item.h"

MainMenuItem::MainMenuItem() {

    title = "NULL";
}

MainMenuItem::MainMenuItem(std::string initTitle, int initIndex) {

    title = initTitle;

    index = initIndex;
}

MainMenuItem::MainMenuItem(std::string initTitle, void(*initEventCallbackPtr)(), int initIndex) {
   
    title = initTitle;
    
    eventCallbackPtr = initEventCallbackPtr;
    
    index = initIndex;
}

int MainMenuItem::getIndex() {
    return index;
}

std::string MainMenuItem::getTitle() {
    return title;
}

void MainMenuItem::onEventCallbackPerform() {
    // Perform callback if exists
    if (eventCallbackPtr != nullptr) eventCallbackPtr();
}