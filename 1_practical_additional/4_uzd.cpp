#include <iostream>
#include <limits> // limits prieks valdiation

using namespace std;

int getValidatedInput(string helperText);
int getReverseNumber(int n);

int main()
{
    int n = getValidatedInput("\n\tn= ");

    cout << "\n Rezultaats = " << getReverseNumber(n) << endl;
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
        if (cin.fail() || (inputValue < 0))
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

int getReverseNumber(int n)
{
    if (n == 0)
        return n;

    int result = 0;

    while (true)
    {
        if (n / 10 >= 1 || n % 10 > 0)
            result = result * 10 + n % 10;
        else
            break;

        n /= 10;
    }

    return result;
}