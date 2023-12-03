#include <vector>
#include <fstream>
#include <iostream>
#include "day1_part1.h"
#include "helper.h"
using std::vector , std::string , std::cout ,std::endl;

int day1_part1(const std::string& file_name) {
    const TestData test_data = parse_file(file_name);
    const vector<string>& data_set = test_data.data_set;
    int sum = 0;
    for (const string& data: data_set) {
        int left = -1;
        int right = -1;
        const int data_size = static_cast<int>(data.size());
        for (int j = 0; j < data.size(); j++) {
            if (left == -1 && is_number(data[j])) {
                left = j;
            }
            if (const int right_index = data_size - j - 1; right == -1 && is_number(data[right_index])) {
                right = right_index;
            }
            if (left != -1 && right != -1)
                break;
        }
        const int val = (to_number(data[left]) * 10 + to_number(data[right]));
        sum += val;
    }
    return sum;
}
