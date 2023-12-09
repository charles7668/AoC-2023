#include "day8_part2.h"

#include <cmath>
#include <iostream>

#include "day8_helper.h"

long long get_GCD(long long a, long long b) {
    while (b != 0) {
        const long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long get_LCM(const long long a, const long long b) {
    return a * b / get_GCD(a, b);
}

long long Day8::day8_part2(const std::string& file_name) {
    using std::string , std::vector;
    auto [instructions, input] = parse_file(file_name);
    vector<string> start_keys;
    for (auto& [first, second]: input) {
        if (first.back() == 'A')
            start_keys.push_back(first);
    }
    vector<int> trun_record;
    for (auto start_key: start_keys) {
        size_t instruction_index = 0;
        int count = 0;
        while (true) {
            auto& [left , right] = input[start_key];
            const std::string next = instructions[instruction_index] == 'L' ? left : right;
            if (next.back() == 'Z') {
                count++;
                break;
            }
            start_key = next;
            count++;
            instruction_index++;
            instruction_index %= instructions.size();
        }
        trun_record.push_back(count);
    }
    long long prev = 1;
    for (const int i: trun_record) {
        prev = get_LCM(prev, i);
    }

    return prev;
}
