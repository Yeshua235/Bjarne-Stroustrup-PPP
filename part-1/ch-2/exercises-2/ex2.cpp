#include <iostream>

int main() {
    double distance{};

    std::cout << "Input the numeric value of the distance you want to convert:\n";
    std::cin >> distance;

    double result = distance * 1.609;

    std::cout << distance << "miles = " << result << "km\n";

    return 0;
}
