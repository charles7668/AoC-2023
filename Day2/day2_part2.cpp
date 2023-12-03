#include "day2_part2.h"
#include "helper.h"
#include <string>
#include <vector>

using std::vector , std::array , std::string ;

int day2_part2(const std::string& input_file) {
    const TestData test_data = parse(input_file);
    int sum = 0;
    const vector<TestData::GameData>& game_data = test_data.game_data;
    for (const auto& [data, game_id]: game_data) {
        array<int, 3> max_cubes{0, 0, 0};
        for (auto cube: data) {
            max_cubes[0] = std::max(max_cubes[0], cube[0]);
            max_cubes[1] = std::max(max_cubes[1], cube[1]);
            max_cubes[2] = std::max(max_cubes[2], cube[2]);
        }
        sum += (max_cubes[0] * max_cubes[1] * max_cubes[2]);
    }
    return sum;
}
