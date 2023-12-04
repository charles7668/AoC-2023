#include "day3_helper.h"
#include <fstream>
#include <string>

using namespace day3;

TestData day3::parse_file(const std::string& file_path) {
    using std::string , std::ifstream , std::vector;
    ifstream input_file(file_path);
    string line;
    vector<vector<char>> data;
    while (std::getline(input_file, line)) {
        std::vector<char> row;
        for (const char& c: line) {
            row.push_back(c);
        }
        data.push_back(row);
    }
    return TestData(std::move(data));
}

bool day3::is_number(const char c) {
    return c >= '0' && c <= '9';
}

bool day3::is_symbol(const char c) {
    return c != '.' && (c < '0' || c > '9');
}
