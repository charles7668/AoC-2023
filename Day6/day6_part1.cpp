#include "day6_part1.h"

#include "day6_helper.h"

using namespace Day6;

long long Day6::day6_part1(const std::string& input) {
    const TestData test_data = parse_file(input);
    const int race_count = static_cast<int>(test_data.time_list.size());
    const std::vector<int>& time_list = test_data.time_list;
    const std::vector<int>& distance_list = test_data.distance_list;
    long long result = 1;
    for (int i = 0; i < race_count; i++) {
        const int time = time_list[i];
        const int distance = distance_list[i];
        int number_of_way = 0;
        for (int t = 0; t < time; t++) {
            if (t * (time - t) > distance) {
                number_of_way = (time - t) - t + 1;
                break;
            }
        }
        result *= number_of_way;
    }
    return result;
}
