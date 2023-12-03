#include <iostream>

#include "day2_part1.h"
#include "day2_part2.h"

using std::cout , std::endl;

int main() {
    const int answer_day2_pt1 = day2_part1("day2.txt");
    const int answer_day2_pt2 = day2_part2("day2.txt");
    cout << "Day2 part1 = " << answer_day2_pt1 << endl;
    cout << "Day2 part2 = " << answer_day2_pt2 << endl;
}
