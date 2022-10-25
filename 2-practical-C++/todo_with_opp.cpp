// #include <algorithm>
// #include <array>
// #include <iomanip>
// #include <iostream>
// #include <limits>
// #include <locale>
// #include <string>
// #include <vector>

// using namespace std;
// // Let's make it using OOP
// // Main Class is MainApp, that will store an array of data structure, where that data structure has Menu Row Text, Menu row number, that is used for input in menu, reference on function?

// template <typename T> class MenuItem {
    
//     private:
//         string _rowText;
//         void (*_func)(string &rowText);
//         T (*_funcWithReturn)(string &rowText)
        
//     public:
//         MenuItem(string rowTxt = " ");
//         MenuItem(void (*func)(string), string rowTxt = " ");
//         MenuItem(T (*_funcWithReturn)(string &rowText), string rowTxt = " ");
// };

// class MainApp {

//     private:
//         vector<MenuItem<int>> _menuItems;


//     public:
//         MainApp();
//         void addMenuItem(string rowTxt = " ");
// };


// #pragma region Menu constants

// #define TEXT_MAIN_WIDTH 50
// #define MENU_AFTER_TEXT_WIDTH 5
// #define MENU_HEADER_LEFT_WIDTH 43
// #define MENU_HEADER_RIGHT_WIDTH 23

// #pragma endregion Menu constants

// enum menuSpacing {
//     TextMainWidth = 50,
//     MenuAfterTextWidth = 5,
//     MenuHeaderLeftWidth = 43,
//     MenuHeaderRightWidth = 23
// };

// enum menuSelection {
//     DataInput = 1,
//     QueueProcess = 2,
//     StackProcess = 3,
//     DoubleStackProcess = 4,
//     DisplayData = 5,
//     Exit = 6
// };

// void displayMenu();
// void displayMenuRow(int menuNumber = EXIT + 1, string rowTxt = " ");
// int getUserMenuInput();

// int main() { 
    
    
//     return 0;
// }

// void displayMenu() {
//     cout << right << setfill('-') << setw(MENU_HEADER_LEFT_WIDTH)
//          << "2. Practical Work";
//     cout << setfill('-') << left << setw(MENU_HEADER_RIGHT_WIDTH) << " "
//          << setfill(' ') << endl;

//     displayMenuRow();

//     displayMenuRow(MENU_NEW_TXT, "Ievadīt jaunu tekstu");
//     displayMenuRow(MENU_TXT_LENGTH_EVEN_ODD,
//                    "Ievadīta teksta garums ir pāra vai nepāra");
//     displayMenuRow(MENU_TXT_SUM, "Izvadīt 1..n (kur n = teksta garums)");
//     displayMenuRow(MENU_TXT_L_FACTORIAL, "Izvadīt n! kur n = teksta garums");
//     displayMenuRow(MENU_TXT_REVERSE, "Izvadīt tekstu reversā");
//     displayMenuRow(MENU_EXIT, "Beigt darbu");

//     // extra tasks
//     displayMenuRow(CHECK_PALINDROM, "Vai ir polindroms");
//     displayMenuRow(ERASE_A, "Izdzēst a char");
//     displayMenuRow(COUNT_NUMERIC, "Saskaitīt numeric simbolus");

//     displayMenuRow(MENU_AUTHOR, "Autors");
//     displayMenuRow();

//     cout << setfill('-')
//          << setw(MENU_HEADER_LEFT_WIDTH + MENU_HEADER_RIGHT_WIDTH) << " "
//          << setfill(' ') << endl;
//     cout << "\n";
// }