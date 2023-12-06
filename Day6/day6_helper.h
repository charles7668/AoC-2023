#pragma once
#include <string>
#include <vector>

namespace Day6 {
    class TestData {
    public:
        std::vector<int> time_list;
        std::vector<int> distance_list;

        TestData(std::vector<int>&& time_list, std::vector<int>&& distance_list)
            : time_list(std::move(time_list)), distance_list(std::move(distance_list)) {
        };
    };

    TestData parse_file(const std::string& input);
}
