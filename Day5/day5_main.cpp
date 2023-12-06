#include <iostream>

#include "day5_part1.h"
#include "day5_part2.h"

using namespace Day5;

int main() {
    const long long day5_part1_answer = day5_part1("day5.txt");
    const long long day5_part2_answer = day5_part2("day5.txt");
    std::cout << "Day 5 part 1 answer: " << day5_part1_answer << std::endl;
    std::cout << "Day 5 part 2 answer: " << day5_part2_answer << std::endl;
    return 0;
}
