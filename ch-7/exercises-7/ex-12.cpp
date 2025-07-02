#include <iostream>
#include <vector>

void print_until_ss(const std::vector<std::string>& vec, const std::string quit) {
    int count = 0;

    for (std::string s : vec) {
        if (s == quit) ++count;
        if (!(count < 2)) break;
    }

    std::cout << quit << " - x2\n";
}

int main() {
    std::vector<std::string> my_string_vec = {"my", "string", "stop", "vectors", "is", "stop", "here"};
    print_until_ss(my_string_vec, "stop");
    return 0;
}