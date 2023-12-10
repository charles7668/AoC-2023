#include <iostream>

#include "day9_part1.h"
#include "day9_part2.h"

int main() {
    const long long day9_part1_answer = Day9::day9_part1("day9.txt");
    const long long day9_part2_answer = Day9::day9_part2("day9.txt");
    std::cout << "Day 9 part 1 answer: " << day9_part1_answer << std::endl;
    std::cout << "Day 9 part 2 answer: " << day9_part2_answer << std::endl;
}
