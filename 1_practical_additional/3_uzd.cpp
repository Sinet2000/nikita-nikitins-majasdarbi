#include <iostream>
#include <limits> // limits prieks valdiation

using namespace std;

#define dividerThree 3
#define dividerFive 5

int getValidatedInput(string helperText);
int getDivisibleSum(int n);

int main()
{
    int n = getValidatedInput("\n\tn= ");

    cout << "\n Rezultaats = " << getDivisibleSum(n) << endl;
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

int getDivisibleSum(int n) {
    int sum = 0;

    if (n < dividerThree)
        return 0;

    for(int i =3; i <= n; i++) {
        if (i % dividerThree == 0 || i % dividerFive == 0)
            sum += i;
    }

    return sum;
}