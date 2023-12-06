#include "day5_helper.h"

#include <fstream>
#include <sstream>
#include <string>
#include <string>


std::vector<std::string> split(std::string& input, char delimiter) {
    std::istringstream stream(input);
    std::string value;
    std::vector<std::string> result;
    while (std::getline(stream, value, delimiter)) {
        if (!value.empty())
            result.push_back(value);
    }
    return result;
}

Day5::TestData Day5::parse_file(const std::string& input) {
    using std::ifstream , std::string , std::vector , std::stoll;
    ifstream infile(input);
    string line;
    TestData test_data;
    const string SEEDS_KEY = "seeds:";
    const string SEED_TO_SOIL_KEY = "seed-to-soil map:";
    const string SOIL_TO_FERTILIZER_KEY = "soil-to-fertilizer map:";
    const string FERTILIZER_TO_WATER_KEY = "fertilizer-to-water map:";
    const string WATER_TO_LIGHT_KEY = "water-to-light map:";
    const string LIGHT_TO_TEMPERATURE_KEY = "light-to-temperature map:";
    const string TEMPERATURE_TO_HUMIDITY_KEY = "temperature-to-humidity map:";
    const string HUMIDITY_TO_LOCATION_KEY = "humidity-to-location map:";
    enum {
        NORMAL = 0,
        START_READ_SEED_TO_SOIL = 1,
        START_READ_SOIL_TO_FERTILIZER,
        START_READ_FERTILIZER_TO_WATER,
        START_READ_WATER_TO_LIGHT,
        START_READ_LIGHT_TO_TEMPERATURE,
        START_READ_TEMPERATURE_TO_HUMIDITY,
        START_READ_HUMIDITY_TO_LOCATION
    };
    int status = NORMAL;
    while (std::getline(infile, line)) {
        if (line.empty()) continue;
        if (line.find(SEEDS_KEY) == 0) {
            string values = line.substr(SEEDS_KEY.size() + 1, line.size() - SEEDS_KEY.size());
            vector<string> seeds_string_list = split(values, ' ');
            vector<long long> seeds_list;
            seeds_list.reserve(seeds_string_list.size());
            for (const string& seed_string: seeds_string_list) {
                seeds_list.push_back(std::stoll(seed_string));
            }
            test_data.seed_list = seeds_list;
        } else if (line.find(SEED_TO_SOIL_KEY) == 0) {
            status = START_READ_SEED_TO_SOIL;
        } else if (line.find(SOIL_TO_FERTILIZER_KEY) == 0) {
            status = START_READ_SOIL_TO_FERTILIZER;
        } else if (line.find(FERTILIZER_TO_WATER_KEY) == 0) {
            status = START_READ_FERTILIZER_TO_WATER;
        } else if (line.find(WATER_TO_LIGHT_KEY) == 0) {
            status = START_READ_WATER_TO_LIGHT;
        } else if (line.find(LIGHT_TO_TEMPERATURE_KEY) == 0) {
            status = START_READ_LIGHT_TO_TEMPERATURE;
        } else if (line.find(TEMPERATURE_TO_HUMIDITY_KEY) == 0) {
            status = START_READ_TEMPERATURE_TO_HUMIDITY;
        } else if (line.find(HUMIDITY_TO_LOCATION_KEY) == 0) {
            status = START_READ_HUMIDITY_TO_LOCATION;
        } else if (status == START_READ_SEED_TO_SOIL) {
            vector<string> values_string_list = split(line, ' ');
            test_data.seed_to_soil.emplace_back(stoll(values_string_list[0]), stoll(values_string_list[1]), stoll(values_string_list[2]));
        } else if (status == START_READ_SOIL_TO_FERTILIZER) {
            vector<string> values_string_list = split(line, ' ');
            test_data.soil_to_fertilizer.emplace_back(stoll(values_string_list[0]), stoll(values_string_list[1]), stoll(values_string_list[2]));
        } else if (status == START_READ_FERTILIZER_TO_WATER) {
            vector<string> values_string_list = split(line, ' ');
            test_data.firtilizer_to_warter.emplace_back(stoll(values_string_list[0]), stoll(values_string_list[1]), stoll(values_string_list[2]));
        } else if (status == START_READ_WATER_TO_LIGHT) {
            vector<string> values_string_list = split(line, ' ');
            test_data.water_to_light.emplace_back(stoll(values_string_list[0]), stoll(values_string_list[1]), stoll(values_string_list[2]));
        } else if (status == START_READ_LIGHT_TO_TEMPERATURE) {
            vector<string> values_string_list = split(line, ' ');
            test_data.light_to_temerature.emplace_back(stoll(values_string_list[0]), stoll(values_string_list[1]), stoll(values_string_list[2]));
        } else if (status == START_READ_TEMPERATURE_TO_HUMIDITY) {
            vector<string> values_string_list = split(line, ' ');
            test_data.temperature_to_humidity.emplace_back(stoll(values_string_list[0]), stoll(values_string_list[1]), stoll(values_string_list[2]));
        } else if (status == START_READ_HUMIDITY_TO_LOCATION) {
            vector<string> values_string_list = split(line, ' ');
            test_data.humidity_to_location.emplace_back(stoll(values_string_list[0]), stoll(values_string_list[1]), stoll(values_string_list[2]));
        }
    }
    return test_data;
}
