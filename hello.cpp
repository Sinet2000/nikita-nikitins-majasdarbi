#include <iostream>
#include <string>
using namespace std;

struct DateStruct {
    int year {};
    int month {};
    int day {};
};

class DateClass {

    public:
        int m_year {};
        int m_month {};
        int m_day {};

        void print() {
            cout << m_year << '/' << m_month << '/' << m_day <<endl;
        }
};

class Employee {

    public:
        string m_name {};
        int m_id {};
        double m_wage {};

        void print() {
            cout << "Name: " << m_name << 
            "\tID: " << m_id <<
            "\tWage: $" << m_wage << '\n' << endl;
        }
};

// pass an address of DateStruct instance
void print(const DateStruct& date) {
    cout << date.year << '/' << date.month << '/' << date.day << endl;
}

int main() {
    DateStruct today {2022, 9, 26 };
    DateClass today1 {2022, 9, 26 };

    today.day = 16;
    
    print(today);

    Employee alex { "Alex" , 1, 25.00 };

    cout << "Hello word!!" << endl;
    return 0;
}