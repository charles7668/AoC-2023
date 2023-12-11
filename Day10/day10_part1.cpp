#include "day10_part1.h"

#include <algorithm>
#include <queue>

#include "day10_helper.h"

int Day10::day10_part1(const std::string& path) {
    using std::vector , std::pair , std::queue;
    const auto [map, start_position] = parse_file(path);
    const size_t m = map.size();
    const size_t n = map[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push(start_position);
    int cur_step = 0;
    int max_step = 0;
    const vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    while (!q.empty()) {
        size_t q_size = q.size();
        while (q_size--) {
            auto& [cur_x, cur_y] = q.front();
            q.pop();
            if (cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m)
                continue;
            visited[cur_y][cur_x] = true;
            for (const pair<int, int>& dir: dirs) {
                auto& [dir_y , dir_x] = dir;
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
                        if (relative_dir == South || relative_dir == North)
                            q.emplace(next_x, next_y);
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
            }
        }
        if (!q.empty())
            max_step = std::max(max_step, cur_step + 1);
        cur_step++;
    }
    return max_step;
}
