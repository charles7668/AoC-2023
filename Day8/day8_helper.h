#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace Day8 {
    class TestData {
    public:
        std::string instructions;
        std::unordered_map<std::string, std::pair<std::string, std::string>> input;
    };

    TestData parse_file(const std::string& file_name);
}
