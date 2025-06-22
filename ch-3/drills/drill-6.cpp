#include <iostream>
#include <vector>

std::pair<double, double> ranker(const std::vector<double>&);

int main(){
    double num{}, largest{}, smallest{};
    std::vector<double> stored_values{};

    std::cout << "Enter another any real numbers: \n";

    while (std::cin >> num){
        stored_values.push_back(num);
        std::tie(largest, smallest) = ranker(stored_values);
        std::cout << "The largest so far = " << largest << '\n' << "The smallest so far = " << smallest << '\n';
    }
    return 0;
}

std::pair<double, double> ranker(const std::vector<double> &store) {
    double min = store[0];
    double max = store[0];

    for (double num : store){
        if(num < min) min = num;
        if(num > max) max = num;
    }

    return std::make_pair(max, min);
}
