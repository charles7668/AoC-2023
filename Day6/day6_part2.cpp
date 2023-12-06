#include "day6_part2.h"

#include <cmath>

#include "day6_helper.h"

int get_number_digit_count(int number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

long long Day6::day6_part2(const std::string& input) {
    TestData test_data = parse_file(input);
    const std::vector<int>& time_list = test_data.time_list;
    const std::vector<int>& distance_list = test_data.distance_list;
    long long time = 0;
    long long distance = 0;
    for (const int t: time_list) {
        const int pow_digit = get_number_digit_count(t);
        time = time * static_cast<long long>(std::pow(10, pow_digit)) + t;
    }
    for (const int d: distance_list) {
        const int pow_digit = get_number_digit_count(d);
        distance = distance * static_cast<long long>(std::pow(10, pow_digit)) + d;
    }
    long long number_of_way = 0;
    for (int t = 0; t < time; t++) {
        if (t * (time - t) > distance) {
            number_of_way = (time - t) - t + 1;
            break;
        }
    }
    return number_of_way;
}
