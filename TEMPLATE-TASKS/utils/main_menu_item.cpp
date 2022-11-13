#include "main_menu_item.h"

MainMenuItem::MainMenuItem() {

    _title = "NULL";
}

MainMenuItem::MainMenuItem(std::string initTitle, int initIndex, bool isTerminatingItem) {

    _title = initTitle;
    _index = initIndex;
    _isTerminatingItem = isTerminatingItem;
}

MainMenuItem::MainMenuItem(std::string initTitle, void(*initEventCallbackPtr)(), int initIndex, bool isTerminatingItem) {
   
    _title = initTitle;
    
    eventCallbackPtr = initEventCallbackPtr;
    
    _index = initIndex;
    _isTerminatingItem = isTerminatingItem;
}

int MainMenuItem::getIndex() {
    return _index;
}

std::string MainMenuItem::getTitle() {
    return _title;
}

bool MainMenuItem::onEventCallbackPerform() {
    // Perform callback if exists
    if (eventCallbackPtr != nullptr) eventCallbackPtr();
}

bool MainMenuItem::getIsTerminatingItem() {
    return _isTerminatingItem;
}