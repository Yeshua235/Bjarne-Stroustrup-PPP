#include <iostream>
#include <vector>

void print(const std::string st, const std::vector<int>& vec) {
    for(int v : vec) {
        std::cout << st << v << '\n';
    }
}
