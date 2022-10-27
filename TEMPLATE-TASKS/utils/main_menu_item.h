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

   public:
    MainMenuItem(/* args */);
    MainMenuItem(std::string initTitle, int initIndex, bool isTerminatingItem = false);
    MainMenuItem(std::string initTitle, void (*initEventCallbackPtr)(),
                 int initIndex, bool isTerminatingItem = false);

    std::string getTitle();

    int getIndex();

    void onEventCallbackPerform();
    
    bool getIsTerminatingItem();
};

#endif