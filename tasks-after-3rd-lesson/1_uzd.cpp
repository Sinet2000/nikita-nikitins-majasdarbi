#include <array>
#include <cstdio>  //printf
#include <iostream>
#include <limits>   // limits prieks valdiation
#include <numeric>  // lai izmanot reduce'
#include <vector>

using namespace std;

#define ARR_SIZE 10

// Mēģināšu ar templates:

template <typename T>
T getValidatedInput(string helperText = "");

template <typename T>
void buildNmbrsArraySimple(T *numbers);

template <typename T>
T getAverageValueOfArrayValues(T numbers[]);

template <typename T>
void buildNmbrsArray(array<T, ARR_SIZE> &numbers);

template <typename T>
T getAverrageFromStdArray(array<T, ARR_SIZE> &numbers);

template <typename T>
void buildNmbrsVector(vector<T> &numbers);

template <typename T>
T getAverrageFromVector(vector<T> &numbers);

int main() {
    cout << "\nMetode ar parastajiem masiiviem: " << endl;
    int numbers[ARR_SIZE];
    buildNmbrsArraySimple<int>(numbers);

    cout << "\nVidējais ir: " << getAverageValueOfArrayValues<int>(numbers);

    cout << "\nMetode ar array<,>: " << endl;
    array<int, ARR_SIZE> numArray;
    buildNmbrsArray<int>(numArray);
    cout << "\nVidējais array <,> ir: "
         << getAverrageFromStdArray<int>(numArray);

    // https://www.geeksforgeeks.org/vector-in-cpp-stl/
    /**
     * Vector funckcijas:
     * - begin(), end()...
     * size() - number of els
     * max_size()
     * capacity() - the size of the storage currently allocated to the vector
     * resize(n)
     * empty() : bool
     * ...
     *
     */
    cout << "\nMetode ar vector<>: " << endl;
    vector<int> numVector;
    buildNmbrsVector<int>(numVector);
    cout << "\nVidējais vector <> ir: "<< getAverrageFromVector<int>(numVector);
    system("pause>nul");
    return 0;
}

template <typename T>
T getValidatedInput(string helperText) {
    T inputValue;
    if (helperText.length() > 0) cout << helperText;
    cin >> inputValue;

    while (1) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nIevadiet ludzu integer skaitli!" << endl;
            cout << ">>>> ";
            cin >> inputValue;
        }

        if (!cin.fail()) break;
    }

    return inputValue;
}

template <typename T>
void buildNmbrsArraySimple(T *numbers) {
    printf("\nIevadiet masīva skaitļus:\n");

    for (int i = 0; i < ARR_SIZE; i++) {
        printf("\n%d = ", i + 1);
        numbers[i] = getValidatedInput<T>();
    }
}

template <typename T>
T getAverageValueOfArrayValues(T numbers[]) {
    T sum = 0;

    for (int i = 0; i < ARR_SIZE; i++) {
        sum += numbers[i];
    }

    return sum / ARR_SIZE;
}

template <typename T>
void buildNmbrsArray(array<T, ARR_SIZE> &numbers) {
    printf("\nIevadiet array skaitļus:\n");

    for (int i = 0; i < numbers.max_size(); i++) {
        printf("\n%d = ", i + 1);
        numbers[i] = getValidatedInput<T>();
    }
}

template <typename T>
T getAverrageFromStdArray(array<T, ARR_SIZE> &numbers) {
    if (numbers.empty()) return 0;

    T sum = 0;

    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }

    return sum / ARR_SIZE;
}

template <typename T>
void buildNmbrsVector(vector<T> &numbers) {
    printf("\nIevadiet vector skaitļus:\n");

    for (int i = 0; i < ARR_SIZE; i++) {
        printf("\n%d = ", i + 1);
        numbers.push_back(getValidatedInput<T>());
    }
}

template <typename T>
T getAverrageFromVector(vector<T> &numbers) {
    if (numbers.empty()) return 0;

    T sum = 0;

    return reduce(numbers.begin(), numbers.end()) / numbers.size();
}