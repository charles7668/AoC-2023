#include "day7_part1.h"

#include <algorithm>

#include "day7_helper.h"

int Day7::day7_part1(const std::string& input) {
    using std::vector , std::pair;
    const auto [cards, scores] = parse_file(input);
    vector<pair<vector<int>, int>> bind_card_score;
    bind_card_score.reserve(cards.size());
    for (int i = 0; i < scores.size(); i++) {
        bind_card_score.emplace_back(cards[i], scores[i]);
    }
    sort(bind_card_score.begin(), bind_card_score.end(), [](const auto& a, const auto& b) {
        const int patter_a = card_pattern_rule1(a.first);
        const int patter_b = card_pattern_rule1(b.first);
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
