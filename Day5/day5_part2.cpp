#include "day5_part2.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "day5_helper.h"

long long Day5::day5_part2(const std::string& input) {
    using std::vector ,std::string ,std::tuple;
    const TestData test_data = parse_file(input);
    vector<std::pair<long long, long long>> seed_map;
    for (int i = 0; i < test_data.seed_list.size(); i += 2) {
        seed_map.emplace_back(test_data.seed_list[i], test_data.seed_list[i] + test_data.seed_list[i + 1] - 1);
    }
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
        for (int i = 0; i < seed_map.size(); i++) {
            vector<std::pair<long long, long long>> new_push;
            const vector<std::tuple<long long, long long, long long>>* seed_to_soil = nullptr;
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
                auto& [seed_s , seed_e] = seed_map[i];
                if (src >= seed_s && src + len - 1 <= seed_e) {
                    if (src > seed_s) {
                        new_push.emplace_back(seed_s, src - 1);
                    }
                    if (src + len - 1 < seed_e) {
                        new_push.emplace_back(src + len, seed_e);
                    }
                    const long long dest_src = src;
                    const long long dest_end = src + len - 1;
                    seed_s = dest + (dest_src - src);
                    seed_e = dest + (dest_end - src);
                    break;
                } else if (src < seed_s && src + len - 1 >= seed_s && src + len - 1 <= seed_e) {
                    if (src + len - 1 < seed_e) {
                        new_push.emplace_back(src + len, seed_e);
                    }
                    const long long dest_src = seed_s;
                    const long long dest_end = src + len - 1;
                    seed_s = dest + (dest_src - src);
                    seed_e = dest + (dest_end - src);
                    break;
                } else if (src >= seed_s && src <= seed_e && src + len - 1 > seed_e) {
                    if (src > seed_s) {
                        new_push.emplace_back(seed_s, src - 1);
                    }
                    const long long dest_src = src;
                    const long long dest_end = seed_e;
                    seed_s = dest + (dest_src - src);
                    seed_e = dest + (dest_end - src);
                    break;
                } else if (src < seed_s && src + len - 1 > seed_e) {
                    const long long dest_src = seed_s;
                    const long long dest_end = seed_e;
                    seed_s = dest + (dest_src - src);
                    seed_e = dest + (dest_end - src);
                    break;
                }
            }
            for (const auto& j: new_push)
                seed_map.push_back(j);
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
    long long result = std::get<0>(seed_map[0]);
    vector<long long> test;
    for (int i = 1; i < seed_map.size(); ++i) {
        if (std::get<0>(seed_map[i]) < result) {
            result = std::get<0>(seed_map[i]);
        }
        test.push_back(std::get<0>(seed_map[i]));
    }
    sort(test.begin(), test.end());
    return result;
}
