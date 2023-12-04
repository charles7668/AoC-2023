#pragma once
#include <string>
#include <vector>

namespace day3 {
    class TestData {
    public:
        std::vector<std::vector<char>> data;

        explicit TestData(std::vector<std::vector<char>>&& input)
            : data(std::move(input)) {
        }
    };

    TestData parse_file(const std::string& file_path);

    bool is_number(char c);
    bool is_symbol(char c);
}
