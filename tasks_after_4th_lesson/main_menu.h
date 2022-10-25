#ifndef main_menu_h
#define main_menu_h

#include <stdio.h>

#include <vector>

#include "main_menu_item.h"

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
};

#endif