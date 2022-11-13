#ifndef __PRINT_TABLE_H
#define __PRINT_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

// content - outer vector is the row, inner vector are the columns
// colWidths - A value of -1 means auto-fit that column
void printTable(std::vector<std::string> colLabels,
                std::vector<std::vector<std::string>> content,
                std::vector<int> colWidths, int hPadding = 1);

#endif