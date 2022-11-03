#include "main_menu_item.h"
#include <iostream>

MainMenuItem::MainMenuItem() {

    _title = "NULL";
}

MainMenuItem::MainMenuItem(std::string initTitle, int initIndex, bool isTerminatingItem) {

    _title = initTitle;
    _index = initIndex;
    _isTerminatingItem = isTerminatingItem;
}

MainMenuItem::MainMenuItem(std::string initTitle, void(*initEventCallbackPtr)(), int initIndex, bool isTerminatingItem) : MainMenuItem::MainMenuItem(initTitle, initIndex, isTerminatingItem) {
   
    eventCallbackPtr = initEventCallbackPtr;
}

MainMenuItem::MainMenuItem(std::string initTitle, void(*initEventCallbackPtrIntRef)(int &number), int &eventParam, int initIndex, bool isTerminatingItem) : MainMenuItem::MainMenuItem(initTitle, initIndex, isTerminatingItem) {
   
   _eventParamInt = &eventParam;
        
    eventCallbackPtrIntRef = initEventCallbackPtrIntRef;
}

MainMenuItem::MainMenuItem(std::string initTitle, void(*initEventCallbackPtrStringRef)(std::string &stringParam), std::string &eventParam, int initIndex, bool isTerminatingItem) : MainMenuItem::MainMenuItem(initTitle, initIndex, isTerminatingItem) {
   
   _eventParamString = &eventParam;
        
    eventCallbackPtrStringRef = initEventCallbackPtrStringRef;
}

MainMenuItem::MainMenuItem(std::string initTitle, void(*initEventCallbackPtrStringAndBoolRef)(std::string &stringParam, bool &boolParamType), std::string &eventParam, bool &boolParam, int initIndex, bool isTerminatingItem) : MainMenuItem::MainMenuItem(initTitle, initIndex, isTerminatingItem) {
   
   _eventParamString = &eventParam;
   _eventParamBool = &boolParam;
        
    eventCallbackPtrStringAndBoolRef = initEventCallbackPtrStringAndBoolRef;
}

MainMenuItem::MainMenuItem(std::string initTitle, void(*initEventCallbackPtrCharArrRef)(char *charArrParam), char *eventParam, int initIndex, bool isTerminatingItem) : MainMenuItem::MainMenuItem(initTitle, initIndex, isTerminatingItem) {
   
   _eventParamCharArray = eventParam;
        
    eventCallbackPtrCharArrRef = initEventCallbackPtrCharArrRef;
}

MainMenuItem::MainMenuItem(std::string initTitle, void(*initEventCallbackPtrCharArrAndBoolRef)(char *charArrParam, bool &boolParamType), char *eventParam, bool &boolParam, int initIndex, bool isTerminatingItem) : MainMenuItem::MainMenuItem(initTitle, initIndex, isTerminatingItem) {
   
   _eventParamCharArray = eventParam;
   _eventParamBool = &boolParam;
        
    eventCallbackPtrCharArrAndBoolRef = initEventCallbackPtrCharArrAndBoolRef;
}

MainMenuItem::MainMenuItem(std::string initTitle, void (*initEventCallbackCharAndString)(char *charArrParam, std::string &stringParam, bool &boolParamType), char *eventParamChar, std::string &eventParamString, bool &boolParam, int initIndex, bool isTerminatingItem) : MainMenuItem::MainMenuItem(initTitle, initIndex, isTerminatingItem) {
   
   _eventParamCharArray = eventParamChar;
   _eventParamString = &eventParamString;
   _eventParamBool = &boolParam;
        
    eventCallbackCharAndString = initEventCallbackCharAndString;
}

// MainMenuItem::MainMenuItem(std::string initTitle, void (MainMenuRunner::*initEventCallbackPtr)(), int initIndex, bool isTerminatingItem) : MainMenuItem::MainMenuItem(initTitle, initIndex, isTerminatingItem) {

//     menuRunnerEventCallbackPtr = initEventCallbackPtr;
// }

int MainMenuItem::getIndex() {
    return _index;
}

std::string MainMenuItem::getTitle() {
    return _title;
}

void MainMenuItem::onEventCallbackPerform() {
    // Perform callback if exists
    if (eventCallbackPtr != nullptr) eventCallbackPtr();

    if (eventCallbackPtrIntRef != nullptr && _eventParamInt != NULL) eventCallbackPtrIntRef(*_eventParamInt);

    if (eventCallbackPtrCharArrRef != nullptr && _eventParamCharArray != NULL) eventCallbackPtrCharArrRef(_eventParamCharArray);
    if (eventCallbackPtrCharArrAndBoolRef != nullptr && _eventParamCharArray != NULL && _eventParamBool != nullptr) eventCallbackPtrCharArrAndBoolRef(_eventParamCharArray, *_eventParamBool);

    if (eventCallbackPtrStringRef != nullptr && _eventParamString != NULL) eventCallbackPtrStringRef(*_eventParamString);
    if (eventCallbackPtrStringAndBoolRef != nullptr && _eventParamString != NULL && _eventParamBool != nullptr) eventCallbackPtrStringAndBoolRef(*_eventParamString, *_eventParamBool);

    if (eventCallbackCharAndString != nullptr && _eventParamString != NULL && _eventParamBool != nullptr && _eventParamCharArray != NULL) eventCallbackCharAndString(_eventParamCharArray, *_eventParamString, *_eventParamBool);
    // std::cout << "menuRunnerEventCallbackPtr" << menuRunnerEventCallbackPtr << std::endl;
    // if (menuRunnerEventCallbackPtr != nullptr) ((MainMenuItem*)this)->MainMenuItem::menuRunnerEventCallbackPtr;
}

bool MainMenuItem::getIsTerminatingItem() {
    return _isTerminatingItem;
}