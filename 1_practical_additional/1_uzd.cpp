#include <iostream>
#include <limits> // limits prieks valdiation

using namespace std;

bool isPrimeNumber(int number);

int main()
{
    cout << "Ievadiet skaitli, lai parbaudit vai tas ir pirmskaitlis: >> ";
    int userInput;
    cin >> userInput;

    while (1)
    {
        if (cin.fail() || (userInput < 0))
        {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ievadiet ludzu ne negativo skaitli!" << endl;
            cout << ">>>> ";
            cin >> userInput;
        }

        if (!cin.fail() && (userInput >= 0))
            break;
    }

    cout << "\n"
         << (isPrimeNumber(userInput) ? "Ir pirmskaitlis" : "Nav pirmskaitlis!") << endl;

    system("pause>nul");
    return 0;
}

bool isPrimeNumber(int number)
{
    if (number == 2)
        return true;

    int k = 0;
    for (int i = 2; i < number - 1; i++)
    {
        if (number % i == 0)
            k ++;
    }

    return !(k > 0);
}