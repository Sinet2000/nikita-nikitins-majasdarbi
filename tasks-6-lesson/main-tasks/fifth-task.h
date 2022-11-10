#ifndef fifth_task_h
#define fifth_task_h

#include "../core-file.h"
#include <cstdio>
#include <vector>

using namespace std;

namespace mainTasks {

    void datetimeManagerInBinFile() {
        string fileName = "file-task1.txt";
        vector<char> fileContent = fileUtils::readArrFromFile<char>(fileName);
        cout << "\nFile " << fileName << " content: " <<endl;
        programUtils::printVector(fileContent);

        cout << "\n\nEnter char to be replaced: ";

        char toReplace = getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        programUtils::remove(fileContent, toReplace);
        const size_t contentLength = fileContent.size();
        
        char *fileContentArr = programUtils::vectorToArr(fileContent, contentLength);
        fileUtils::writeArrToFile("file5.txt", fileContentArr, contentLength);
    }

} // namespace mainTasks


#endif