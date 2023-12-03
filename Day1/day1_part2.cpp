#include "day1_part2.h"
#include "helper.h"
#include <unordered_map>
using std::vector , std::string;

static std::unordered_map<string, int> number_string_map = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
};

int day1_part2(const std::string& file_name) {
    const TestData test_data = parse_file(file_name);
    const vector<string>& data_set = test_data.data_set;
    int sum = 0;
    for (const string& data: data_set) {
        int left = -1;
        int right = -1;
        int left_val = 0;
        int right_val = 0;
        const int data_size = static_cast<int>(data.size());
        for (int j = 0; j < data.size(); j++) {
            if (left == -1 && is_number(data[j])) {
                left = j;
                left_val = to_number(data[j]);
            }
            if (const int right_index = data_size - j - 1; right == -1 && is_number(data[right_index])) {
                right = right_index;
                right_val = to_number(data[right_index]);
            }
            if (left != -1 && right != -1)
                break;
        }
        for (auto& [fisrt, second]: number_string_map) {
            size_t find_index = data.find(fisrt);
            if (find_index != string::npos && (find_index < left)) {
                left = static_cast<int>(find_index);
                left_val = second;
            }
            size_t start_index = find_index + 1;
            while (start_index < data.size()) {
                if (find_index != string::npos && (find_index > right)) {
                    right = static_cast<int>(find_index);
                    right_val = second;
                }
                find_index = data.find(fisrt, start_index);
                start_index = find_index + 1;
                if (find_index == string::npos)
                    start_index = data.size();
            }
        }
        const int val = left_val * 10 + right_val;
        sum += val;
    }
    return sum;
}
