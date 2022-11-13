#ifndef _FIRST_ADDIT_H
#define _FIRST_ADDIT_H

#include "../core-file.h"
#include <regex>
#include <cstdio>

using namespace std;

namespace additionalTasks {

    enum MenuItems {
        INIT = 1,
        DISPLAY_FILE_NAME = 2,
        COMBINE = 3,
        DELETE_FILE = 4,
        MENU_EXIT = 5
    };
    void displayMenu();

    void initNewFileWithContent(string &newFileName, bool &isProgramFinishAllowed);
    void displayNewFileName(string &newFileName);
    void combineFileWithFirstProgramFile(string &newFileName);
    void deleteNewFile(string &newFileName);
    bool checkIsProgramFinishAllowed(string &newFileName);

    void getTextToFile(string &newFileName);
    bool setNewFileName(string &newFileName);
    void checkAndFixTxtFileExt(string &newFileName);

    
    void taskMenuRunnerFirst() {
        string newFileName = "";
        
        int userInput;
        bool isProgramFinishAllowed = false;

        do
        {
            displayMenu();
            userInput = inputValidatorsUtils::getUserMenuInput("\nSelect from menu: (1, 2, 3 or 4):\t");

            switch (userInput) {
                case INIT:
                    initNewFileWithContent(newFileName, isProgramFinishAllowed);

                    cin.ignore();
                    cin.get();

                    break;

                case DISPLAY_FILE_NAME:
                    displayNewFileName(newFileName);

                    cin.ignore();
                    cin.get();

                    break;

                case COMBINE:
                    combineFileWithFirstProgramFile(newFileName);

                    cin.ignore();
                    cin.get();

                    break;

                case DELETE_FILE:
                    deleteNewFile(newFileName);

                    cin.ignore();
                    cin.get();

                    break;
                
                case MENU_EXIT:
                    isProgramFinishAllowed = checkIsProgramFinishAllowed(newFileName);

                    cin.ignore();
                    cin.get();

                    break;

                default:
                    cout << "\nIncorrect menu item selection. Please try again!" <<endl;
                    break;
            }

        } while (userInput != MENU_EXIT && !isProgramFinishAllowed);
        
    }

    void initNewFileWithContent(string &newFileName, bool &isProgramFinishAllowed) {

        if(!setNewFileName(newFileName)) {
            outputUtils::printTxtYellow("Initialization was cancelled!");
            return;
        }

        if(!fileUtils::fileExists(newFileName)) {
            getTextToFile(newFileName);
            isProgramFinishAllowed = false;

        } else {
            outputUtils::printTxtGreen("File already exists! Please, enter another name");
        }

    }

    void displayNewFileName(string &newFileName) {
        if (!fileUtils::fileExists(newFileName))
            outputUtils::printTxtYellow("The new file wasn't created");
        else 
            outputUtils::printTxtGreen(newFileName);
    }

    void combineFileWithFirstProgramFile(string &newFileName) {

        if (!fileUtils::fileExists(newFileName) || !fileUtils::fileExists(ProgramConstants::FIRST_PROGRAM_FILENAME)) {
            outputUtils::printTxtRed("The one of files wasn't found!");
            return;
        }

        vector<char> newFileContent = fileUtils::readArrFromFile<char>(newFileName);
        const size_t contentLength = newFileContent.size();
        char *newFileContentArr = programUtils::vectorToArr(newFileContent, contentLength);

        

        fileUtils::writeArrToFile<char>(ProgramConstants::FIRST_PROGRAM_FILENAME, newFileContentArr, contentLength-1, false, true);
    }

    void deleteNewFile(string &newFileName) {
        if (!fileUtils::fileExists(newFileName)) {
            outputUtils::printTxtRed("The new file wasn't created");
            return;
        }

        char *fileNameCharArr = (char*)malloc((newFileName.length() + 1) * sizeof(char));
        strcpy(fileNameCharArr, newFileName.c_str());  

        remove(fileNameCharArr);
    }

    bool checkIsProgramFinishAllowed(string &newFileName) {
        if (!fileUtils::fileExists(newFileName)) {
            return true;
        }

        outputUtils::printTxtRed("You must delete the new file, before finish!");
        bool isAllowedDeleteNewFile = inputValidatorsUtils::getBoolInput("Delete new file? [Enter (y or n)]\n:");
        if (isAllowedDeleteNewFile) {
            deleteNewFile(newFileName);
            return true;
        }

        return false;
    }

    void getTextToFile(string &newFileName) {
        string fileContent = inputValidatorsUtils::getTextInput("\nEnter content of file: \n:");

        const int fileContentLength = fileContent.length() + 1;
        char *fileContentArr = (char*)malloc((fileContentLength) * sizeof(char));
        strcpy(fileContentArr, fileContent.c_str());        

        fileUtils::writeArrToFile<char>(newFileName, fileContentArr, fileContentLength-1);
    }

    bool setNewFileName(string &newFileName) {
        const vector<string> reservedFileNames = programUtils::getReservedFileNames();

        bool isCanceled = false;
        bool isFileNameCorrect = false;
        do
        {
            string userInput = inputValidatorsUtils::getTextInput("\nEnter the name of new file or {\"c\" - to cancel}\n:");
            isCanceled = userInput.length() == 1 && tolower(userInput[0]) == (char)DefaultMenuItem::CANCEL;

            if (!isCanceled && std::find(reservedFileNames.begin(), reservedFileNames.end(), userInput) != reservedFileNames.end()) {
                outputUtils::printTxtRed("The file name is reserved, please, try again!");
                userInput.clear();
            } else {
                isFileNameCorrect = true;
                newFileName = userInput;
                checkAndFixTxtFileExt(newFileName);
            }

        } while (!isCanceled && !isFileNameCorrect);

        return !isCanceled;
    }

    void checkAndFixTxtFileExt(string &newFileName) {
        size_t foundIdx = newFileName.find('.');

        if (foundIdx == string::npos) {
            newFileName += ProgramConstants::TEXT_FILE_EXT;
        } else {
            string fileExt = newFileName.substr(foundIdx);
            outputUtils::printTxtYellow("File extension: " + fileExt + " changed to .txt");

            if (fileExt.length() > 0 && fileExt != ProgramConstants::TEXT_FILE_EXT) {
                newFileName = regex_replace(newFileName, std::regex(fileExt), ProgramConstants::TEXT_FILE_EXT);
            }
        }
    }

    void displayMenu() {
        cout << "\n\t1.Additional" << endl;
        cout << "\nSelect: " <<endl;
        cout << "[" << INIT << "]\t Izveidot jaunu failu" <<endl;
        cout << "[" << DISPLAY_FILE_NAME << "]\t Paradit jauna faila nosaukumu" <<endl;
        cout << "[" << COMBINE << "]\t Apvienot jauno failu ar pirmas programmas failu" <<endl;
        cout << "[" << DELETE_FILE << "]\t Izdzest jauno failu" <<endl;
        cout << "[" << MENU_EXIT << "]\t Beigt programmu" <<endl;
        cout << "\n";
    }
}

#endif