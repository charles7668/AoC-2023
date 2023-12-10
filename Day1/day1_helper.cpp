#include "day1_helper.h"
#include <fstream>

using std::vector , std::string;

Day1::TestData::TestData(vector<string>&& data_set)
    : data_set(std::forward<vector<string>>(data_set)) {
}

Day1::TestData Day1::parse_file(const string& file_name) {
    std::ifstream input_file(file_name, std::ios::in);
    string line;
    vector<string> data_set;
    while (getline(input_file, line)) {
        data_set.push_back(line);
    }
    return Day1::TestData(std::move(data_set));
}
