#ifndef main_menu_h
#define main_menu_h

#include <stdio.h>

#include <vector>

#include "main_menu_item.h"

enum MenuPaddings {
    TEXT_MAIN_WIDTH = 50,
    MENU_AFTER_TEXT_WIDTH = 5,
    MENU_HEADER_LEFT_WIDTH = 43,
    MENU_HEADER_RIGHT_WIDTH = 23
};

class MainMenu {
   private:
    std::vector<MainMenuItem*> menuItems;

    int count = 0;

    std::string header;
    bool hasHeader = false;

    void (*globalCallbackPtr)(int) = nullptr;

    void displayMenuStyled();
    int getMenuSelectionAndExecute();

    void displayMenuRow(int menuNumber = 0, std::string rowTxt = " ", bool isDescriptiveRow = false);

   public:
    MainMenu();
    MainMenu(std::string);
    MainMenu(void (*)(int));
    MainMenu(std::string, void (*)(int));

    void addItem(std::string, bool isTerminatingItem = false);
    void addItem(std::string, void (*)(), bool isTerminatingItem = false);
    void addItem(std::string, void (*)(int &), int & eventParam, bool isTerminatingItem = false);

    void addItem(std::string, void (*)(char *), char * eventParam, bool isTerminatingItem = false);
    void addItem(std::string, void (*)(char *, bool &), char * eventParam,  bool & boolParam, bool isTerminatingItem = false);

    void addItem(std::string, void (*)(std::string &), std::string &eventParam, bool isTerminatingItem = false);
    void addItem(std::string, void (*)(std::string &, std::string &), std::string &eventParam1, std::string &eventParam2, bool isTerminatingItem = false);
    void addItem(std::string, void (*)(std::string &, bool &), std::string & eventParam, bool & boolParam, bool isTerminatingItem = false);
    
    void addItem(std::string, void (*)(char *, std::string &, bool &), char * eventParamCharArr, std::string & eventParamStr, bool & boolParam, bool isTerminatingItem = false);
    // void addItem(std::string, void (MainMenuRunner::*)(), bool isTerminatingItem = false);

    void runProgram();
};

#endif