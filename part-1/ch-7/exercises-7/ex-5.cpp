#include <iostream>
#include <vector>

std::vector<int>rev_new_vec(const std::vector<int>& vec) {
    if (vec.size() == 0) throw std::runtime_error("You gave an empty vector.");

    std::vector<int> new_vec{};

    for (int i = (vec.size() - 1); i > -1; --i) {
        new_vec.push_back(vec[i]);
    }

    return new_vec;
}

std::vector<int>rev_org_vec(std::vector<int>& vec) {
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

std::vector<int> my_vector = {1, 2, 3, 4, 5};
std::vector<int> another_vector = {6, 7, 8, 9, 10};

int main() {
    try {
        for (int v : rev_org_vec(my_vector)) {
            std::cout << v << '\n';
        }

        std::cout << "************************\n";

        for (int v : rev_new_vec(another_vector)) {
            std::cout << v << '\n';
        }

    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

