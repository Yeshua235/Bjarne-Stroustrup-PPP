#include <iostream>

int main() {
    char letter{'a'};

    while(letter <= int{'z'}) {
        std::cout << letter << '\t' << int{letter} << '\n';
        ++letter;
    }
    return 0;
}

