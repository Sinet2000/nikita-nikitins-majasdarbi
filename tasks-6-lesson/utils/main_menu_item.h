#ifndef main_menu_item_h
#define main_menu_item_h

#include <stdio.h>
#include <string>

class MainMenuItem {
   private:
    std::string _title;
    int _index = 0;
    bool _isTerminatingItem = false;
    void (*eventCallbackPtr)() = nullptr;
    void (*eventCallbackPtrIntRef)(int &) = nullptr;

    void (*eventCallbackPtrCharArrRef)(char *) = nullptr;
    void (*eventCallbackPtrCharArrAndBoolRef)(char *, bool &) = nullptr;

    void (*eventCallbackPtrStringRef)(std::string &) = nullptr;
    void (*eventCallbackPtrDoubleStringRef)(std::string &, std::string &) = nullptr;
    void (*eventCallbackPtrStringAndBoolRef)(std::string &, bool &) = nullptr;

    void (*eventCallbackCharAndString)(char *, std::string &, bool &) = nullptr;

    int * _eventParamInt = nullptr;
    std::string * _eventParamString = nullptr;
    std::string * _eventParamStringAdditional = nullptr;
    char * _eventParamCharArray = nullptr;
    bool * _eventParamBool = nullptr;
    // void (MainMenuRunner::*menuRunnerEventCallbackPtr)() = nullptr;

   public:
    MainMenuItem(/* args */);
    MainMenuItem(std::string initTitle, int initIndex, bool isTerminatingItem = false);
    MainMenuItem(std::string initTitle, void (*initEventCallbackPtr)(), int initIndex, bool isTerminatingItem = false);
    MainMenuItem(std::string initTitle, void (*initEventCallbackPtrIntRef)(int &numberParam), int &eventParam, int initIndex, bool isTerminatingItem = false);

    MainMenuItem(std::string initTitle, void (*initEventCallbackPtrStringRef)(std::string &stringParam), std::string &eventParam, int initIndex, bool isTerminatingItem = false);
    MainMenuItem(std::string initTitle, void (*initEventCallbackPtrStringRef)(std::string &stringParam1, std::string &stringParam2), std::string &eventParam1, std::string &eventParam2, int initIndex, bool isTerminatingItem = false);
    MainMenuItem(std::string initTitle, void (*initEventCallbackPtrStringAndBoolRef)(std::string &stringParam, bool &boolParamType), std::string &eventParam, bool &boolParam, int initIndex, bool isTerminatingItem = false);

    MainMenuItem(std::string initTitle, void (*initEventCallbackPtrCharArrRef)(char *charArrParam), char *eventParam, int initIndex, bool isTerminatingItem = false);
    MainMenuItem(std::string initTitle, void (*initEventCallbackPtrCharArrAndBoolRef)(char *charArrParam, bool &boolParamType), char *eventParam, bool &boolParam, int initIndex, bool isTerminatingItem = false);

    MainMenuItem(std::string initTitle, void (*initEventCallbackCharAndString)(char *charArrParam, std::string &stringParam, bool &boolParamType), char *eventParamChar, std::string &eventParamString, bool &boolParam, int initIndex, bool isTerminatingItem = false);
    // MainMenuItem(std::string initTitle, void (MainMenuRunner::*initEventCallbackPtr)(), int initIndex, bool isTerminatingItem = false);

    std::string getTitle();

    int getIndex();

    void onEventCallbackPerform();
    
    bool getIsTerminatingItem();
};

#endif