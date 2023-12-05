#include <iostream>

#include "day4_part1.h"
#include "day4_part2.h"

int main() {
    const int day4_part1_answer = Day4::day4_part1("day4.txt");
    const int day4_part2_answer = Day4::day4_part2("day4.txt");
    std::cout << "Day 4 part 1 answer: " << day4_part1_answer << std::endl;
    std::cout << "Day 4 part 2 answer: " << day4_part2_answer << std::endl;
}
