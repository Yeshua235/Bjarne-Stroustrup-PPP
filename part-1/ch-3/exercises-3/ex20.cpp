#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> names;
    std::vector<int> scores;

    std::string name;
    int score;
    std::cout << "Input Names and Scores seperated by spaces.\nEnd data entry with -1: \n";
    while(std::cin >> name >> score && score != -1) {
        if(names.size() == 0 || scores.size() == 0) {
            names.push_back(name);
            scores.push_back(score);
        } else {
            for(std::string value : names) {
                if (name == value){
                    std::cout << "This name already exist's in the database.\n";
                    return 1;
                }
            }
            names.push_back(name);
            scores.push_back(score);
        }
        if(names.size()!=0 && scores.size()!=0){
            std::cout << "\n______________\n";
            for(int i=0; i < int(names.size()); ++i){
                std::cout << names[i] << '\t' << scores[i] << '\n';
            }
            std::cout << "-------------\n";
        }
    }
    std::cout << "You have entered query mode.\nEnter the name and score you'd like to query: \n";
    while(std::cin >> name >> score){
        std::vector<std::string> query_names;
        std::vector<int> query_scores;
        if(names.size()!=0 && scores.size()!=0){
            for(int i=0; i < int(names.size()); ++i) {
                if(name == names[i])query_scores.push_back(scores[i]);
                if(score == scores[i])query_names.push_back(names[i]);
            }
            if(query_names.size() != 0) {
                std::cout << "names with the score " << score << " are listed below.\n";
                for (std::string name : query_names) {
                    std::cout << name << '\n';
                }
            } else {
                std::cout << "There is no entry to display for your query.\n";
            }
            if(query_scores.size() != 0) {
                std::cout << "scores belonging to " << name << " are listed below.\n";
                for (int score : query_scores) {
                    std::cout << score << '\n';
                }
            } else {
                std::cout << "There is no entry to display for your query.\n";
            }
        }
    }
    return 0;
}
