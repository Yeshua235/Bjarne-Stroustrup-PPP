#include <iostream>
#include <vector>

void word_checker(std::string);
std::vector<std::string> hated_words = {"devil", "shit", "mad", "demon", "ghost", "satan", "bad"};

int main(){
    std::cout << "Type in a sentence and I'll return a BLEEP! for every word I hate: \n";
    for (std::string input; std::cin >> input;) {
        word_checker(input);
    }
    return 0;
}

void word_checker(std::string word_to_check) {
    for (std::string word : hated_words) {
        if (word == word_to_check)
            std::cout << "BLEEP!\n";
    }
}
