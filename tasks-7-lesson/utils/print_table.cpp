#include "print_table.h"

template <typename T, typename U>
std::vector<std::pair<T, U>> zip(std::vector<T> v1, std::vector<U> v2) {
    std::vector<std::pair<T, U>> output;

    for (int i = 0; i < v1.size(); i++) {
        output.push_back(std::pair<T, U>(v1[i], v2[i]));
    }

    return output;
}

void printRow(std::vector<std::string> row, std::vector<int> colWidths,
              bool header = false) {
    int i = 0;
    for (auto v : zip(row, colWidths)) {
        int dWidth = v.second - v.first.length();
        float hdWidth = dWidth / 2.0;

        std::string spacingBefore(ceil(hdWidth), ' ');
        std::string spacingAfter(floor(hdWidth), ' ');

        std::string ansiStart = "";
        std::string ansiEnd = "";

        if (header) {
            ansiStart = "\x1B[34;1m";
            ansiEnd = "\033[0m";
        }

        // pretty stupid and hacky but ¯\_(ツ)_/¯
        if (i++ == 0) {
            std::cout << "\x1B[1m"
                      << "|"
                      << "\033[0m";
        } else {
            std::cout << "|";
        }

        std::cout << spacingBefore;
        std::cout << ansiStart << v.first << ansiEnd;
        std::cout << spacingAfter;
    }

    std::cout << "\x1B[1m"
              << "|"
              << "\033[0m" << '\n';
}

void printHLine(int tableWidth, std::vector<int> colWidths,
                bool prioritizeVertical = false, bool headLine = false) {
    std::string ansiStart;
    std::string ansiEnd = "\033[0m";

    if (headLine) {
        ansiStart = "\x1B[1m";
    } else {
        ansiStart = "\x1B[90m";
    }

    if (prioritizeVertical) {
        std::cout << "\x1B[1m"
                  << "|"
                  << "\033[0m";

        for (int i = 0; i < colWidths.size(); i++) {
            std::cout << ansiStart << std::string(colWidths[i], '-') << ansiEnd;

            if (i == colWidths.size() - 1) {
                std::cout << "\x1B[1m"
                          << "|"
                          << "\033[0m";
            } else {
                std::cout << "|";
            }
        }

        std::cout << '\n';
    } else {
        std::cout << "\x1B[1m"
                  << "|"
                  << "\033[0m";
        std::cout << ansiStart << std::string(tableWidth, '-') << ansiEnd;
        std::cout << "\x1B[1m"
                  << "|" << '\n'
                  << "\033[0m";
    }
}

void printTable(std::vector<std::string> colLabels,
                std::vector<std::vector<std::string>> content,
                std::vector<int> colWidths, int hPadding) {
    std::vector<int> parsedColWidths(colWidths);
    int tableWidth =
        -1;  // Includes only inner borders. -1 to adjust for rightmost border

    for (int i = 0; i < colLabels.size(); i++) {
        int colWidth;

        if (colWidths[i] != -1) {
            colWidth = colWidths[i];
        } else {
            // Set the width to be the width of the widest item
            int largestWidth = colLabels[i].size();

            for (auto row : content) {
                largestWidth = std::max(largestWidth, (int)row[i].size());
            }

            colWidth = largestWidth;
        }

        colWidth += hPadding * 2;
        parsedColWidths[i] = colWidth;
        tableWidth += colWidth + 1;
    }

    // Print top border
    std::cout << "\x1B[1m" << '+' << std::string(tableWidth, '-') << "+\n"
              << "\033[0m";

    // Print the header
    printRow(colLabels, parsedColWidths, true);

    if (content.size() != 0) {
        printHLine(tableWidth, parsedColWidths, false, true);
        auto lastRow = *content.rbegin();

        // Print the content
        for (auto row : content) {
            printRow(row, parsedColWidths);

            if (row != lastRow) printHLine(tableWidth, parsedColWidths, true);
        }
    }

    // Print the bottom border
    std::cout << "\x1B[1m" << '+' << std::string(tableWidth, '-') << "+\n"
              << "\033[0m";
}