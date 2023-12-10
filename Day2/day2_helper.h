#pragma once

#include <array>
#include <string>
#include <vector>

namespace Day2 {
    class TestData {
    public:
        class GameData {
        public:
            std::vector<std::array<int, 3>> data;
            int game_id{0};
        };

        std::vector<GameData> game_data;

        explicit TestData(std::vector<GameData>&& game_data)
            : game_data(std::forward<std::vector<GameData>>(game_data)) {
        }
    };

    TestData parse(const std::string& input_file_name);
}
