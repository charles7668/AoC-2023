#include "day3_part1.h"

#include <unordered_map>
#include <unordered_set>

#include "day3_helper.h"

using namespace Day3;

namespace {
    std::unordered_map<int, std::unordered_map<int, int>> value_indexes;
}

void get_value_indexes(const std::vector<std::vector<char>>& char_map, const int r, const int c) {
    using std::vector;
    const vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (const vector<int>& direction: directions) {
        const int row_index = r + direction[0];
        const int col_index = c + direction[1];
        if (row_index < 0 || row_index >= char_map.size() || col_index < 0 || col_index >= char_map[0].size()) continue;
        if (!is_number(char_map[row_index][col_index])) continue;
        int result_col_index = -1;
        for (int i = col_index; i > -1; --i) {
            if (is_number(char_map[row_index][i])) {
                result_col_index = i;
            } else {
                break;
            }
        }
        if (result_col_index == -1) continue;
        int count = 0;
        for (int i = result_col_index; i < char_map[row_index].size(); i++) {
            if (is_number(char_map[row_index][i]))
                count++;
            else
                break;
        }
        value_indexes[row_index][result_col_index] = count;
    }
}

int Day3::day3_part1(const std::string& path) {
    using std::vector , std::string;
    const TestData test_data = parse_file(path);
    const int row_count = static_cast<int>(test_data.data.size());
    const int col_count = static_cast<int>(test_data.data[0].size());
    const vector<vector<char>>& data = test_data.data;
    for (int r = 0; r < row_count; ++r) {
        for (int c = 0; c < col_count; ++c) {
            if (is_symbol(data[r][c])) {
                get_value_indexes(data, r, c);
            }
        }
    }
    int sum = 0;
    for (auto& [row_index , col_map]: value_indexes) {
        for (auto& [col_index , count]: col_map) {
            string s{data[row_index].begin() + col_index, data[row_index].begin() + col_index + count};
            const int val = std::stoi(s);
            sum += val;
        }
    }
    return sum;
}
