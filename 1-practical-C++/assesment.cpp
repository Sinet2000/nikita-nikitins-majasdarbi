#include <iostream>
#include <iomanip> // priekš tabulai
#include <limits> // limits prieks valdiation
#include <string> // priekš string 
#include <locale> // setLocale 
#include <clocale>

using namespace std;

#define lv_LV

#define TEXT_MAIN_WIDTH             50
#define MENU_AFTER_TEXT_WIDTH       5
#define MENU_HEADER_LEFT_WIDTH      43
#define MENU_HEADER_RIGHT_WIDTH     23

// menu items
#define MENU_NEW_TXT                        1
#define MENU_TXT_LENGTH_EVEN_ODD            2
#define MENU_TXT_SUM                        3
#define MENU_TXT_L_FACTORIAL                4
#define MENU_TXT_REVERSE                    5
#define MENU_EXIT                           6
#define MENU_AUTHOR                         0

// par locale
//https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/#:~:text=In%20C%2B%2B%20program%20has,just%20need%20to%20import%20them.

// par cin
// https://www.programiz.com/cpp-programming/library-function/iostream/cin

// menu helpers
void displayMenu();
void displayMenuRow(int menuNumber = 7, wstring rowTxt = L" ");
int getUserMenuInput();

// menu main
void displayTextIsEvenOrOdd(wstring currentTxt);
void displayUserTextSum(wstring currentTxt);
void calcTextLengthFactorial(wstring currentTxt);
void displayTxtReverse(wstring currentTxt);
void displayAuthor();

int main() {
    // from Locales and code pages supported https://www.ibm.com/docs/en/radfws/9.6.1?topic=overview-locales-code-pages-supported
    setlocale(LC_CTYPE, "");

    wstring  userText= L"Programmas ir jaraksta cilvekiem, kas tas lasis!";
    int userInput = MENU_EXIT;

    do {
        displayMenu();
        userInput = getUserMenuInput();

        switch (userInput) {
        
            case MENU_NEW_TXT:
                cout << "| Lūdzu ievadiet jaunu tekstu |\t>>";

                // space cin ir pieņemts kā terminating symbol
                cin.ignore();
                getline(wcin, userText);
                
                wcout << L"Teksts nomainīts uz >> " << userText << endl;

                break;

            case MENU_TXT_LENGTH_EVEN_ODD:
                displayTextIsEvenOrOdd(userText);

                break;

            case MENU_TXT_SUM:
                displayUserTextSum(userText);

                break;

            case MENU_TXT_L_FACTORIAL:
                calcTextLengthFactorial(userText);

                break;

            case MENU_TXT_REVERSE:
                displayTxtReverse(userText);

                break;

            case MENU_AUTHOR:
                displayAuthor();

                break;

            default:
                break;
        }
    } 
    while (userInput != MENU_EXIT);
    
    system("PAUSE");
    return 0;
}


void displayMenu() {

    cout << right << setfill('-') << setw(MENU_HEADER_LEFT_WIDTH) << "1. Praktiskais darbs";
    cout << setfill('-') << left << setw(MENU_HEADER_RIGHT_WIDTH) << " " << setfill(' ') << endl;

    displayMenuRow();

    displayMenuRow(MENU_NEW_TXT, L"Ievadīt jaunu tekstu");
    displayMenuRow(MENU_TXT_LENGTH_EVEN_ODD, L"Ievadīta teksta garums ir pāra vai nepāra");
    displayMenuRow(MENU_TXT_SUM, L"Izvadīt 1..n (kur n = teksta garums)" );
    displayMenuRow(MENU_TXT_L_FACTORIAL, L"Izvadīt n! kur n = teksta garums");
    displayMenuRow(MENU_TXT_REVERSE, L"Izvadīt tekstu reversā");
    displayMenuRow(MENU_EXIT, L"Beigt darbu");
    displayMenuRow(MENU_AUTHOR, L"Autors");

    displayMenuRow();

    cout << setfill('-') << setw(MENU_HEADER_LEFT_WIDTH + MENU_HEADER_RIGHT_WIDTH) << " " << setfill(' ') << endl;

    cout << "\n";
}

void displayMenuRow(int menuNumber, wstring rowTxt) {

    if (menuNumber >= MENU_AUTHOR && menuNumber <= MENU_EXIT) 
        wcout << "|\t" << menuNumber << "\t" << left << setw(TEXT_MAIN_WIDTH) << rowTxt  << left << setw(MENU_AFTER_TEXT_WIDTH) << "|" <<  endl;
    else 
        wcout << "|\t" << " " << "\t" << left << setw(TEXT_MAIN_WIDTH) << rowTxt  << left << setw(MENU_AFTER_TEXT_WIDTH) << "|" <<  endl;
}

int getUserMenuInput() {

    int userInput;
    wcout << L"| Lūdzu izvēlieties (0, 1, 2, 3, 4, 5, 6)| >> ";
    cin >> userInput;

    while (1) {
        if (cin.fail() || (userInput < MENU_AUTHOR || userInput > MENU_EXIT)) {
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            wcout << L"| !!! Nav korekta izvēlē! Ievadiet int vērtību no 0 līdz 6 ! |" << endl;
            wcout << L"| Lūdzu izvēlieties (0, 1, 2, 3, 4, 5, 6) |\t>>";
            cin >> userInput;
        }

        if(!cin.fail() && (userInput >= MENU_AUTHOR && userInput <= MENU_EXIT))
            break;
    }

    return userInput;
}

void displayTextIsEvenOrOdd(wstring currentTxt) {
    if (currentTxt.length() % 2 == 0)
        wcout << L"\n Teksta garums ir pāra skaitlis!" << endl;
    else 
        wcout << L"\n Teksta garums ir nepāra skaitlis!" << endl;

    cin.ignore();
    cin.get();
}

void displayUserTextSum(wstring currentTxt) {
    
    int sum = 0;
    for(int i = 1; i <= currentTxt.length(); i++) {
        sum += i;
    }

    cout << "\n Summa ir: " << sum << endl;
    
    cin.ignore();
    cin.get();
}

void calcTextLengthFactorial(wstring currentTxt) {

    unsigned long long factorialProduct = 1;
    for(int i = 1; i <= currentTxt.length(); i++) {
        factorialProduct *= i;
    }

    wcout << L"\n Faktoriāls ir: " << factorialProduct << endl;
    
    cin.ignore();
    cin.get();
}

void displayTxtReverse(wstring currentTxt) {

    wcout << L"\n Teksts reversā: ";
    for(int i = currentTxt.length() - 1; i >= 0; i--) {
        wcout << currentTxt[i];
    }

    cout << endl;
    
    cin.ignore();
    cin.get();
}

void displayAuthor() {
    cout << "|\t" << " " << left << setw(30) << "Darba autors:"  << left << setw(30) << "Nikita Nikitins" <<  endl;
    cout << "|\t" << " " << left << setw(30) << "Datums:"  << left << setw(30) << "03/10/2022" <<  endl;
    
    cin.ignore();
    cin.get();
}