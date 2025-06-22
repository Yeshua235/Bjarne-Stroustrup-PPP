#include <iostream>
#include <utility>

std::pair<int, int> check_order(int x, int y);

int main() {
    int val1{}, val2{}, val3{}, greatest{}, greater{}, least{};

    std::cout << "Enter three (3) integers of your choice: \n";
    std::cin >> val1 >> val2 >> val3;

    if (val1 >= val2 && val1 >= val3) {
        greatest = val1;
    } else if (val2 >= val1 && val2 >= val3) {
        greatest = val2;
    } else if (val3 >= val1 && val3 >= val2) {
        greatest = val3;
    }

    int p{}, q{};
    if (greatest == val1) {
        p = val2;
        q = val3;
    } else if (greatest == val2) {
        p = val1;
        q = val3;
    } else if (greatest == val3){
        p = val1;
        q = val2;
    }
    std::tie(greater, least) = check_order(p, q);

    std::cout << least << ", " << greater << ", " << greatest << ".\n";

    return 0;
}

std::pair<int, int> check_order(int x, int y) {
    int greater{}, least{};
    if (x >= y) {
        greater = x;
        least = y;
    } else {
        greater = y;
        least = x;
    }
    return std::make_pair(greater, least);
}
