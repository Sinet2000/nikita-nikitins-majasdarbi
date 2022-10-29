#ifndef string_utils
#define string_utils

#include "program_utils.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

namespace StringUtils {

    void reverseStrAndDisplay(string &str, bool useIterators = false);
    void reverseCharArrayAndDisplay(char *charArray, bool useIterators = false);
    void reverseStr(string &str);
    void reverseStrIterators(std::string &str);
    void reverseCharArray(char *charArray);
    void reverseCharArrayIterators(char *charArray);

    void reverseStrAndDisplay(string &str, bool useIterators) {
        try
        {
            string stringToReverse = str;

            if (useIterators) {
                reverseStrIterators(stringToReverse);
            } else {
                reverseStr(stringToReverse);
            }

            programUtils::displayData(stringToReverse);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    void reverseCharArrayAndDisplay(char *charArray, bool useIterators) {
        char *charArrayToReverse = (char*)malloc(strlen(charArray));;
        strcpy(charArrayToReverse,charArray);

        if (useIterators) {
            reverseCharArrayIterators(charArrayToReverse);
        } else {
            reverseCharArray(charArrayToReverse);
        }

        programUtils::displayData(charArrayToReverse);
        free(charArrayToReverse);
    }

    void reverseStr(string &str) {
        int txtLength = str.length();
        int rightSideCharIndex = txtLength-1;
        int leftSideCharIndex = 0;

        while(leftSideCharIndex <= rightSideCharIndex) {

            std::swap(str[leftSideCharIndex], str[rightSideCharIndex]);

            leftSideCharIndex++;
            rightSideCharIndex--;
        }
    }

    void reverseStrIterators(std::string &str) {
        string initialString = str;
        str.clear();

        for(string::reverse_iterator itr=initialString.rbegin();itr!=initialString.rend();++itr) {
            str += *itr;
        }
    }

    void reverseCharArray(char *charArray) {
        const int len = strlen(charArray);

        cout << "reverse char arr" << endl;
        for (int i = 0; i < len / 2; i++) {
            std::swap(charArray[i], charArray[len - i - 1]);
        }
    }

    void reverseCharArrayIterators(char *charArray) {
        reverse(charArray, charArray + strlen(charArray)); // in algorithm library
    }

};

#endif