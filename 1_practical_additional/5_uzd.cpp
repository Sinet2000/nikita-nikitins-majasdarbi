#include <iostream>
#include <limits> // limits prieks valdiation
#include <iomanip> // priekš tabulai

using namespace std;

int getValidatedInput(string helperText);
void displayTable(int n, int range);

int main()
{
    int n, range;

    n = getValidatedInput("\nn= ");
    range = getValidatedInput("\nrange= ");

    displayTable(n, range);

    system("pause>nul");
    return 0;
}

int getValidatedInput(string helperText)
{
    int inputValue;
    cout << helperText;
    cin >> inputValue;

    while (1)
    {
        if (cin.fail() || (inputValue <= 0))
        {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nIevadiet ludzu pozitivo skaitli!" << endl;
            cout << ">>>> ";
            cin >> inputValue;
        }

        if (!cin.fail())
            break;
    }

    return inputValue;
}

void displayTable(int n, int range) {
    for(int i = 1; i < range; i ++) {
        cout << left << setw(5) << n <<  '*' << right << setw(5) << i << right << setw(5) << '=' << right << setw(5) << n*i << endl;
    }
}