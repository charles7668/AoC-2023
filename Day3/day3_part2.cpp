#include "day3_part2.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "day3_helper.h"

using namespace day3;

int get_value_produce(const std::vector<std::vector<char>>& char_map, const int r, const int c) {
    using std::vector , std::unordered_map , std::string;
    unordered_map<int, unordered_map<int, bool>> visited;
    const vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<int> temp;
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
        if (visited[row_index][result_col_index]) continue;
        visited[row_index][result_col_index] = true;
        int count = 0;
        for (int i = result_col_index; i < char_map[row_index].size(); i++) {
            if (is_number(char_map[row_index][i]))
                count++;
            else
                break;
        }
        string s{char_map[row_index].begin() + result_col_index, char_map[row_index].begin() + result_col_index + count};
        temp.push_back(std::stoi(s));
    }
    if (temp.size() == 2)
        return temp[0] * temp[1];
    return 0;
}

int day3::day3_part2(const std::string& path) {
    using std::vector , std::string;
    const TestData test_data = parse_file(path);
    const int row_count = static_cast<int>(test_data.data.size());
    const int col_count = static_cast<int>(test_data.data[0].size());
    const vector<vector<char>>& data = test_data.data;
    int sum = 0;
    for (int r = 0; r < row_count; ++r) {
        for (int c = 0; c < col_count; ++c) {
            if (is_symbol(data[r][c])) {
                sum += get_value_produce(data, r, c);
            }
        }
    }
    return sum;
}
