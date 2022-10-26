#ifndef main_menu_item_h
#define main_menu_item_h

#include <stdio.h>

#include <string>

class MainMenuItem {
   private:
    std::string title;
    int index = 0;
    void (*eventCallbackPtr)() = nullptr;

   public:
    MainMenuItem(/* args */);
    MainMenuItem(std::string initTitle, int initIndex);
    MainMenuItem(std::string initTitle, void (*initEventCallbackPtr)(),
                 int initIndex);

    std::string getTitle();

    int getIndex();

    void onEventCallbackPerform();
};

#endif