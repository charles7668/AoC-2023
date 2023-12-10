#pragma once
#include <string>
#include <vector>

namespace Day9 {
    class TestData {
    public:
        std::vector<std::vector<long long>> sensor_data;

        explicit TestData(std::vector<std::vector<long long>>&& data)
            : sensor_data(std::move(data)) {
        }
    };

    TestData parse_file(const std::string& file_name);
}
