#include "day4_helper.h"

#include <fstream>
#include <sstream>
#include <string>

Day4::TestData Day4::parse_file(const std::string& filename) {
    using std::string , std::ifstream , std::vector;
    ifstream in_file(filename);
    string line;
    std::getline(in_file, line, ':');
    std::getline(in_file, line);
    vector<vector<int>> winner_cards_list;
    vector<vector<int>> your_cards_list;
    int count = 0;
    do {
        count++;
        vector<int> winner_cards;
        vector<int> your_cards;
        std::istringstream iss_line(line);
        string winner_card_string;
        string your_card_string;
        std::getline(iss_line, winner_card_string, '|');
        std::getline(iss_line, your_card_string);
        std::istringstream iss_winner_card_string(winner_card_string);
        std::istringstream iss_your_card_string(your_card_string);
        string winner_card;
        while (std::getline(iss_winner_card_string, winner_card, ' ')) {
            if (winner_card.empty()) continue;
            winner_cards.push_back(std::stoi(winner_card));
        }
        string your_card;
        while (std::getline(iss_your_card_string, your_card, ' ')) {
            if (your_card.empty()) continue;
            your_cards.push_back(std::stoi(your_card));
        }
        winner_cards_list.push_back(winner_cards);
        your_cards_list.push_back(your_cards);
        std::getline(in_file, line, ':');
    } while (std::getline(in_file, line));
    return TestData(count, std::move(winner_cards_list), std::move(your_cards_list));
}
