#ifndef first_task_h
#define first_task_h

#include "../core-file.h"
#include "../utils/main_menu.h"


using namespace std;

namespace mainTasks {

    struct Student {
        char[ProgramConstants::MAX_TXT_LENGTH] name;
        char[ProgramConstants::MAX_TXT_LENGTH] surname;
        char[ProgramConstants::MAX_TXT_LENGTH] email;
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
                    displayNewFileName(newFileName);

                    cin.ignore();
                    cin.get();

                    break;

                case DISPLAY_ALL:
                    combineFileWithFirstProgramFile(newFileName);

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
        inputValidatorsUtils::getTextInput("\nName:");
    }

} // namespace mainTasks


#endif