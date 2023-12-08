#include "day7_part2.h"

#include <algorithm>
#include <iostream>
#include <vector>

#include "day7_helper.h"

int Day7::day7_part2(const std::string& input) {
    using std::vector , std::pair;
    const TestData test_data = parse_file_rule2(input);
    vector<pair<vector<int>, int>> bind_card_score;
    bind_card_score.reserve(test_data.cards.size());
    for (int i = 0; i < test_data.scores.size(); i++) {
        bind_card_score.emplace_back(test_data.cards[i], test_data.scores[i]);
    }
    sort(bind_card_score.begin(), bind_card_score.end(), [](const auto& a, const auto& b) {
        const int patter_a = card_pattern_rule2(a.first);
        const int patter_b = card_pattern_rule2(b.first);
        if (patter_a == patter_b) {
            for (int i = 0; i < a.first.size(); i++)
                if (a.first[i] != b.first[i])
                    return a.first[i] < b.first[i];
        }
        return patter_a < patter_b;
    });
    int sum = 0;
    for (int i = 0; i < bind_card_score.size(); i++) {
        const int score = bind_card_score[i].second;
        sum += score * (i + 1);
    }
    return sum;
}
