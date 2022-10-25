#include <algorithm>  // lai izmanot remove erase funkcijaa
#include <array>
#include <iomanip>  // priekš tabulai
#include <iostream>
#include <limits>  // limits prieks valdiation
#include <locale>  // setLocale
#include <string>  // priekš string

using namespace std;

#define lv_LV

#define TEXT_MAIN_WIDTH 50
#define MENU_AFTER_TEXT_WIDTH 5
#define MENU_HEADER_LEFT_WIDTH 43
#define MENU_HEADER_RIGHT_WIDTH 23

// menu items
#define MENU_NEW_TXT 1
#define MENU_TXT_LENGTH_EVEN_ODD 2
#define MENU_TXT_SUM 3
#define MENU_TXT_L_FACTORIAL 4
#define MENU_TXT_REVERSE 5
#define MENU_EXIT 6
#define CHECK_PALINDROM 7
#define ERASE_A 8
#define COUNT_NUMERIC 9
#define MENU_AUTHOR 0

#pragma region Menu and Input helpers

void displayMenu();
void displayMenuRow(int menuNumber = 10, string rowTxt = " ");
int getUserMenuInput();

#pragma endregion Menu and Input helpers

#pragma region Main Tasks

void displayTextIsEvenOrOdd(string currentTxt);
void displayUserTextSum(string currentTxt);
void calcTextLengthFactorial(string currentTxt);
void displayTxtReverse(string currentTxt);

#pragma endregion Main Tasks

#pragma region Additional Tasks

bool isPalindrom(string currentTxt);
void eraseFromTextIfTimesMet(string &currentTxt, char charToErase,
                             int countCondition);
void countNumericInTxt(string currentTxt);

#pragma endregion Additional Tasks

#pragma region Utils

void swap(char *a, char *b);
string reversedText(string txt);
void displayAuthor();

#pragma endregion Utils

int main() {
    // from Locales and code pages supported
    // https://www.ibm.com/docs/en/radfws/9.6.1?topic=overview-locales-code-pages-supported
    setlocale(LC_ALL, "lv_LV");

    string userText = "Programmas ir jaraksta cilvekiem, kas tas lasis!";
    int userInput = MENU_EXIT;

    do {
        displayMenu();
        userInput = getUserMenuInput();

        switch (userInput) {
            case MENU_NEW_TXT:
                cout << "| Lūdzu ievadiet jaunu tekstu |\t>>";

                // space cin ir pieņemts kā terminating symbol
                cin.ignore();
                getline(cin, userText);

                cout << "Teksts nomainīts uz >> " << userText << endl;

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

            case CHECK_PALINDROM:
                cout << (isPalindrom(userText) ? "Teksts ir palindroms"
                                               : "Teksts nav palindroms!")
                     << endl;
                cin.ignore();
                cin.get();

                break;

            case ERASE_A:
                eraseFromTextIfTimesMet(userText, 'a', 3);

                break;

            case COUNT_NUMERIC:
                countNumericInTxt(userText);

                break;

            case MENU_AUTHOR:
                displayAuthor();

                break;

            default:
                break;
        }
    } while (userInput != MENU_EXIT);

    system("PAUSE");
    return 0;
}

#pragma region Menu

void displayMenu() {
    cout << right << setfill('-') << setw(MENU_HEADER_LEFT_WIDTH)
         << "1. Praktiskais darbs";
    cout << setfill('-') << left << setw(MENU_HEADER_RIGHT_WIDTH) << " "
         << setfill(' ') << endl;

    displayMenuRow();

    displayMenuRow(MENU_NEW_TXT, "Ievadīt jaunu tekstu");
    displayMenuRow(MENU_TXT_LENGTH_EVEN_ODD,
                   "Ievadīta teksta garums ir pāra vai nepāra");
    displayMenuRow(MENU_TXT_SUM, "Izvadīt 1..n (kur n = teksta garums)");
    displayMenuRow(MENU_TXT_L_FACTORIAL, "Izvadīt n! kur n = teksta garums");
    displayMenuRow(MENU_TXT_REVERSE, "Izvadīt tekstu reversā");
    displayMenuRow(MENU_EXIT, "Beigt darbu");

    // extra tasks
    displayMenuRow(CHECK_PALINDROM, "Vai ir polindroms");
    displayMenuRow(ERASE_A, "Izdzēst a char");
    displayMenuRow(COUNT_NUMERIC, "Saskaitīt numeric simbolus");

    displayMenuRow(MENU_AUTHOR, "Autors");
    displayMenuRow();

    cout << setfill('-')
         << setw(MENU_HEADER_LEFT_WIDTH + MENU_HEADER_RIGHT_WIDTH) << " "
         << setfill(' ') << endl;
    cout << "\n";
}

