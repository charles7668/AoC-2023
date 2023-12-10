#include "day9_helper.h"

#include <fstream>
#include <sstream>
#include <string>

Day9::TestData Day9::parse_file(const std::string& file_name) {
    using std::ifstream, std::string, std::vector;
    ifstream in_file(file_name);
    string line;
    vector<vector<long long>> sensor_data;
    while (std::getline(in_file, line)) {
        vector<long long> sensor_line;
        std::istringstream iss(line);
        string split;
        while (std::getline(iss, split, ' ')) {
            sensor_line.push_back(std::stoi(split));
        }
        sensor_data.push_back(sensor_line);
    }

    return TestData(std::move(sensor_data));
}
