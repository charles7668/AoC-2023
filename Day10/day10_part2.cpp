#include "day10_part2.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

#include "day10_helper.h"

bool point_in_polygon(const std::pair<int, int>& pt, const std::vector<std::pair<int, int>>& verts) {
    const size_t n = verts.size();
    bool inside = false;

    for (size_t i = 0, j = n - 1; i < n; j = i++) {
        const auto& [pre_x, pre_y] = verts[i];

        if (const auto& [cur_x, cur_y] = verts[j]; (pre_y > pt.second) != (cur_y > pt.second)) {
            if (const int crossX = (cur_x - pre_x) * (pt.second - pre_y) / (cur_y - pre_y) + pre_x; pt.first < crossX) {
                inside = !inside;
            }
        }
    }

    return inside;
}

int Day10::day10_part2(const std::string& path) {
    using std::vector , std::pair , std::queue;
    const auto [map, start_position] = parse_file(path);
    const size_t m = map.size();
    const size_t n = map[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> dp(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push(start_position);
    const vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vector<pair<int, int>> path_points;
    int cur_step = 1;
    while (!q.empty()) {
        auto& [cur_x, cur_y] = q.front();
        q.pop();
        if (cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m)
            continue;
        path_points.emplace_back(cur_x, cur_y);
        dp[cur_y][cur_x] = cur_step++;
        visited[cur_y][cur_x] = true;
        for (const pair<int, int>& dir: dirs) {
            const char cur_c = map[cur_y][cur_x];
            auto& [dir_y , dir_x] = dir;
            switch (cur_c) {
                case 'S':
                    break;
                case '|':
                    if (dir_y == 0)
                        continue;
                    break;
                case '-':
                    if (dir_x == 0)
                        continue;
                    break;
                case 'L':
                    if (!((dir_x == 1 && dir_y == 0) || (dir_x == 0 && dir_y == -1)))
                        continue;
                    break;
                case 'J':
                    if (!((dir_x == -1 && dir_y == 0) || (dir_x == 0 && dir_y == -1)))
                        continue;
                    break;
                case '7':
                    if (!((dir_x == -1 && dir_y == 0) || (dir_x == 0 && dir_y == 1)))
                        continue;
                    break;
                case 'F':
                    if (!((dir_x == 1 && dir_y == 0) || (dir_x == 0 && dir_y == 1)))
                        continue;
                    break;
                default:
                    continue;
            }
            auto [next_y , next_x] = std::make_pair(cur_y + dir_y, cur_x + dir_x);
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
                continue;
            if (visited[next_y][next_x])
                continue;
            const char c = map[next_y][next_x];
            enum {
                South = 0,
                West = 1,
                North = 2,
                East = 3
            };
            int relative_dir = South;
            if (dir_x == -1 && dir_y == 0) {
                relative_dir = West;
            } else if (dir_x == 1 && dir_y == 0) {
                relative_dir = East;
            } else if (dir_x == 0 && dir_y == -1) {
                relative_dir = North;
            }
            switch (c) {
                case '|':
                    if (relative_dir == South || relative_dir == North) {
                        q.emplace(next_x, next_y);
                    }
                    break;
                case '-':
                    if (relative_dir == West || relative_dir == East)
                        q.emplace(next_x, next_y);
                    break;
                case 'L':
                    if (relative_dir == West || relative_dir == South)
                        q.emplace(next_x, next_y);
                    break;
                case 'J':
                    if (relative_dir == South || relative_dir == East)
                        q.emplace(next_x, next_y);
                    break;
                case '7':
                    if (relative_dir == East || relative_dir == North)
                        q.emplace(next_x, next_y);
                    break;
                case 'F':
                    if (relative_dir == North || relative_dir == West)
                        q.emplace(next_x, next_y);
                    break;
                default:
                    break;
            }
            if (!q.empty())
                break;
        }
    }
    int count = 0;
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (dp[r][c] == 0) {
                if (pair<int, int> pt = {c, r}; point_in_polygon(pt, path_points))
                    count++;
            }
        }
    }

    return count;
}
