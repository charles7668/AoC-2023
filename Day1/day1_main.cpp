#include <iostream>

#include "day1_part1.h"
#include "day1_part2.h"

using std::cout , std::endl;

int main() {
    const int answer_pt1 = Day1::day1_part1("day1.txt");
    const int answer_pt2 = Day1::day1_part2("day1.txt");
    cout << "part1 answer = " << answer_pt1 << endl;
    cout << "part2 answer = " << answer_pt2 << endl;
    return 0;
}
