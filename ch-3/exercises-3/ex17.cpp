#include <iostream>
#include <cmath>

int main() {
    double a{}, b{}, c{}, x1{}, x2{};

    std::cout << "Input the values for the variables a, b, and c in the quadratic equation: \n";
    std::cin >> a >> b >> c;

    x1 = (-b + std::sqrt((b*b) - (4*a*c))) / (2*a);
    x2 = (-b - std::sqrt((b*b) - (4*a*c))) / (2*a);

    std::cout << "X_1 = " << x1 << '\n'
                << "X_2 = " << x2 << '\n';
    return 0;
}
