#pragma once
#include <vector>
#include <string>

class TestData {
public:
    std::vector<std::string> data_set;

    explicit TestData(std::vector<std::string>&& data_set);
};

TestData parse_file(const std::string& file_name);

constexpr bool is_number(const char c) {
    return c >= '0' && c <= '9';
}

constexpr int to_number(const char c) {
    return c - '0';
}
