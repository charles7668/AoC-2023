#include "day7_helper.h"

#include <algorithm>
#include <fstream>
#include <unordered_map>


Day7::TestData Day7::parse_file(const std::string& filename) {
    using std::string , std::ifstream , std::vector , std::getline;
    ifstream infile(filename);
    string line;
    const std::unordered_map<char, int> card_values = {
            {'A', 13}, {'K', 12}, {'Q', 11}, {'J', 10}, {'T', 9},
            {'9', 8}, {'8', 7}, {'7', 6}, {'6', 5}, {'5', 4},
            {'4', 3}, {'3', 2}, {'2', 1}
    };
    TestData test_data;
    while (getline(infile, line)) {
        const size_t split = line.find(' ');
        if (split == string::npos) continue;
        string card_str = line.substr(0, split);
        string score_str = line.substr(split + 1);
        vector<int> cards;
        for (char i: card_str) {
            cards.push_back(card_values.at(i));
        }
        int score = std::stoi(score_str);
        test_data.cards.push_back(std::move(cards));
        test_data.scores.push_back(score);
    }
    return test_data;
}

Day7::TestData Day7::parse_file_rule2(const std::string& filename) {
    using std::string , std::ifstream , std::vector , std::getline;
    ifstream infile(filename);
    string line;
    const std::unordered_map<char, int> card_values = {
            {'A', 13}, {'K', 12}, {'Q', 11}, {'T', 9},
            {'9', 8}, {'8', 7}, {'7', 6}, {'6', 5}, {'5', 4},
            {'4', 3}, {'3', 2}, {'2', 1}, {'J', 0}
    };
    TestData test_data;
    while (getline(infile, line)) {
        const size_t split = line.find(' ');
        if (split == string::npos) continue;
        string card_str = line.substr(0, split);
        string score_str = line.substr(split + 1);
        vector<int> cards;
        for (char i: card_str) {
            cards.push_back(card_values.at(i));
        }
        int score = std::stoi(score_str);
        test_data.cards.push_back(std::move(cards));
        test_data.scores.push_back(score);
    }
    return test_data;
}

int Day7::card_pattern_rule1(const std::vector<int>& cards) {
    std::unordered_map<int, int> counter_map;
    for (int card: cards) {
        counter_map[card]++;
    }
    std::vector<int> sort_arr;
    sort_arr.reserve(counter_map.size());
    for (auto& [first, count]: counter_map) {
        sort_arr.push_back(count);
    }
    sort(sort_arr.begin(), sort_arr.end());
    if (counter_map.size() == 1)
        return 7;
    if (counter_map.size() == 2) {
        if (sort_arr.back() == 4)
            return 6;
        return 5;
    }
    if (counter_map.size() == 3) {
        if (sort_arr.back() == 3)
            return 4;
        return 3;
    }
    if (counter_map.size() == 4)
        return 2;
    return 1;
}

int Day7::card_pattern_rule2(const std::vector<int>& cards) {
    std::unordered_map<int, int> counter_map;
    for (int card: cards) {
        counter_map[card]++;
    }
    const int j_card = counter_map[0];
    counter_map.erase(0);
    std::vector<int> sort_arr;
    sort_arr.reserve(counter_map.size());
    for (auto& [first, count]: counter_map) {
        sort_arr.push_back(count);
    }
    sort(sort_arr.begin(), sort_arr.end());
    if (!sort_arr.empty())
        sort_arr.back() += j_card;
    else
        sort_arr.push_back(j_card);
    if (sort_arr.size() == 1)
        return 7;
    if (sort_arr.size() == 2) {
        if (sort_arr.back() == 4)
            return 6;
        return 5;
    }
    if (sort_arr.size() == 3) {
        if (sort_arr.back() == 3)
            return 4;
        return 3;
    }
    if (sort_arr.size() == 4)
        return 2;
    return 1;
}
