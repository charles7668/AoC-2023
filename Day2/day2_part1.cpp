#include "day2_helper.h"
#include "day2_part1.h"
using std::vector , std::array , std::string ;

int Day2::day2_part1(const string& input_file) {
    const TestData test_data = parse(input_file);
    int sum = 0;
    const vector<TestData::GameData>& game_data = test_data.game_data;
    for (const auto& [data, game_id]: game_data) {
        bool can_pass = true;
        for (auto j: data) {
            if (j[0] > 12 || j[1] > 13 || j[2] > 14) {
                can_pass = false;
                break;
            }
        }
        if (can_pass)
            sum += game_id;
    }
    return sum;
}
