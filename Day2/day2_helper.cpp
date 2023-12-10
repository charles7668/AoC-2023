#include "day2_helper.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
using std::string , std::vector , std::array;

Day2::TestData Day2::parse(const std::string& input_file_name) {
    std::ifstream input_file(input_file_name, std::ios::in);
    string line;
    vector<TestData::GameData> result;
    while (getline(input_file, line)) {
        TestData::GameData current_game;
        size_t split_index = line.find(':', 0);
        auto game_id_string = line.substr(0 + string("game ").size(), split_index);
        current_game.game_id = std::stoi(game_id_string);
        vector<array<int, 3>> game_turn_data;
        size_t turn_split = line.find(';', split_index);
        size_t start = split_index;
        while (start < line.size()) {
            array<int, 3> turn_data{};
            std::fill(turn_data.begin(), turn_data.end(), 0);
            auto turn_data_split = line.substr(start + 1, turn_split - start - 1);
            std::unordered_map<string, int> color_map{{"red", 0}, {"green", 1}, {"blue", 2}};
            std::istringstream iss(turn_data_split);
            string temp;
            while (getline(iss, temp, ',')) {
                for (auto& [first, second]: color_map) {
                    if (auto index = temp.find(first); index != string::npos) {
                        turn_data[second] = std::stoi(temp.substr(0, index));
                        break;
                    }
                }
            }
            game_turn_data.push_back(turn_data);
            start = turn_split;
            turn_split = line.find(';', start + 1);
            if (turn_split == string::npos)
                turn_split = line.size();
        }
        current_game.data = std::move(game_turn_data);
        result.push_back(std::move(current_game));
    }
    return TestData(std::move(result));
}
