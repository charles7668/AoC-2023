#include <iostream>

#include "day10_part1.h"
#include "day10_part2.h"

int main() {
    const int day10_part1_answer = Day10::day10_part1("day10.txt");
    const int day10_part2_answer = Day10::day10_part2("day10.txt");
    std::cout << "Day 10 part 1 answer: " << day10_part1_answer << std::endl;
    std::cout << "Day 10 part 2 answer: " << day10_part2_answer << std::endl;
    return 0;
}
