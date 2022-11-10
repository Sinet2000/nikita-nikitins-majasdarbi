#ifndef third_task_h
#define third_task_h

#include "../core-file.h"
#include <cstdio>
#include <vector>

using namespace std;

namespace mainTasks {

    void countLettersInFileTxt() {
        const char *mainTxt = R""""(
The syntax highlighting engine has been significantly improved, with new features like handling non-deterministic grammars, multi-line constructs, lazy embeds and syntax inheritance. 
Memory usage has been reduced, and load times are faster than ever.
Eat snack.
Write code.
Eat snack.
        )"""";

        const string fileName = "file4.txt";
        if(!fileUtils::fileExists(fileName))
            fileUtils::writeArrToFile(fileName, mainTxt, strlen(mainTxt));

        vector<char> readData = fileUtils::readArrFromFile<char>(fileName);

        int countOfLettersInTxt = 0;
        for (std::vector<char>::iterator it = readData.begin(); it != readData.end(); ++it) {
            if (isalpha(*it)) countOfLettersInTxt++;
        }

        cout << "\nCount of letters: " << countOfLettersInTxt <<endl;
    }

} // namespace mainTasks


#endif