#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstring>

using namespace std;


int main()
{
    setlocale(LC_CTYPE, "Russian"); // перекодировка windows-1251 -> cp866 (OEM) при выводе

    char bufin[100], bufout[100];

    cout << "Скажи \"да\": ";
    cin >> bufin;  // приняли строку в кодировке OEM

    OemToCharBuff(bufin, bufout, 100); // перекодировали из OEM в windows-1251

    if (stricmp(bufout, "да") == 0)  // сравниваем с "да" в кодировке windows-1251
        cout << "принято 'да'" << endl;

    cout << bufout << endl;

    getch();
    return 0;
}