#include "program_utils.h"
#include <cstring>
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

    void getInputInCharArray(string description, char *charArray, int length) {
        cout << "\n| " << description << " |\t>>";
        cin.ignore();
        cin.getline(charArray, length);
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

    void displayData(char *data) {
        const int len = strlen(data);
        string dataToDisplay;

        for(int i = 0; i<len; i++) {
            dataToDisplay+=data[i];
        }  

        displayData(dataToDisplay);
    }

    void swap(char *a, char *b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
} 
