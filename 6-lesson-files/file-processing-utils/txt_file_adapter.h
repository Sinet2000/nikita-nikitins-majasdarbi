#ifndef txt_file_adapter_h
#define txt_file_adapter_h

#include <string>
#include <fstream>
#include <iterator>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

// ofstream - write
// ifstream -read
// fstream - rw

// in - for reading
// out - writing
// binary
// ate - at end- The output position starts at the end of the file
// app - append - All output operations happen at the end of the file, appending to its existing contents
// trunc - truncate - Any contents that existed in the file beofre it is open are discared

// https://www.delftstack.com/howto/cpp/read-file-into-string-cpp/

void readFileToCharArrayIterators(string filePath, char *charArray, int length);
void readFileToString(string filePath, string &fileDataStore);


void readFileToCharArrayIterators(string filePath, char *charArray, int length) {
    ifstream fileHandler;
    fileHandler.open(filePath.c_str());

    std::copy(std::istream_iterator<char>(fileHandler), std::istream_iterator<char>(), charArray); // can be overflow
}

void readFileToString(string filePath, string &fileDataStore) {
    ifstream fileHandler(filePath);

    if (fileHandler) {
        ostringstream ss;
        ss << fileHandler.rdbuf();
        fileDataStore = ss.str();
    }
}

// reading file using istreambuf_iterator to Read File Into String 
// 
string readFileIntoString(const string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

// The rdbuf function is a built-in method to return a pointer to the stream buffer of the file, which is useful to insert the entire contents of the file using the << operator to the needed object.
string readFileIntoString2(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

// fread takes fours arguments: 
// 1. Pointer to the buffer where read data is stored
// 2. The size of the data item
// 3. Number of data items
// 4. The file pointer from which to read
string readFileIntoString3(const string& path) {
    struct stat sb{};
    string res;

    FILE* input_file = fopen(path.c_str(), "r");
    if (input_file == nullptr) {
        perror("fopen");
    }

    stat(path.c_str(), &sb);
    res.resize(sb.st_size);
    fread(const_cast<char*>(res.data()), sb.st_size, 1, input_file);
    fclose(input_file);

    return res;
}

// The read method is POSIX compliant function call available on various operating systems and can be the most flexible one if the programmer knows to employ it efficiently
// fread itself calls read underneath, but this doesn't guarantee the faster operation in all cases, as multiply factors play a hand in the efficient use of such system calls
// The main difference with fread is that read needs a file descriptor argument to point to the file from where to read data.
string readFileIntoString4(const string& path) {
    struct stat sb{};
    string res;

    int fd = open(path.c_str(), O_RDONLY);
    if (fd < 0) {
        perror("open\n");
    }

    fstat(fd, &sb);
    res.resize(sb.st_size);
    read(fd, (char*)(res.data()), sb.st_size);
    close(fd);

    return res;
}

// https://www.positioniseverything.net/cpp-read-binary-file

#endif