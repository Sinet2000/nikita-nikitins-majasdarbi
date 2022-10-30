#ifndef input_utils_h
#define input_utils_h

#include "../table_utils.h"
#include "../input_validators.h"
#include "../program_utils.h"
#include "../string_utils.h"

using namespace std;

namespace inputUtils {

    enum dataTypeOptions {
        INT = 1,
        DOUBLE = 2,
        CHAR = 3,
        STRING = 4 
    };

    dataTypeOptions getUserSelectedDataType();

    template<typename T>
    void displayMinValueFromInput();

    template<typename T>
    void displayMaxValueFromInput();

    template<typename T>
    void initializeVectorAndDisplay() ;

    void initializeVectorFromInput(vector<int> &dataVector);
    void initializeVectorFromInput(vector<double> &dataVector);
    void initializeVectorFromInput(vector<string> &dataVector);
    void initializeVectorFromInput(vector<char> &dataVector);

    dataTypeOptions getUserSelectedDataType() {
        tableUtils::displayHeader(" Select data type");

        // Empty row with border (rigt, left)
        tableUtils::displayMenuRow(0, " ", true);

        tableUtils::displayMenuRow(static_cast<int>(dataTypeOptions::INT), "Integer");
        tableUtils::displayMenuRow(static_cast<int>(dataTypeOptions::DOUBLE), "DOUBLE");
        tableUtils::displayMenuRow(static_cast<int>(dataTypeOptions::CHAR), "CHAR");
        tableUtils::displayMenuRow(static_cast<int>(dataTypeOptions::STRING), "STRING");
        tableUtils::displayMenuRow(0, " ", true);

        tableUtils::displayFooter();

        int option = inputValidatorsUtils::getNumericOrCharValidatedInput<int>();
        return static_cast<dataTypeOptions>(option);
    }

    template<typename T>
    void displayMinValueFromInput() {
        T val1 = inputValidatorsUtils::getNumericOrCharValidatedInput<T>("| Input first value \t: ");
        T val2 = inputValidatorsUtils::getNumericOrCharValidatedInput<T>("| Input second \t: ");
        T min = MathUtils::min<T, T>(val1, val2);
        programUtils::Print("Min Value:");
        programUtils::Print(min);
    }

    template<typename T>
    void displayMaxValueFromInput() {
        T val1 = inputValidatorsUtils::getNumericOrCharValidatedInput<T>("| Input first value \t: ");
        T val2 = inputValidatorsUtils::getNumericOrCharValidatedInput<T>("| Input second \t: ");
        T max = MathUtils::max<T, T>(val1, val2);
        programUtils::Print("Max Value:");
        programUtils::Print(max);
    }

    template<typename T>
    void initializeVectorAndDisplay() {
        vector<T> initialData = {};
        initializeVectorFromInput(initialData);
    }

    void initializeVectorFromInput(vector<int> &dataVector) {
        vector<int> initialData = dataVector;
        cout << "|\t Data initialization :" << endl;
        cout << "|\t Enter int type data. [{\"f\" - to finish}, {\"c\" - to cancel}]" << endl;

        bool isFinish = true, isCancel = false;
        int addedCount = 1;
        string userInput = "";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do {
            cout << "|\t [" << addedCount << "] : ";
            getline(cin, userInput);
            StringUtils::stringTrim(userInput);

            isFinish = userInput.length() == 1 &&  tolower(userInput[0]) == 'f';
            isCancel = userInput.length() == 1 && tolower(userInput[0]) == 'c';

            if (!isFinish && !isCancel) {

                try
                {
                    // I am exp problems if it is one digit number
                    // cout << "|\t User Input: '" << userInput << "'" << endl;
                    int i = userInput.length() == 1 && isdigit(userInput[0]) ? userInput[0] - '0' : std::stoi(userInput);
                    dataVector.push_back(i);
                    addedCount++;
                }
                catch (const std::invalid_argument &e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "|\t Error: " << e.what() << "\t Try Again!"<<endl;;
                }
                
            }

        } while (!isFinish && !isCancel);

        if (isCancel)
            dataVector = initialData;

        programUtils::Print(dataVector);
    }

    void initializeVectorFromInput(vector<double> &dataVector) {
        vector<double> initialData = dataVector;
        cout << "|\t Data initialization :" << endl;
        cout << "|\t Enter int type data. [{\"f\" - to finish}, {\"c\" - to cancel}]" << endl;

        bool isFinish = true, isCancel = false;
        int addedCount = 1;
        string userInput = "";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do {
            cout << "|\t [" << addedCount << "] : ";
            getline(cin, userInput);
            StringUtils::stringTrim(userInput);

            isFinish = userInput.length() == 1 &&  tolower(userInput[0]) == 'f';
            isCancel = userInput.length() == 1 && tolower(userInput[0]) == 'c';

            if (!isFinish && !isCancel) {

                try
                {
                    // I am exp problems if it is one digit number
                    // cout << "|\t User Input: '" << userInput << "'" << endl;
                    double valueD = stod(userInput);
                    dataVector.push_back(valueD);
                    addedCount++;
                }
                catch (const std::invalid_argument &e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "|\t Error: " << e.what() << "\t Try Again!"<<endl;;
                }
                
            }

        } while (!isFinish && !isCancel);

        if (isCancel)
            dataVector = initialData;

        programUtils::Print(dataVector);
    }

    void initializeVectorFromInput(vector<string> &dataVector) {
        vector<string> initialData = dataVector;
        cout << "|\t Data initialization :" << endl;
        cout << "|\t Enter string type data. [{\"f\" - to finish}, {\"c\" - to cancel}]" << endl;

        bool isFinish = true, isCancel = false;
        int addedCount = 1;
        string userInput = "";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do {
            cout << "|\t [" << addedCount << "] : ";
            getline(cin, userInput);

            isFinish = userInput.length() == 1 &&  tolower(userInput[0]) == 'f';
            isCancel = userInput.length() == 1 && tolower(userInput[0]) == 'c';

            if (!isFinish && !isCancel) {

                try
                {
                    dataVector.push_back(userInput);
                    addedCount++;
                }
                catch (const std::invalid_argument &e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "|\t Error: " << e.what() << "\t Try Again!"<<endl;;
                }
                
            }

        } while (!isFinish && !isCancel);

        if (isCancel)
            dataVector = initialData;

        programUtils::Print(dataVector);
    }

    void initializeVectorFromInput(vector<char> &dataVector) {
        vector<char> initialData = dataVector;
        cout << "|\t Data initialization :" << endl;
        cout << "|\t Enter string type data. [{\"f\" - to finish}, {\"c\" - to cancel}]" << endl;

        bool isFinish = true, isCancel = false;
        int addedCount = 1;
        char userInput;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do {
            cout << "|\t [" << addedCount << "] : ";
            userInput = inputValidatorsUtils::getNumericOrCharValidatedInput<char>();


            isFinish = userInput == 'f';
            isCancel = userInput == 'c';

            if (!isFinish && !isCancel) {

                try
                {
                    dataVector.push_back(userInput);
                    addedCount++;
                }
                catch (const std::invalid_argument &e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "|\t Error: " << e.what() << "\t Try Again!"<<endl;;
                }
                
            }

        } while (!isFinish && !isCancel);

        if (isCancel)
            dataVector = initialData;

        programUtils::Print(dataVector);
    }
}

#endif