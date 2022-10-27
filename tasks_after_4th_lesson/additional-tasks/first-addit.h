#ifndef first_addit_h
#define first_addit_h

#include "../core-file.h"

namespace additionalTasks
{
    
    string reverseStrIterator(std::string &str);


    string reverseStrIterator(std::string &str) {
        string reversedStr;

        // crbegin - returns a read only reverse iterator  that points to the last char
        // string:: iterator it;
        string::const_reverse_iterator strIterator = str.crbegin();
        while(strIterator != str.crend()) {
            reversedStr.append(1, *(strIterator++));
        }

        return reversedStr;
    }

} // namespace additionalTasks


#endif