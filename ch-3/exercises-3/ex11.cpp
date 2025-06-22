#include <iostream>
#include <vector>
#include <utility>

std::string check_winner (char, char);

int main(){
    std::vector<char> store = {'s', 'r', 'p', 'p', 's', 'r', 'p', 'r', 's'};
    std::tuple<std::string, int, std::string, int> scoreboard = {"player_1", 0, "player_2", 0};
    std::string winning_player;

    std::cout << "Welcome to my Rock, Paper and Scissors game.\nYou are player_1 and the Computer is player_2.\nYou play by typing r, p or s, for Rock, Paper and Scissors respectively.\n\n";
    int index{};
    for(char play; std::cin >> play;){
        switch(play){
            case 's':
                index = 4;
                break;
            case 'p':
                index = 1;
                break;
            case 'r':
                index = 6;
                break;
            default:
                std::cout << "Enter a proper input\n";
        }
        std::cout << "Computer plays " << store[index] << '\n';
        winning_player = check_winner(play, store[index]);
        if (winning_player == "player_1") {
            std::get<1>(scoreboard) += 1;
        } else if (winning_player == "player_2") {
            std::get<3>(scoreboard) += 1;
        }

        for (int index = 0; index < 4; ++index) {
            std::cout << std::get<0>(scoreboard) << '\t'
                        << std::get<1>(scoreboard) << '\t'
                        << std::get<2>(scoreboard) << '\t'
                        << std::get<3>(scoreboard) << '\n';
        }
        std::cout << std::endl;
    }
    return 0;
}

std::string check_winner (char player_1, char player_2){
    std::string winner;
    if((player_1 == 'r') && (player_2 == 's')){
        winner = "player_1";
    } else if ((player_1 == 's') && (player_2 == 'p')) {
        winner = "player_1";
    } else if ((player_1 == 'p') && (player_2 == 'r')) {
        winner = "player_1";
    } else if (player_1 == player_2) {
        winner = "draw";
    } else {
        winner = "player_2";
    }
    return winner;
}
