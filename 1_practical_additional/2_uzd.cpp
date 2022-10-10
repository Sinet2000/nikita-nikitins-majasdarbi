#include <iostream>
#include <limits> // limits prieks valdiation

using namespace std;

float getValidatedInput(string helperText);

int main()
{
    float width, height;

    cout << "Ievadiet tainstuura platumu un garumu:" << endl;
    width = getValidatedInput("\nPlatums: ");
    height = getValidatedInput("\nnGarums: ");

    cout << "\nPerimetrs: " << fixed << (width + height) * 2 << endl;
    cout << "\nLaukums: " << fixed << width * height << endl;

    system("pause>nul");
    return 0;
}

float getValidatedInput(string helperText)
{
    float inputValue;
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