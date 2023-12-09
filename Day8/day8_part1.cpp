#include "day8_part1.h"

#include "day8_helper.h"

int Day8::day8_part1(const std::string& file_name) {
    auto [instructions, input] = parse_file(file_name);
    size_t instruction_index = 0;
    std::string start_key = "AAA";
    int count = 0;
    while (true) {
        auto& [left , right] = input[start_key];
        const std::string next = instructions[instruction_index] == 'L' ? left : right;
        if (next == "ZZZ") return count + 1;
        start_key = next;
        count++;
        instruction_index++;
        instruction_index %= instructions.size();
    }
}
