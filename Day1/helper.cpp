#include "helper.h"
#include <fstream>

using std::vector , std::string;

TestData::TestData(vector<string>&& data_set)
    : data_set(std::forward<vector<string>>(data_set)) {
}

TestData parse_file(const string& file_name) {
    std::ifstream input_file(file_name, std::ios::in);
    string line;
    vector<string> data_set;
    while (getline(input_file, line)) {
        data_set.push_back(line);
    }
    return TestData(std::move(data_set));
}
