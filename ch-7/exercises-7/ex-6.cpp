#include <iostream>
#include <vector>

std::vector<std::string>rev_new_vec(const std::vector<std::string>& vec) {
    if (vec.size() == 0) throw std::runtime_error("You gave an empty vector.");

    std::vector<std::string> new_vec{};

    for (int i = (vec.size() - 1); i > -1; --i) {
        new_vec.push_back(vec[i]);
    }

    return new_vec;
}

std::vector<std::string>rev_org_vec(std::vector<std::string>& vec) {
    if (vec.size() == 0) throw std::runtime_error("You gave an empty vector.");

    int a = 0;
    int b = vec.size() - 1;

    while (b > a && b != a) {
        std::swap(vec[a], vec[b]);
        --b;
        ++a;
    }

    return vec;
}

std::vector<std::string> my_vector = {"my", "first", "string", "vector"};
std::vector<std::string> another_vector = {"MY", "SECOND", "STRING", "VECTOR"};

int main() {
    try {
        for (std::string v : rev_org_vec(my_vector)) {
            std::cout << v << '\n';
        }

        std::cout << "************************\n";

        for (std::string v : rev_new_vec(another_vector)) {
            std::cout << v << '\n';
        }

    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

