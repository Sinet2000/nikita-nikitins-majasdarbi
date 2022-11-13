
#ifndef __OUTPUT_UTILS_H
#define __OUTPUT_UTILS_H

#include <iostream>
#include <string>

using namespace std;

namespace outputUtils {

    void printTxtRed(string txt, bool addNewLineBeg = true) {
        if (addNewLineBeg)
            cout << endl;

        cout << "\x1B[31m" <<  txt << "\033[0m";
    }

    void printTxtYellow(string txt, bool addNewLineBeg = true) {
        if (addNewLineBeg)
            cout << endl;

        cout << "\x1B[33m" <<  txt << "\033[0m";
    }



    void printTxtGreen(string txt, bool addNewLineBeg = true) {
        if (addNewLineBeg)
            cout << endl;

        std::cout << "\n\n\t\t\x1B[32m" + txt  + "\033[0m" << std::endl;
    }

};  // namespace vectorUtils

#endif