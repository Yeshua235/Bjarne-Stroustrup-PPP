#include <iostream>
#include <vector>
#include <random>

int random_number_generator();
std::vector<int> get_user_input();

int main() {
    bool stop = false;
    char continue_game = 'y';

    std::cout << "Welcome to Guess Random Number Game.\nYou have 4 chances to correctly guess a randomly generated number.\n'Bull' show number of correct guess(es) in the right position and 'Cow' shows number of correct guess(es) in the wrong position.\n Ensure to seperate your input with spaces or Enter button.\nLet's begin.\n\nInitiating a new round...\n\n" << std::endl;

    while (!stop) {
        std::vector<int> numbers_list(4), guesses_list(4);

        numbers_list.clear();
        guesses_list.clear();

        for(int i=0; i<4; ++i){
            numbers_list.push_back(random_number_generator());
        }

        bool current_round = true;
        int chance_remaining = 4;

        while(current_round && chance_remaining > 0){
            int bull{0}, cow{0};
            guesses_list.clear();

            std::cout << "Guess the digits in the random four digit number: \n";

            try {
                guesses_list = get_user_input();
            } catch (const std::exception& e) {
                std::cerr << "An Error occured.\nException caught: " << e.what() << "\n\nInitiating a new round...\n\n";
                break;
            }

            for(std::vector<int>::size_type i = 0; i < numbers_list.size(); ++i){
                for(std::vector<int>::size_type j = 0; j < guesses_list.size(); ++j){
                    if(guesses_list[j] == numbers_list[i] && j==i) {
                        ++bull;
                    } else if (guesses_list[j] == numbers_list[i] && j!=i) {
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
                std::cout << "The correct number is: ";
                for (int number : numbers_list) std::cout << number << " ";
                std::cout << "\nYou lose.\n\nInitiating another round...\n\n";
            }

        }

    }
    return 0;
}

int random_number_generator() {
    std::random_device rd;
    std::mt19937_64 gen(rd());

    std::uniform_int_distribution<int> dist(0, 9);

    return dist(gen);
}

std::vector<int> get_user_input(){
    std::vector<int> user_input;
    user_input.clear();
    int num1, num2, num3, num4;

    if (std::cin >> num1 >> num2 >> num3 >> num4) {

        user_input.push_back(num1);
        user_input.push_back(num2);
        user_input.push_back(num3);
        user_input.push_back(num4);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return user_input;
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("An error occured while reading your input.");
    }
}
