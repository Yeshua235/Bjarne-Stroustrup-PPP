#include <iostream>
#include <utility>

std::pair<std::string, std::string> check_order(std::string x, std::string y);

int main() {
    std::string val1{}, val2{}, val3{}, greatest{}, greater{}, least{};

    std::cout << "Type three (3) words of your choice seperated by spaces and all in small caps: \n";
    std::cin >> val1 >> val2 >> val3;

    if (val1 >= val2 && val1 >= val3) {
        greatest = val1;
    } else if (val2 >= val1 && val2 >= val3) {
        greatest = val2;
    } else if (val3 >= val1 && val3 >= val2) {
        greatest = val3;
    }

    std::string p{}, q{};
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

std::pair<std::string, std::string> check_order(std::string x, std::string y) {
    std::string greater{}, least{};
    if (x >= y) {
        greater = x;
        least = y;
    } else {
        greater = y;
        least = x;
    }
    return std::make_pair(greater, least);
}
