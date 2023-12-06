#include "day5_part1.h"

#include <algorithm>
#include <stdexcept>

#include "day5_helper.h"

long long Day5::day5_part1(const std::string& input) {
    using std::vector ,std::string;
    const TestData test_data = parse_file(input);
    vector<long long> seed_map(test_data.seed_list.begin(), test_data.seed_list.end());
    enum {
        SEED_TO_SOIL,
        SOIL_TO_FERTILIZER,
        FERTILIZER_TO_WATER,
        WATER_TO_LIGHT,
        LIGHT_TO_TEMPERATURE,
        TEMPERATURE_TO_HUMIDITY,
        HUMIDITY_TO_LOCATION,
        END
    };
    int turn = SEED_TO_SOIL;
    while (turn != END) {
        for (long long& seed: seed_map) {
            const vector<std::tuple<long long, long long, long long>>* seed_to_soil = &test_data.seed_to_soil;
            switch (turn) {
                case SEED_TO_SOIL:
                    seed_to_soil = &test_data.seed_to_soil;
                    break;
                case SOIL_TO_FERTILIZER:
                    seed_to_soil = &test_data.soil_to_fertilizer;
                    break;
                case FERTILIZER_TO_WATER:
                    seed_to_soil = &test_data.firtilizer_to_warter;
                    break;
                case WATER_TO_LIGHT:
                    seed_to_soil = &test_data.water_to_light;
                    break;
                case LIGHT_TO_TEMPERATURE:
                    seed_to_soil = &test_data.light_to_temerature;
                    break;
                case TEMPERATURE_TO_HUMIDITY:
                    seed_to_soil = &test_data.temperature_to_humidity;
                    break;
                case HUMIDITY_TO_LOCATION:
                    seed_to_soil = &test_data.humidity_to_location;
                    break;
                default:
                    throw std::runtime_error("Invalid turn");
            }
            for (auto& [dest , src , len]: (*seed_to_soil)) {
                if (seed >= src && seed < src + len) {
                    seed = dest + seed - src;
                    break;
                }
            }
        }
        switch (turn) {
            case SEED_TO_SOIL:
                turn = SOIL_TO_FERTILIZER;
                break;
            case SOIL_TO_FERTILIZER:
                turn = FERTILIZER_TO_WATER;
                break;
            case FERTILIZER_TO_WATER:
                turn = WATER_TO_LIGHT;
                break;
            case WATER_TO_LIGHT:
                turn = LIGHT_TO_TEMPERATURE;
                break;
            case LIGHT_TO_TEMPERATURE:
                turn = TEMPERATURE_TO_HUMIDITY;
                break;
            case TEMPERATURE_TO_HUMIDITY:
                turn = HUMIDITY_TO_LOCATION;
                break;
            case HUMIDITY_TO_LOCATION:
                turn = END;
                break;
            default:
                throw std::runtime_error("Invalid turn");
        }
    }
    return *std::min_element(seed_map.begin(), seed_map.end());
}
