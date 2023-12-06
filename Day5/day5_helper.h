#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace Day5 {
    class TestData {
    public:
        std::vector<long long> seed_list;
        std::vector<std::tuple<long long, long long, long long>> seed_to_soil;
        std::vector<std::tuple<long long, long long, long long>> soil_to_fertilizer;
        std::vector<std::tuple<long long, long long, long long>> firtilizer_to_warter;
        std::vector<std::tuple<long long, long long, long long>> water_to_light;
        std::vector<std::tuple<long long, long long, long long>> light_to_temerature;
        std::vector<std::tuple<long long, long long, long long>> temperature_to_humidity;
        std::vector<std::tuple<long long, long long, long long>> humidity_to_location;
    };

    TestData parse_file(const std::string& input);
}
