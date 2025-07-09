#include <iostream>

int main() {
    for(char letter{'a'}; letter <= 'z'; ++letter) {
        std::cout << letter << '\t' << int{letter} << '\n';
    }

    std::cout << '\n';

    for(char letter{'A'}; letter <= 'Z'; ++letter) {
        std::cout << letter << '\t' << int{letter} << '\n';
    }
}
