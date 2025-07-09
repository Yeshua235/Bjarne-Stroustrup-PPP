#include <iostream>

void word_checker();

int main() {

    word_checker();

}

void word_checker() {
    std::string previous, current;
    int word_position = 0;

    while (std::cin >> current) {
        ++word_position;
        if (current ==  previous)
            std::cout << "repeated word: " << current << "\tword number " << word_position << '\n';
        previous  = current;
    }
}
