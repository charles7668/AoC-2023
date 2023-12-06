#include "day6_helper.h"

#include <fstream>
#include <sstream>
#include <string>

Day6::TestData Day6::parse_file(const std::string& input) {
    using std::ifstream , std::string , std::vector;
    ifstream input_file(input);
    string line;
    std::getline(input_file, line);
    const string TIME_KEY = "Time:";
    const string DISTANCE_KEY = "Distance:";
    line = line.substr(TIME_KEY.size());
    std::istringstream iss(line);
    string temp;
    vector<int> time_list;
    while (std::getline(iss, temp, ' ')) {
        if (temp.empty()) continue;
        time_list.push_back(std::stoi(temp));
    }
    std::getline(input_file, line);
    line = line.substr(DISTANCE_KEY.size());
    iss = std::istringstream(line);
    vector<int> distance_list;
    while (std::getline(iss, temp, ' ')) {
        if (temp.empty()) continue;
        distance_list.push_back(std::stoi(temp));
    }
    return TestData{std::move(time_list), std::move(distance_list)};
}
