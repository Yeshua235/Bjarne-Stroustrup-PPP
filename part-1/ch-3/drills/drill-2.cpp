#include <iostream>

std::pair<int, int> ranker(int, int);

int main(){
    int num1{}, num2{}, greater{}, smaller{};;

    std::cout << "Enter another two integers: \n";

    while (std::cin >> num1 >> num2){
        if (num1 == num2) {
            std::cout << "<----->\n" << num1 << " is equal to " << num2 << "\n<----->\n\n";
        } else {
            std::tie(greater, smaller) = ranker(num1, num2);
            std::cout << "<----->\nGreater = " << num1 << "\nsmaller = " << num2 << "\n<----->\n\n";
        }
    }
    return 0;
}

std::pair<int, int> ranker(int x, int y) {
    int greater{}, smaller{};
    if (x >= y){
        greater = x;
        smaller = y;
    } else {
        greater = y;
        smaller = x;
    }
    return std::make_pair(greater, smaller);
}
