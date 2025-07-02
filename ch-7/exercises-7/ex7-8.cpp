#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> names{};
std::vector<double> ages{};

int main() {
    try {
        std::cout << "Input names below, and terminate with ';' on a new line: \n";
        for (std::string name; std::cin >> name;) {
            if (name == ";") break;
            names.push_back(name);
        }

        std::cout << "Input the age for each name below, and terminate with non-numeric character: \n";

        for (double age; std::cin >> age;) {
            ages.push_back(age);
        }

        if (names.size() != ages.size()) throw std::runtime_error("The number of names and ages do not match");

        std::cout << "The unsorted age, name pairs are: \nNAMES\t - \tAGES\n**************************\n";
        for (std::vector<double>::size_type i = 0; i < ages.size(); ++i) {
            std::cout << names[i] << " - " << ages[i] << '\n';
        }

        std::vector<std::string> sorted_names = names;
        std::ranges::sort(sorted_names);

        std::cout << "The sorted age, name pairs are: \nNAMES\t - \tAGES\n**************************\n";
        for (std::string name : sorted_names){
            for (std::vector<double>::size_type i = 0; i < ages.size(); ++i) {
                if (name == names[i]) std::cout << names[i] << " - " << ages[i] << '\n';
            }
        }

        return 0;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}