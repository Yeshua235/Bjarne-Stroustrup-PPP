#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> count_string(const std::vector<std::string>& vec) {
    if (vec.size() == 0) throw std::runtime_error("you passed an empty vector count_string.");

    std::vector<int> string_count;

    for (std::string word : vec) {
        int char_count{0};
        for (char ch : word) ++char_count; //flaged as unused variable.
        string_count.push_back(char_count);
    }
    return string_count;
}

std::pair<int, int> min_max(std::vector<int> vec) {
    std::ranges::sort(vec);
    int min = vec[0];
    int max = vec[vec.size()-1];
    return std::make_pair(min, max);
}

std::pair<std::string, std::string> long_short_string (const std::vector<std::string>& vec) {
    if (vec.size() == 0) throw std::runtime_error("you passed an empty vector count_string.");

    std::vector<int> index = count_string(vec);
    int min{0}, max{0}, min_index{0}, max_index{};

    std::tie(min, max) = min_max(index);

    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i) {
        if (index[i] == min) min_index = i;
        if (index[i] == max) max_index = i;
    }

    std::string shortest_string = vec[min_index];
    std::string longest_string = vec[max_index];

    return std::make_pair(longest_string, shortest_string);
}

std::pair<std::string, std::string> lex_first_last (std::vector<std::string>& vec) {
    if (vec.size() == 0) throw std::runtime_error("you passed an empty vector count_string.");

    std::ranges::sort(vec);
    std::string lex_first = vec[0];
    std::string lex_last = vec[vec.size()-1];

    return std::make_pair(lex_first, lex_last);
}

int main() {
    try{
        std::vector<std::string> my_string = {"my", "custom", "vector", "of", "strings"};

        std::cout << "printing the vector of string counts...\n";

        for (int num : count_string(my_string)) {
            std::cout << num << ", ";
        }
        std::cout << '\n';

        std::string longest_string, shortest_string, lex_first, lex_last;

        std::tie(longest_string, shortest_string)  = long_short_string(my_string);
        std::tie(lex_first, lex_last) = lex_first_last(my_string);

        std::cout << "longest string = " << longest_string << "\nshortest string = " << shortest_string << '\n';
        std::cout << "lexicographically first string = " << lex_first << "\nlexicographically last string = " << lex_last << '\n';

        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}