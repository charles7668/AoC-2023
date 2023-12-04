#include <iostream>
#include "day3_part1.h"
#include "day3_part2.h"

int main() {
    using namespace day3;
    using std::cout, std::endl;
    const int day3_part1_answer = day3_part1("day3.txt");
    const int day3_part2_answer = day3_part2("day3.txt");
    cout << "Day 3 Part 1 Answer: " << day3_part1_answer << endl;
    cout << "Day 3 Part 2 Answer: " << day3_part2_answer << endl;
}
