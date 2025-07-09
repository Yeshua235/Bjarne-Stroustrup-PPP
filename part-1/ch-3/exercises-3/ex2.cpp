#include <iostream>

int main(){
    std::string word;
    std::cout << "Type a word or sentence below: \n";
    std::getline(std::cin, word);
    for(char letter : word){
        std::cout << letter << '\t' << int(letter) << '\n';
    }
    return 0;
}
