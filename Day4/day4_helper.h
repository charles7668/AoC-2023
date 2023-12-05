#pragma once
#include <string>
#include <vector>

namespace Day4 {
    class TestData {
    public:
        int turn_count;
        std::vector<std::vector<int>> winner_cards_list;
        std::vector<std::vector<int>> your_cards_list;

        explicit TestData(const int turn_count, std::vector<std::vector<int>>&& winner_cards, std::vector<std::vector<int>>&& your_cards)
            : turn_count(turn_count), winner_cards_list(std::move(winner_cards)), your_cards_list(std::move(your_cards)) {
        }
    };

    TestData parse_file(const std::string& filename);
}
