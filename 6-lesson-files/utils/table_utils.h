#ifndef table_utils_h
#define table_utils_h

#include <stdio.h>
#include <string>
#include <iomanip>

#include <iostream>

using namespace std;

namespace tableUtils {

    enum MenuPaddings {
        TEXT_MAIN_WIDTH = 50,
        MENU_AFTER_TEXT_WIDTH = 5,
        MENU_HEADER_LEFT_WIDTH = 43,
        MENU_HEADER_RIGHT_WIDTH = 23
    };

    void displayMenuRow(int menuNumber = 0, std::string rowTxt = " ", bool isDescriptiveRow = false);
    void displayHeader(string headerText);
    void displayFooter();

    void displayMenuRow(int menuNumber, std::string rowTxt, bool isDescriptiveRow) {

        if (!isDescriptiveRow) {
            std::cout << "|\t" << menuNumber << "\t" << std::left
                << std::setw(MenuPaddings::TEXT_MAIN_WIDTH) << rowTxt << std::left
                << std::setw(MenuPaddings::MENU_AFTER_TEXT_WIDTH) << "|" << std::endl;
        } 
        else {
            std::cout << "|\t"
                << " "
                << "\t" << std::left << std::setw(MenuPaddings::TEXT_MAIN_WIDTH) << rowTxt
                << std::left << std::setw(MenuPaddings::MENU_AFTER_TEXT_WIDTH) << "|" << std::endl;
        }
    }

    void displayHeader(string headerText) {
        std::cout << std::right << std::setfill('-') << std::setw(MenuPaddings::MENU_HEADER_LEFT_WIDTH)
            << headerText;
        std::cout << std::setfill('-') << std::left << std::setw(MenuPaddings::MENU_HEADER_RIGHT_WIDTH)
            << " " << std::setfill(' ') << std::endl;
    }

    void displayFooter() {
        std::cout << std::setfill('-')
            << std::setw(MenuPaddings::MENU_HEADER_LEFT_WIDTH +
                    MenuPaddings::MENU_HEADER_RIGHT_WIDTH)
            << " " << std::setfill(' ') << std::endl;
        std::cout << "\n";
    }

}

#endif