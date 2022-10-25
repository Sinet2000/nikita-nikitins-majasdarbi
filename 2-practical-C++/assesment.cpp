#include <algorithm>  // lai izmanot remove erase funkcijaa
#include <array>
#include <iomanip>  // priekš tabulai
#include <iostream>
#include <limits>  // limits prieks valdiation
#include <locale>  // setLocale
#include <string>  // priekš string
#include <vector>

using namespace std;

#pragma region Menu constants

namespace menuUtils {

enum MenuItems {
    MENU_ENTER_DATA = 1,
    MENU_QUEUE_PROCESS = 2,
    MENU_STACK_PROCESS = 3,
    MENU_DOUBLE_STACK = 4,
    MENU_DISPLAY_DATA = 5,
    MENU_EXIT = 6,
    MENU_AUTHOR = 7
};

enum MenuPaddings {
    TEXT_MAIN_WIDTH = 50,
    MENU_AFTER_TEXT_WIDTH = 5,
    MENU_HEADER_LEFT_WIDTH = 43,
    MENU_HEADER_RIGHT_WIDTH = 23
};

enum DataInitMenu { CANCEL = 'c', FINISH = 'f' };

}  

#pragma endregion Menu constants

void displayMenu();
void displayMenuRow(int menuNumber = menuUtils::MENU_AUTHOR + 1, string rowTxt = " ");
int getUserMenuInput();

// main tasks
void initializeVectorFromInput(vector<int> &dataVector);

void displayAuthor();

// utils
void displayVectorData(vector<int> &dataVector);
void stringTrim(string &str);

int main() {
    int userInput;

    vector<int> initialData = {4, 5, 6, 7, 8};
    do {
        displayMenu();
        userInput = getUserMenuInput();

        switch (userInput) {
            case menuUtils::MENU_ENTER_DATA:
                cout << "Enter data" << endl;
                initializeVectorFromInput(initialData);

                cin.ignore();
                cin.get();

                break;

            case menuUtils::MENU_QUEUE_PROCESS:
                cout << "Enter Queue" << endl;
                cin.ignore();
                cin.get();

                break;

            case menuUtils::MENU_STACK_PROCESS:
                cout << "Enter Stack" << endl;
                cin.ignore();
                cin.get();

                break;

            case menuUtils::MENU_DOUBLE_STACK:
                cout << "Enter Double Stack" << endl;
                cin.ignore();
                cin.get();

                break;

            case menuUtils::MENU_DISPLAY_DATA:
                cout << "Display Data" << endl;
                cin.ignore();
                cin.get();

                break;

            case menuUtils::MENU_AUTHOR:
                displayAuthor();

                break;

            default:
                break;
        }
    } while (userInput != menuUtils::MENU_EXIT);

    return 0;
}

#pragma region Menu

void displayMenu() {
    cout << right << setfill('-') << setw(menuUtils::MENU_HEADER_LEFT_WIDTH)
         << "2. Practical work";
    cout << setfill('-') << left << setw(menuUtils::MENU_HEADER_RIGHT_WIDTH)
         << " " << setfill(' ') << endl;

    displayMenuRow();

    displayMenuRow(menuUtils::MENU_ENTER_DATA, "Enter data");
    displayMenuRow(menuUtils::MENU_QUEUE_PROCESS, "Queue");
    displayMenuRow(menuUtils::MENU_STACK_PROCESS, "Stack");
    displayMenuRow(menuUtils::MENU_DOUBLE_STACK, "Double Stack");
    displayMenuRow(menuUtils::MENU_DISPLAY_DATA, "Output a string of numbers");
    displayMenuRow(menuUtils::MENU_EXIT, "Exit");

    displayMenuRow(menuUtils::MENU_AUTHOR, "Author");
    displayMenuRow();

    cout << setfill('-')
         << setw(menuUtils::MENU_HEADER_LEFT_WIDTH +
                 menuUtils::MENU_HEADER_RIGHT_WIDTH)
         << " " << setfill(' ') << endl;
    cout << "\n";
}

void displayMenuRow(int menuNumber, string rowTxt) {
    if (menuNumber >= menuUtils::MENU_ENTER_DATA &&
        menuNumber <= menuUtils::MENU_AUTHOR)
        cout << "|\t" << menuNumber << "\t" << left
             << setw(menuUtils::TEXT_MAIN_WIDTH) << rowTxt << left
             << setw(menuUtils::MENU_AFTER_TEXT_WIDTH) << "|" << endl;
    else
        cout << "|\t"
             << " "
             << "\t" << left << setw(menuUtils::TEXT_MAIN_WIDTH) << rowTxt
             << left << setw(menuUtils::MENU_AFTER_TEXT_WIDTH) << "|" << endl;
}

#pragma endregion Menu

#pragma region Input Helpers

int getUserMenuInput() {
    int userInput;
    cout << "| Please select (1, 2, 3, 4, 5, 6, 7)| >> ";
    cin >> userInput;

    while (1) {
        if (cin.fail() || (userInput > menuUtils::MENU_AUTHOR ||
                           userInput < menuUtils::MENU_ENTER_DATA)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "| !!! Incorrect selection! Enter int value from 1 to 7 ! |"
                 << endl;
            cout << "| Please select (1, 2, 3, 4, 5, 6, 7) |\t>>";
            cin >> userInput;
        }

        if (!cin.fail()) break;
    }

    return userInput;
}

#pragma endregion Input Helpers

void initializeVectorFromInput(vector<int> &dataVector) {
    vector<int> initialData = dataVector;
    displayVectorData(dataVector);
    cout << "|\t Data initialization :" << endl;
    cout << "|\t Enter int type data. [{\"f\" - to finish}, {\"c\" - to cancel}]" << endl;

    bool isFinish = true, isCancel = false;
    int addedCount = 1;
    string userInput = "";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do {
        cout << "|\t [" << addedCount << "] : ";
        getline(cin, userInput);
        stringTrim(userInput);

        isFinish = userInput.length() == 1 &&  tolower(userInput[0]) == (char)menuUtils::FINISH;
        isCancel = userInput.length() == 1 && tolower(userInput[0]) == (char)menuUtils::CANCEL;

        if (!isFinish && !isCancel) {

            try
            {
                // I am exp problems if it is one digit number
                // cout << "|\t User Input: '" << userInput << "'" << endl;
                int i = userInput.length() == 1 && isdigit(userInput[0]) ? userInput[0] - '0' : std::stoi(userInput);
                dataVector.push_back(i);
                addedCount++;
            }
            catch (const std::invalid_argument &e) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "|\t Error: " << e.what() << "\t Try Again!"<<endl;;
            }
            
        }

    } while (!isFinish && !isCancel);

    displayVectorData(dataVector);
}

void displayAuthor() {
    cout << "|\t"
         << " " << left << setw(30) << "Darba autors:" << left << setw(30)
         << "Nikita Nikitins" << endl;
    cout << "|\t"
         << " " << left << setw(30) << "Datums:" << left << setw(30)
         << "24/10/2022" << endl;

    cin.ignore();
    cin.get();
}

void displayVectorData(vector<int> &dataVector) {
    cout << "|\t Current data in vector: ";
    for (std::vector<int>::iterator it = dataVector.begin(); it != dataVector.end(); ++it) {
        cout << *it << ", ";
    }

    cout << endl;
}

void stringTrim(string &str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}