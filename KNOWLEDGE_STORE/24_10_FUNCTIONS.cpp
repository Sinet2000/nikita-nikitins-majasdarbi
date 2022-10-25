#include <iostream>

using namespace std;


void Tests() {
    int num;
    cout << "Ciparu saraksts: ";
    cin >> num;
    int *ptrNum;

    ptrNum = new int[num];

    cout << "Ievadiet skaitlus" << endl;
    for (int i =0; i < num; ++i) {
        cout << "skaitlis " << i + 1 << ": ";
        cin >> *(ptrNum + i);
    }
}

int main() {
    int num = 5;
    double dec = 4.6;

    int *pointNum;

    void *point = &dec;
    cout << point << " " << &dec << endl;

    point = &num;
    cout << point << "" << &dec << endl;

    cout << *(static_cast<int*>(point));


    // null un nullptr
    int *numPointer, *numPointer2 = nullptr, *numPointer3 = NULL, *nullPointer4 = 0;


    // Pointers and const
    int num (5), num2(17);
    const int num3 = 10;

    int *ptrNum = &num;
    *ptrNum = 7;
    ptrNum = &num2;
    const int *ptrNum2 = &num3;

    system("pause>nul");
    return 0;
}