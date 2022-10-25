#include <iostream>
#include "main_menu.h"

void globalCallback(int option) {
    std::cout << "Global Callback | Selection: " << option << std::endl;
}

void option0() {
    std::cout << "Item Callback | Selected option 0" << std::endl;
}

void option1() {
    std::cout << "Item Callback | Selected option 1" << std::endl;
}

void option2() {
    std::cout << "Item Callback | Selected option 2" << std::endl;
}

int main(int argc, const char * argv[]) {
    
    // Menu with no header or global callback
    MainMenu defaultMenu;
    defaultMenu.addItem("Option 0", &option0);
    defaultMenu.addItem("Option 1", &option1);
    defaultMenu.addItem("Option 2", &option2);
    
    defaultMenu.displayMenu();
    
    // Menu with header and no global callback
    MainMenu headerMenu("Select an option");
    headerMenu.addItem("Option 0", &option0);
    headerMenu.addItem("Option 1", &option1);
    headerMenu.addItem("Option 2", &option2);
    
    headerMenu.displayMenu();
    
    // Menu with no header and with global callback
    MainMenu globalMenu(&globalCallback);
    globalMenu.addItem("Option 0");
    globalMenu.addItem("Option 1", &option1); // You can have global callback and individual callbacks
    globalMenu.addItem("Option 2");
    
    globalMenu.displayMenu();
    
    // Menu with header and global callbacks
    MainMenu globalAndHeader("Selection an option:", &globalCallback);
    
    globalAndHeader.addItem("Option 0");
    globalAndHeader.addItem("Option 1", &option1); // You can have global callback and individual callbacks
    globalAndHeader.addItem("Option 2");
    
    globalAndHeader.displayMenu();
    
    return 0;
}
