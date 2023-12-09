#include <iostream>

#include "day8_part1.h"
#include "day8_part2.h"

int main() {
    using namespace Day8;
    const int day8_part1_answer = day8_part1("day8.txt");
    const long long day8_part2_answer = day8_part2("day8.txt");
    std::cout << "Day 8 part 1 answer: " << day8_part1_answer << std::endl;
    std::cout << "Day 8 part 2 answer: " << day8_part2_answer << std::endl;
}
