#include "program_utils.h"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

namespace programUtils {
    
    string getInputInString(string description) {
        string txt;

        cout << "\n| " << description << " |\t>>";
        cin.ignore();
        getline(cin, txt);

        return txt;
    }

    void displayData(string txt) {
        cout << "\n| Result:\t" << txt << endl;
        cin.get();
    }

    void displayData(int data) {
        displayData(to_string(data));
    }

    void displayData(double data) {
        displayData(to_string(data));
    }

    void displayData(char data) {
        stringstream ss;
        ss << data;
        string dataInString;
        ss >> dataInString;
        
        displayData(dataInString);
    }

    void swap(char *a, char *b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
} 
