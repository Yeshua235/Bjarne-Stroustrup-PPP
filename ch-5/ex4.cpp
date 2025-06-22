#include <iostream>
#include <vector>

int main() {
    class Name_values {
        public:
            std::string name;
            int value;

            Name_values(std::string given_name, int val): name{given_name}, value{val} {};
    };

    std::vector<Name_values> names_and_scores;

    std::string name;
    int score;
    std::cout << "Input Names and Scores seperated by spaces.\nEnd data entry with -1: \n";
    while(std::cin >> name >> score && score != -1) {
        if(names_and_scores.size() == 0) {
            // names_and_scores.push_back(Name_values(name, score)); // creates a temporary Name_values object and pushes it into the vector

            names_and_scores.emplace_back(name, score);
            //for in-place construction of the Name_values object - This avoids a temporary object and constructs the Name_values directly inside the vector (slightly more efficiently)
        } else {
            for(const Name_values& nv : names_and_scores) {
                if (name == nv.name){
                    std::cout << "This name already exist's in the database.\n";
                    return 1;
                }
            }
            names_and_scores.emplace_back(name, score);
        }
        if(names_and_scores.size() != 0){
            std::cout << "\n______________\n";
            for(const Name_values& nv : names_and_scores){
                std::cout << nv.name << '\t' << nv.value << '\n';
            }
            std::cout << "-------------\n";
        }
    }
    std::cout << "You have entered query mode.\nEnter the name and score you'd like to query: \n";
    while(std::cin >> name >> score){
        std::vector<std::string> query_names;
        std::vector<int> query_scores;
        if(names_and_scores.size() != 0){
            for(const Name_values& nv : names_and_scores) {
                if(name == nv.name)query_scores.push_back(nv.value);
                if(score == nv.value)query_names.push_back(nv.name);
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
