#ifndef first_task_h
#define first_task_h

#include "../core-file.h"
#include "../utils/main_menu.h"
#include <iterator>
#include <algorithm>
#include <iomanip>


using namespace std;

namespace mainTasks {

    struct Student {
        string name;
        string surname;
        string email;
        int age;
    };

    enum MenuItems {
        ADD_STUDENT = 1,
        DELETE_STUDENT = 2,
        DISPLAY_ALL = 3,
        MENU_EXIT = 4
    };
    void displayMenu();

    void createStudent(vector<Student> &students);
    void deleteStudent(vector<Student> &students);
    void displayAllStudents(vector<Student> &students);

    void taskMenuRunnerFirst() {
        vector<Student> students;
        
        int userInput;

        do
        {
            displayMenu();
            userInput = inputValidatorsUtils::getUserMenuInput("\nSelect from menu: (1, 2, 3 or 4):\t");

            switch (userInput) {
                case ADD_STUDENT:
                    createStudent(students);

                    cin.ignore();
                    cin.get();

                    break;

                case DELETE_STUDENT:
                    deleteStudent(students);

                    cin.ignore();
                    cin.get();

                    break;

                case DISPLAY_ALL:
                    displayAllStudents(students);

                    cin.ignore();
                    cin.get();

                    break;

                default:
                    cout << "\nIncorrect menu item selection. Please try again!" <<endl;
                    break;
            }

        } while (userInput != MENU_EXIT);
        
    }

    void displayMenu() {
        cout << "\n\t1.Student Management" << endl;
        cout << "\nSelect: " <<endl;
        cout << "[" << ADD_STUDENT << "]\t Add Student" <<endl;
        cout << "[" << DELETE_STUDENT << "]\t Delete Student" <<endl;
        cout << "[" << DISPLAY_ALL << "]\t Display All students" <<endl;
        cout << "[" << MENU_EXIT << "]\t Beigt programmu" <<endl;
        cout << "\n";
    }

    void createStudent(vector<Student> &students) {
        Student newStudent;

        newStudent.name = inputValidatorsUtils::getTextInput("\nName:");
        newStudent.surname = inputValidatorsUtils::getTextInput("\nSurname:");
        newStudent.email = inputValidatorsUtils::getTextInput("\nEmail:");
        newStudent.age = inputValidatorsUtils::getIntInput("\nAge: ");
        students.push_back(newStudent);
        outputUtils::printTxtGreen("Student is created!");

    }

    void deleteStudent(vector<Student> &students) {
        string email = inputValidatorsUtils::getTextInput("\nEnter email of student to delete:");

        vector<Student>::iterator foundStudentToDelete = find_if(
            students.begin(), 
            students.end(), 
            [&email](const Student& obj) {
                return obj.email == email;
        });

        if (foundStudentToDelete != students.end()) {
            students.erase(foundStudentToDelete);
        } else {
            outputUtils::printTxtRed("The student was not found!");
        }
    }

    void displayAllStudents(vector<Student> &students) {
        cout << setw(30) << "Name" << setw(30) << "Surname" << setw(30) << "Email" << setw(30) << "Age" << setw(30) << endl;

        for (Student& student : students) {
            cout << setw(30) << student.name << setw(30) << student.surname << setw(30) << student.email << setw(30) << student.age << setw(30) << endl;
        }
    }

} // namespace mainTasks


#endif