void displayMenuRow(int menuNumber, string rowTxt) {
    if (menuNumber >= MENU_AUTHOR && menuNumber <= COUNT_NUMERIC)
        cout << "|\t" << menuNumber << "\t" << left << setw(TEXT_MAIN_WIDTH)
             << rowTxt << left << setw(MENU_AFTER_TEXT_WIDTH) << "|" << endl;
    else
        cout << "|\t"
             << " "
             << "\t" << left << setw(TEXT_MAIN_WIDTH) << rowTxt << left
             << setw(MENU_AFTER_TEXT_WIDTH) << "|" << endl;
}

#pragma endregion Menu

#pragma region Input Helpers

int getUserMenuInput() {
    int userInput;
    cout << "| Lūdzu izvēlieties (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)| >> ";
    cin >> userInput;

    while (1) {
        if (cin.fail() ||
            (userInput < MENU_AUTHOR || userInput > COUNT_NUMERIC)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "| !!! Nav korekta izvēlē! Ievadiet int vērtību no 0 līdz "
                    "9 ! |"
                 << endl;
            cout << "| Lūdzu izvēlieties (0, 1, 2, 3, 4, 5, 6, 7, 8, 9) |\t>>";
            cin >> userInput;
        }

        if (!cin.fail() &&
            (userInput >= MENU_AUTHOR && userInput <= COUNT_NUMERIC))
            break;
    }

    return userInput;
}

#pragma endregion Input Helpers

#pragma region Main Tasks
void displayTextIsEvenOrOdd(string currentTxt) {
    if (currentTxt.length() % 2 == 0)
        cout << "\n Teksta garums ir pāra skaitlis!" << endl;
    else
        cout << "\n Teksta garums ir nepāra skaitlis!" << endl;

    cin.ignore();
    cin.get();
}

void displayUserTextSum(string currentTxt) {
    int sum = 0;
    for (int i = 1; i <= currentTxt.length(); i++) {
        sum += i;
    }

    cout << "\n Summa ir: " << sum << endl;

    cin.ignore();
    cin.get();
}

void calcTextLengthFactorial(string currentTxt) {
    unsigned long long factorialProduct = 1;
    for (int i = 1; i <= currentTxt.length(); i++) {
        factorialProduct *= i;
    }

    cout << "\n Faktoriāls ir: " << factorialProduct << endl;

    cin.ignore();
    cin.get();
}

void displayTxtReverse(string currentTxt) {
    cout << "\n Teksts reversā: ";
    for (int i = currentTxt.length() - 1; i >= 0; i--) {
        cout << currentTxt[i];
    }

    cout << endl;

    cin.ignore();
    cin.get();
}

#pragma endregion Main Tasks

void displayAuthor() {
    cout << "|\t"
         << " " << left << setw(30) << "Darba autors:" << left << setw(30)
         << "Nikita Nikitins" << endl;
    cout << "|\t"
         << " " << left << setw(30) << "Datums:" << left << setw(30)
         << "03/10/2022" << endl;

    cin.ignore();
    cin.get();
}

// extra tasks
bool isPalindrom(string currentTxt) {
    return currentTxt == reversedText(currentTxt);
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

string reversedText(string txt) {
    int length = txt.length();
    for (int i = 0; i < length / 2; i++) swap(txt[i], txt[length - i - 1]);

    return txt;
}

void eraseFromTextIfTimesMet(string &currentTxt, char charToErase,
                             int countCondition) {
    cout << "\n Teksts pašlaik ir: " << currentTxt << endl;

    int count = 0;
    string newTxt = "";

    for (char c : currentTxt) {
        // nezinu, vai ir jaizmanto tolower ??? (bija defineets tikai '')

        if (c == charToErase) {
            count++;
            continue;
        }

        newTxt += c;
    }

    // #1 Method using existing functions in C++ 11
    // if (count > countCondition)
    //     currentTxt.erase(remove(currentTxt.begin(), currentTxt.end(),
    //     charToErase), currentTxt.end());

    // pārsniedz nozīmē ja ir vairāk par n ? vai n ieslēdzot?
    if (count > countCondition) currentTxt = newTxt;
    cout << "\n Jauns teksts: " << currentTxt << endl;

    cin.ignore();
    cin.get();
}

void countNumericInTxt(string currentTxt) {
    array<int, 10> numericFoundCountArray{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < numericFoundCountArray.size(); i++) {
        for (char c : currentTxt) {
            if (((int)(c - '0')) == i) numericFoundCountArray[i]++;
        }
    }

    cout << "\n Testēts teksts >> " << currentTxt << endl;
    cout << "rezultāts: \n" << endl;

    for (int i = 0; i < numericFoundCountArray.size(); i++) {
        cout << i << "  -  " << numericFoundCountArray[i] << 'x' << endl;
    }

    cin.ignore();
    cin.get();
}