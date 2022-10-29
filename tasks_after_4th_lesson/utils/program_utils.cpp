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

    void Print(std::vector<char> vectorData) {
            for (std::vector<char>::iterator it = vectorData.begin(); it != vectorData.end(); ++it) {
            cout << *it;
        }
    }

    void Print(std::stack<char> stackData) {
        while (!stackData.empty()) {
            cout << stackData.top()<<", ";
            stackData.pop();
        }
        cout << endl;
    }

    void Print(std::queue<char> q) {
        while (!q.empty()) {
            cout << q.front()<<" ";
            q.pop();
        }
        cout << endl;
    }

    void swap(char *a, char *b);

    void swap(char *a, char *b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
} 
