#include <iostream>

#include "day7_part1.h"
#include "day7_part2.h"

int main() {
    const int day7_part1_answer = Day7::day7_part1("day7.txt");
    const int day7_part2_answer = Day7::day7_part2("day7.txt");
    std::cout << "Day 7 part 1 answer: " << day7_part1_answer << std::endl;
    std::cout << "Day 7 part 2 answer: " << day7_part2_answer << std::endl;
}
