#include "program_utils.h"
#include <cstring>
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <stdio.h>      /* printf, scanf, NULL */
#include <cstdlib> /* malloc, free, rand */

using namespace std;

namespace programUtils {
    
    string getInputInString(string description) {
        string txt;

        cout << "\n| " << description << " |\t>>";
        cin.ignore();
        getline(cin, txt);

        return txt;
    }

    char *getInputInCharArray(string description, int length) {
        char *charArr = (char*)malloc((length + 1) * sizeof(char)); // length + 1, cause the last one is '\0'
        cout << "\n| " << description << " |\t>>";
        cin.getline(charArr, length);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        return charArr;
    }

    void Print(string txt) {
        cout << "\n| Result:\t" << txt << endl;
        cin.get();
    }

    void Print(int data) {
        Print(to_string(data));
    }

    void Print(double data) {
        Print(to_string(data));
    }

    void Print(char data) {
        stringstream ss;
        ss << data;
        string dataInString;
        ss >> dataInString;
        
        Print(dataInString);
    }

    void Print(char *data) {
        const int len = strlen(data);
        string dataToDisplay;

        for(int i = 0; i<len; i++) {
            dataToDisplay+=data[i];
        }  

        Print(dataToDisplay);
    }

    void Print(int *data, int size) {
        for (int *p = data; p < data + size; ++p) {
            cout << *p << " ";
        }
        cout << endl;
    }
} 
