#pragma once
#include <string>
#include <vector>

namespace Day7 {
    class TestData {
    public:
        std::vector<std::vector<int>> cards;
        std::vector<int> scores;
    };

    TestData parse_file(const std::string& filename);
    TestData parse_file_rule2(const std::string& filename);
    int card_pattern_rule1(const std::vector<int>& cards);
    int card_pattern_rule2(const std::vector<int>& cards);
}
