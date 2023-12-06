#include <iostream>
#include <ostream>

#include "day6_part1.h"
#include "day6_part2.h"

int main() {
    const long long day6_part1_answer = Day6::day6_part1("day6.txt");
    const long long day6_part2_answer = Day6::day6_part2("day6.txt");
    std::cout << "Day 6 part 1 answer: " << day6_part1_answer << std::endl;
    std::cout << "Day 6 part 2 answer: " << day6_part2_answer << std::endl;
}
