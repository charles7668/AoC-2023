#include "day8_helper.h"

#include <complex>
#include <fstream>
#include <string>
#include <string>

std::string trim(const std::string& input, const std::string& trim_args = " ") {
    std::vector<char> buffer;
    buffer.reserve(input.size());
    for (const char& c: input) {
        bool contain_trim = false;
        for (const char& trim_char: trim_args) {
            if (c == trim_char) {
                contain_trim = true;
                break;
            }
        }
        if (!contain_trim) {
            buffer.push_back(c);
        }
    }
    return std::string{buffer.begin(), buffer.end()};
}

Day8::TestData Day8::parse_file(const std::string& file_name) {
    using std::ifstream , std::string , std::vector , std::unordered_map , std::pair;
    ifstream input_file(file_name);
    string line;
    std::getline(input_file, line);
    TestData test_data;
    test_data.instructions = line;
    while (std::getline(input_file, line)) {
        if (line.empty()) continue;
        const size_t split = line.find('=');
        string key = trim(line.substr(0, split));
        string value = line.substr(split + 1);
        const size_t value_split = value.find(',');
        string value1 = trim(value.substr(0, value_split), " ()");
        string value2 = trim(value.substr(value_split + 1), " ()");
        test_data.input[key] = std::make_pair(value1, value2);
    }
    return test_data;
}
