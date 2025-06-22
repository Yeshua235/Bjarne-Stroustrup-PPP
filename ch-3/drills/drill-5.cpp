#include <iostream>

std::pair<double, double> ranker(double, double);

int main(){
    double num1{}, num2{}, greater{}, smaller{};;

    std::cout << "Enter another two real numbers: \n";

    while (std::cin >> num1 >> num2){
        if (num1 == num2) {
            std::cout << "<----->\n" << num1 << " is equal to " << num2 << "\n<----->\n\n";
        } else {
            std::tie(greater, smaller) = ranker(num1, num2);
            std::cout << "<----->\nGreater = " << num1 << "\nsmaller = " << num2;
            if ((greater - smaller) < (1.0/100)) {
                std::cout << "\nThe numbers are almost equal";
            }
            std::cout << "\n<----->\n\n";
        }
    }
    return 0;
}

std::pair<double, double> ranker(double x, double y) {
    double greater{}, smaller{};
    if (x >= y){
        greater = x;
        smaller = y;
    } else {
        greater = y;
        smaller = x;
    }
    return std::make_pair(greater, smaller);
}
