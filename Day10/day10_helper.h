#pragma once
#include <string>
#include <vector>

namespace Day10 {
    class TestData {
    public:
        std::vector<std::vector<char>> map;
        std::pair<int, int> start_position;
    };

    TestData parse_file(const std::string& input);
}
