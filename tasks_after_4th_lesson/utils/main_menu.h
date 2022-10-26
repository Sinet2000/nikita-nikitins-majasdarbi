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

   public:
    MainMenu();
    MainMenu(std::string);
    MainMenu(void (*)(int));
    MainMenu(std::string, void (*)(int));

    void addItem(std::string);
    void addItem(std::string, void (*)());

    void displayMenu();

    void displayMenuRow(int menuNumber = 0, std::string rowTxt = " ", bool isDescriptiveRow = false);
};

#endif