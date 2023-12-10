#include "day9_part1.h"

#include <algorithm>
#include <iostream>
#include <stack>

#include "day9_helper.h"

long long Day9::day9_part1(const std::string& input_file) {
    using std::vector , std::string;
    const TestData test_data = parse_file(input_file);
    const vector<vector<long long>> sensor_data = test_data.sensor_data;
    std::stack<long long> stack_start;
    long long sum = 0;
    for (auto& data: sensor_data) {
        vector<long long> pre;
        pre.reserve(data.size());
        std::copy(data.begin(), data.end(), std::back_inserter(pre));
        vector<long long> cur;
        int count = 0;
        while (true) {
            cur.clear();
            count++;
            stack_start.push(pre[0]);
            for (long long j = 1; j < pre.size(); j++) {
                cur.push_back(pre[j] - pre[j - 1]);
            }
            if (!std::any_of(cur.begin(), cur.end(), [](const long long x) {
                return x != 0;
            }))
                break;

            pre.swap(cur);
        }
        cur.push_back(0);
        while (count--) {
            long long start = stack_start.top();
            stack_start.pop();
            pre.clear();
            pre.push_back(start);
            for (const long long x: cur) {
                pre.push_back(pre.back() + x);
            }
            cur.clear();
            std::copy(pre.begin(), pre.end(), std::back_inserter(cur));
        }
        sum = sum + pre.back();
    }
    return sum;
}
