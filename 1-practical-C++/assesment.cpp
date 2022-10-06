#include <iostream>
#include <iomanip> // priekš tabulai
#include <limits> // limits prieks valdiation
#include <string> // priekš string 
#include <locale> // setLocale 

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

// par wcin
// https://www.programiz.com/cpp-programming/library-function/iostream/wcin

// menu helpers
void displayMenu(wchar_t *userText);
void displayMenuRow(int menuNumber = 7, std::string rowTxt = " ");
int getUserMenuInput();

// menu main
void displayTextIsEvenOrOdd(wchar_t *currentTxt);
void displayUserTextSum(wchar_t *currentTxt);
void calcTextLengthFactorial(wchar_t *currentTxt);
void displayTxtReverse(wchar_t *currentTxt);
void displayAuthor();



int main() {
    // from Locales and code pages supported https://www.ibm.com/docs/en/radfws/9.6.1?topic=overview-locales-code-pages-supported
    setlocale(LC_CTYPE, "lv_LV.1257");
    //wcin.imbue(locale("lv_LV.1257"));
    //wcout.imbue(locale("lv_LV.1257"));

    wchar_t userText[200] = L"Programmas ir jaraksta cilvekiem, kas tas lasis!";
    int userInput = MENU_EXIT;

    do {
        displayMenu(userText);
        userInput = getUserMenuInput();

        switch (userInput) {
        
            case MENU_NEW_TXT:
                wcout << L"| Lūdzu ievadiet jaunu tekstu |\t>>";

                // space cin ir pieņemts kā terminating symbol
                cin.ignore();
                wcin.getline(userText, 200);
                wcout << L"\n Teksts nomainīts uz >> " << userText << endl;

                // for(int i = 0; i < wcslen(userText);i++) {
                //     cout << userText[i];
                // }

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
    
    return 1;
}


void displayMenu(wchar_t  *userText) {

    cout << right << setfill('-') << setw(MENU_HEADER_LEFT_WIDTH) << "1. Praktiskais darbs";
    cout << setfill('-') << left << setw(MENU_HEADER_RIGHT_WIDTH) << " " << setfill(' ') << endl;

    displayMenuRow();

    displayMenuRow(MENU_NEW_TXT, "Ievadīt jaunu tekstu");
    displayMenuRow(MENU_TXT_LENGTH_EVEN_ODD, "Ievadīta teksta garums ir pāra vai nepāra");
    displayMenuRow(MENU_TXT_SUM, "Izvadīt 1..n (kur n = teksta garums)" );
    displayMenuRow(MENU_TXT_L_FACTORIAL, "Izvadīt n! kur n = teksta garums");
    displayMenuRow(MENU_TXT_REVERSE, "Izvadīt tekstu reversā");
    displayMenuRow(MENU_EXIT, "Beigt darbu");
    displayMenuRow(MENU_AUTHOR, "Autors");

    displayMenuRow();

    cout << setfill('-') << setw(MENU_HEADER_LEFT_WIDTH + MENU_HEADER_RIGHT_WIDTH) << " " << setfill(' ') << endl;

    cout << "\n";
}

void displayMenuRow(int menuNumber, string rowTxt) {

    if (menuNumber >= MENU_AUTHOR && menuNumber <= MENU_EXIT) 
        cout << "|\t" << menuNumber << "\t" << left << setw(TEXT_MAIN_WIDTH) << rowTxt  << left << setw(MENU_AFTER_TEXT_WIDTH) << "|" <<  endl;
    else 
        cout << "|\t" << " " << "\t" << left << setw(TEXT_MAIN_WIDTH) << rowTxt  << left << setw(MENU_AFTER_TEXT_WIDTH) << "|" <<  endl;
}

int getUserMenuInput() {

    int userInput;
    cout << "| Lūdzu izvēlieties (0, 1, 2, 3, 4, 5, 6) |\t>>";
    cin >> userInput;

    while (1) {
        if (cin.fail() || (userInput < MENU_AUTHOR || userInput > MENU_EXIT)) {
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "| !!! Nav korekta izvēlē! Ievadiet int vērtību no 0 līdz 6 ! |" << endl;
            cout << "| Lūdzu izvēlieties (0, 1, 2, 3, 4, 5, 6) |\t>>";
            cin >> userInput;
        }

        if(!cin.fail() && (userInput >= MENU_AUTHOR && userInput <= MENU_EXIT))
            break;
    }

    return userInput;
}

void displayTextIsEvenOrOdd(wchar_t *currentTxt) {
    if (wcslen(currentTxt) % 2 == 0)
        cout << "\n Teksta garums ir pāra skaitlis!" << endl;
    else 
        cout << "\n Teksta garums ir nepāra skaitlis!" << endl;

    cin.ignore();
    cin.get();
}

void displayUserTextSum(wchar_t *currentTxt) {
    
    int sum = 0;
    for(int i = 1; i <= wcslen(currentTxt); i++) {
        sum += i;
    }

    cout << "\n Summa ir: " << sum << endl;
    
    cin.ignore();
    cin.get();
}

void calcTextLengthFactorial(wchar_t *currentTxt) {

    unsigned long long factorialProduct = 1;
    for(int i = 1; i <= wcslen(currentTxt); i++) {
        factorialProduct *= i;
    }

    cout << "\n Faktoriāls ir: " << factorialProduct << endl;
    
    cin.ignore();
    cin.get();
}

void displayTxtReverse(wchar_t *currentTxt) {

    string reverseTxt = "";
    for(int i = wcslen(currentTxt) - 1; i >= 0; i--) {
        reverseTxt += currentTxt[i];
    }

    cout << "\n Teksts reversā: " << reverseTxt << endl;
    
    cin.ignore();
    cin.get();
}

void displayAuthor() {
    cout << "|\t" << " " << left << setw(30) << "Darba autors:"  << left << setw(30) << "Nikita Nikitins" <<  endl;
    cout << "|\t" << " " << left << setw(30) << "Datums:"  << left << setw(30) << "03/10/2022" <<  endl;
    
    cin.ignore();
    cin.get();
}