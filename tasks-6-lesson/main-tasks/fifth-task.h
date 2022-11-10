#ifndef fifth_task_h
#define fifth_task_h

#include "../core-file.h"
#include "../utils/main_menu.h"
#include <cstdio>
#include <vector>
#include <iterator>  
#include <sstream>

using namespace std;

namespace mainTasks {

    void initializeDatetime(string &dateTime) {
        dateTime = inputValidatorsUtils::getTextInput("\nEnter datetime to work with: ", "13.10.2021 16:49");
    }

    void saveDatetimeToBinaryFile(string &fileName, string &dateTime) {
        cout << "\nWriting to file..." <<endl;

        const int txtArrLength = fileName.length() + 1;
        char *charArr = (char*)malloc((txtArrLength) * sizeof(char));

        fileUtils::writeArrToFile(fileName, charArr, txtArrLength, true);
        cout << "\nWriting finished." <<endl;
    }

    void readAndDisplayBinaryFileContent(string &fileName, string &dateTime) {
        vector<char> fileContent = fileUtils::readArrFromFile<char>(fileName, true);
        ostringstream stream;

        cout << "\nFile " << fileName << " content: " <<endl;
        if(!fileContent.empty()){
            copy(fileContent.begin(), fileContent.end()-1, ostream_iterator<int>(stream," "));
            stream << fileContent.back();
            dateTime = stream.str();
        }
        cout<< stream.str() <<endl;
    }

    void datetimeManagerInBinFile() {
        string dateTime = "13.10.2021 16:49";
        string fileName = "file-5uzd.bin";

        MainMenu mainProgram("Tasks after 6th Lesson");

        mainProgram.addItem("Set Date Time", &initializeDatetime, dateTime);
        mainProgram.addItem("Save to Binary File", &saveDatetimeToBinaryFile, fileName, dateTime);
        mainProgram.addItem("Display data from Binary File", &readAndDisplayBinaryFileContent, fileName, dateTime);

        mainProgram.addItem("Exit", true);

        mainProgram.runProgram();
    }

} // namespace mainTasks


#endif