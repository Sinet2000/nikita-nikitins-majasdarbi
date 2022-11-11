#ifndef fifth_task_h
#define fifth_task_h

#include <cstdio>
#include <iterator>
#include <sstream>
#include <vector>

#include "../core-file.h"
#include "../utils/main_menu.h"

using namespace std;

namespace mainTasks {

enum MenuItems {
    INITIALIZE_DATETIME = 1,
    SAVE_DATETIME_BIN = 2,
    READ_DISPLAY_BIN = 3,
    MENU_EXIT = 4,
};

void datetimeManagerInBinFile();
void initializeDatetime(string &dateTime);
void saveDatetimeToBinaryFile(const string &fileName, const string &dateTime);
void readAndDisplayBinaryFileContent(const string &fileName, string &dateTime);
void displayMenu();

void datetimeManagerInBinFile() {
    string dateTime = "13.10.2021 16:49";
    const string fileName = "file-5uzd.bin";

    int userInput;

    do
    {
        displayMenu();
        userInput = inputValidatorsUtils::getUserMenuInput("\nSelect from menu: (1, 2, 3 or 4):\t");

        switch (userInput) {
            case INITIALIZE_DATETIME:
                initializeDatetime(dateTime);

                cin.ignore();
                cin.get();

                break;

            case SAVE_DATETIME_BIN:
                saveDatetimeToBinaryFile(fileName, dateTime);

                cin.ignore();
                cin.get();

                break;

            case READ_DISPLAY_BIN:
                readAndDisplayBinaryFileContent(fileName, dateTime);

                cin.ignore();
                cin.get();

                break;

            default:
                cout << "\nIncorrect menu item selection. Please try again!" <<endl;
                break;
        }

    } while (userInput != MENU_EXIT);
    
}

void initializeDatetime(string &dateTime) {
    dateTime = inputValidatorsUtils::getTextInput(
        "\nEnter datetime to work with: ", "13.10.2021 16:49");
}

void saveDatetimeToBinaryFile(const string &fileName, const string &dateTime) {
    cout << "\nWriting to file..." << endl;

    const int txtArrLength = dateTime.length() + 1;
    char *charArr = (char *)malloc((txtArrLength) * sizeof(char));
    strcpy(charArr, dateTime.c_str());

    fileUtils::writeArrToFile(fileName, charArr, txtArrLength, true);
    cout << "\nWriting finished." << endl;
}

void readAndDisplayBinaryFileContent(const string &fileName, string &dateTime) {
    vector<char> fileContent = fileUtils::readArrFromFile<char>(fileName, true);
    dateTime = "";

    for (std::vector<char>::iterator it = fileContent.begin(); it != fileContent.end(); ++it) {
        dateTime += *it;
    }

    cout << "\nFetched data: " << dateTime <<endl;
}

void displayMenu() {
    cout << "\n\t5.uzd Bin file Manager" << endl;
    cout << "\nSelect: " <<endl;
    cout << "[" << INITIALIZE_DATETIME << "]\t Set Datetime" <<endl;
    cout << "[" << SAVE_DATETIME_BIN << "]\t Save Datetime to bin file" <<endl;
    cout << "[" << READ_DISPLAY_BIN << "]\t Read datetime from bin file and display" <<endl;
    cout << "[" << MENU_EXIT << "]\t Exit menu" <<endl;
    cout << "\n";
}

}  // namespace mainTasks

#endif