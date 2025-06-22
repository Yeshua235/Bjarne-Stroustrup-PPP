#include <iostream>
#include <vector>
#include <random>

int random_number_generator();
std::vector<char> get_user_input();
std::vector<char> letters{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main() {
    bool stop = false;
    char continue_game = 'y';

    std::cout << "Welcome to Guess Random CAPITAL Letters Game.\nYou have 4 chances to correctly guess 4 randomly generated capital letters.\n'Bull' show number of correct guess(es) in the right position and 'Cow' shows number of correct guess(es) in the wrong position.\n Ensure to seperate your input with spaces or Enter button.\nLet's begin.\n\nInitiating a new round...\n\n" << std::endl;

    while (!stop) {
        std::vector<char> letters_list(4), guesses_list(4);

        letters_list.clear();
        guesses_list.clear();

        for(int i=0; i<4; ++i){
            letters_list.push_back(letters[random_number_generator()]);
        }

        bool current_round = true;
        int chance_remaining = 4;

        while(current_round && chance_remaining > 0){
            int bull{0}, cow{0};
            guesses_list.clear();

            std::cout << "Guess the letters of the random four letters: \n";

            try {
                guesses_list = get_user_input();
            } catch (const std::exception& e) {
                std::cerr << "An Error occured.\nException caught: " << e.what() << "\n\nInitiating a new round...\n\n";
                break;
            }

            for(std::vector<int>::size_type i = 0; i < letters_list.size(); ++i){
                for(std::vector<int>::size_type j = 0; j < guesses_list.size(); ++j){
                    if(guesses_list[j] == letters_list[i] && j==i) {
                        ++bull;
                    } else if (guesses_list[j] == letters_list[i] && j!=i) {
                        ++cow;
                    } else {
                        continue;
                    }
                }
            }

            std::cout << "Bull: " << bull << "\nCow: " << cow << std::endl;

            if (bull==4) {
                std::cout << "\nCongratulations! You win.\n";
                current_round = false;
                chance_remaining = 0;
            } else {
                std::cout << "Oops! You're wrong!.\n";
                --chance_remaining;
                std::cout << "You have " << chance_remaining << " number of chances left.\n";
            }

            std::cout << "To continue press 'y', to end the game press anyother key.\n";

            try {
                if(std::cin >> continue_game){
                    if (continue_game == 'y') {
                        stop = false;
                    } else {
                        stop = true;
                        break;
                    }
                } else {
                    throw std::invalid_argument("An error occured while reading your input.");
                }
            } catch (const std::exception& e) {
                std::cerr << "An Error occured.\nException caught: " << e.what() << "\n\nInitiating a new round...\n" << std::endl;
                current_round = false;
                chance_remaining = 0;
                break;
            }

            if (chance_remaining == 0) {
                std::cout << "The correct Letters are: ";
                for (char let : letters_list) std::cout << let << " ";
                std::cout << "\nYou lose.\n\nInitiating another round...\n\n";
            }

        }

    }
    return 0;
}

int random_number_generator() {
    std::random_device rd;
    std::mt19937_64 gen(rd());

    std::uniform_int_distribution<int> dist(0, 25);

    return dist(gen);
}

std::vector<char> get_user_input(){
    std::vector<char> user_input;
    user_input.clear();
    char let1, let2, let3, let4;

    if (std::cin >> let1 >> let2 >> let3 >> let4) {

        user_input.push_back(let1);
        user_input.push_back(let2);
        user_input.push_back(let3);
        user_input.push_back(let4);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return user_input;
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("An error occured while reading your input.");
    }
}
