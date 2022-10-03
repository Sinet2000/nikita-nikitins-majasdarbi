#include <iostream>
#include <string>
using namespace std;

// 1. Arrays of struct
struct Rectangle {
    // int score = 0 -> copy initialization ; int scoe {}; -> value initialization, sice C++
    int length{};
    int width{};
};

// 2. Array subscripts


int main() {
    int prime[5]{};
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5; // ....

    int array[5]{}; // declare
    // using a literal (const) index
    array[1] = 7; // ok
    enum Animals {
        animal_cat = 2
    };
    array[animal_cat] = 4; // ok
    int index { 3 };
    array[index] = 7;

    // using a literal constant
    int numberOfLessonsPerDay[7]{}; // Ok
    // using a constexpr symbolic constant
    constexpr int daysPerWeek{ 7 };
    int numberOfLessonsPerDay[daysPerWeek]{}; // Ok

    // using an enumerator
    enum DaysOfWeek
    {
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday,

        maxDaysOfWeek
    };
    int numberOfLessonsPerDay[maxDaysOfWeek]{}; // Ok

    // using a macro
    #define DAYS_PER_WEEK 7
    int numberOfLessonsPerDay[DAYS_PER_WEEK]{}; // Works, but don't do this (use a constexpr symbolic constant instead)

    Rectangle rects[5]{};
    rects[0].length = 24;

    return 0;
}