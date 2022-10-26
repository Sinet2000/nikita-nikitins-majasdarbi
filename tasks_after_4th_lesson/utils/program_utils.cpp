#include "program_utils.h"
#include <iostream>
#include <limits>
using namespace std;

namespace ProgramUtils{
    
    string getInputInString(string description) {
        string txt;

        cout << "\n| " << description << " |\t>>";
        cin.ignore();
        getline(cin, txt);

        return txt;
    }

    void displayString(string txt) {
        cout << "\n| Result:\t" << txt;
        cin.get();
    }

    void swap(char *a, char *b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
} 
