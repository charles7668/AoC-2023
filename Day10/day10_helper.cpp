#include "day10_helper.h"

#include <fstream>
#include <string>

Day10::TestData Day10::parse_file(const std::string& input) {
    using std::ifstream, std::string, std::vector , std::pair;
    ifstream infile(input);
    string line;
    vector<vector<char>> map;
    pair<int, int> start_position;
    while (std::getline(infile, line)) {
        vector<char> row;
        for (auto i = 0; i < line.size(); ++i) {
            char c = line[i];
            if (c == 'S')
                start_position = {i, map.size()};
            row.push_back(c);
        }
        map.push_back(row);
    }
    TestData test_data;
    test_data.map = std::move(map);
    test_data.start_position = start_position;
    return test_data;
}
