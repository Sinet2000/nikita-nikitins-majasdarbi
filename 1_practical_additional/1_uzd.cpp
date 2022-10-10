#include <iostream>
#include <limits> // limits prieks valdiation
#include <math.h> //sqrt

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
    if (number <= 1)
        return false;

    int k = 0;
    // improved logic:
    /**
    * Pieņemsim skaitli N, kas ir naturāls skaitlis (>1),
    * kas ir products no skaitļa a un b reizināšanas (a<=b pieņemsim),
    * tad N = a *b, kur 1<a<=b<n,
    * reizinot ar a, tad:
    * a^2<=ab
    * ar b, tad => ab<=b^2
    * tad intervaals ir => a^2<=ab<=b^2, bet ir zinaams, ka ab = N, taapeec:
    * a<= sqrt(N) <= b
    **/
    for (int i = 2; i <= sqrt(number) ; i++)
    {
        if (number % i == 0)
            k ++;
    }

    return !(k > 0);
}