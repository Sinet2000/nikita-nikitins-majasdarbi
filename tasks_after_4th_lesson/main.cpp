#include <iostream>
#include "utils/main_menu.h"

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
    
    MainMenu globalAndHeader("Tasks after 4th Lesson", &globalCallback);
    
    globalAndHeader.addItem("Option 0");
    globalAndHeader.addItem("Option 1", &option1); // You can have global callback and individual callbacks
    globalAndHeader.addItem("Option 2");
    
    globalAndHeader.displayMenu();
    
    return 0;
}
