#include <iostream>
#include <vector>

double index(const std::vector<double>& price, const std::vector<double>& weight) {
    if (price.size() != weight.size()) throw std::runtime_error("You passed two vectors of different sizes.");

    double index{0};

    for (std::vector<double>::size_type i = 0; i < price.size(); ++i){
        index += price[i]*weight[i];
    }
    return index;
}

std::vector<double> prices = {5, 7, 13, 11, 17, 19};
std::vector<double> weights = {13.3, 11.5, 5.7, 3.9, 9.7, 9};

int main() {
    try {
        std::cout << index(prices, weights) << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
