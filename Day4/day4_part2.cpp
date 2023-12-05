#include "day4_part2.h"

#include <numeric>
#include <unordered_map>

#include "day4_helper.h"

int Day4::day4_part2(const std::string& filename) {
    using std::vector , std::string;
    const TestData test_data = parse_file(filename);
    const int turn_count = test_data.turn_count;
    const std::vector<std::vector<int>>& winner_cards_list = test_data.winner_cards_list;
    const std::vector<std::vector<int>>& your_cards_list = test_data.your_cards_list;
    vector<int> instant_count_list(turn_count, 1);
    for (int i = 0; i < turn_count; ++i) {
        int win_count = 0;
        std::unordered_map<int, bool> winner_map;
        const vector<int>& winner_cards = winner_cards_list[i];
        const vector<int>& your_cards = your_cards_list[i];
        for (int winner_card: winner_cards) {
            winner_map[winner_card] = true;
        }
        for (int your_card: your_cards) {
            if (winner_map[your_card]) {
                win_count++;
            }
        }
        for (int j = 0; j < win_count && (i + 1 + j) < turn_count; ++j) {
            instant_count_list[i + 1 + j] += instant_count_list[i];
        }
    }
    const int sum = std::accumulate(instant_count_list.begin(), instant_count_list.end(), 0);
    return sum;
}
