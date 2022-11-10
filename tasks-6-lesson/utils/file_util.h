#ifndef __FILE_UTIL_H
#define __FILE_UTIL_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

namespace fileUtils {

bool fileExists(const std::string& path) {
    if (FILE *file = fopen(path.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }  
}

template <typename T>
void writeArrToFile(const std::string& path, const T* data, const int dataLength, bool isBinary = false, bool isAppend = false) {

    fstream file;

    if (isBinary)
        file.open(path, ios::out | ios::binary);
    else if (isAppend)
        file.open(path, ios::out | ios::app);
    else 
        file.open(path, ios::out);

    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(data), sizeof(T) * dataLength);
    } else {
        throw runtime_error("Error writing to file!");
    }

    file.close();
}

template <typename T>
void appendToFile(const std::string& path, const T &dataObject) {

    fstream file;

    file.open(path, ios::out | ios::app);

    if (file.is_open()) {
        file << dataObject << ' ';
    } else {
        throw runtime_error("Error writing to file!");
    }

    file.close();
}

template <typename T>
vector<T> readArrFromFile(const string& path, bool isBinary = false) {
    
    fstream file;

    if (isBinary)
        file.open(path, ios::in | ios::binary);
    else 
        file.open(path, ios::in);

    vector<T> importData;

    auto entrySize = sizeof(T);

    // Allocate zero block for comparing to empty data
    char* dataTestBlock[entrySize];
    memset(dataTestBlock, 0, sizeof(dataTestBlock));

    if (file.is_open()) {
        while (!file.eof()) {
            auto data = new T();
            file.read(reinterpret_cast<char*>(data), entrySize);

            // Check if EOF or all bytes are zero
            if (file.eof() || !memcmp(dataTestBlock, data, entrySize)) {
                break;
            }

            importData.push_back(*data);
        }
    } else {
        cout << "[WARN] Attempt to read array from non-existant file\n";
    }

    file.close();
    return importData;
}

}  // namespace fileUtils

#endif