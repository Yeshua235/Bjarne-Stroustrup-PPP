#include <iostream>

int main() {
    int val1{}, val2{}, greater{}, lesser{}, sum{}, diff{}, product{}, integer_ratio{};

    do {
        std::cout << "Enter two different integers: \n";
        std::cin >> val1  >> val2;
    } while (val1 == val2);

    if (val1 > val2) {
        greater = val1;
        lesser = val2;
    } else {
        greater = val2;
        lesser = val1;
    }

    sum = val1 + val2;
    diff = greater - lesser;
    product = val1*val2;
    integer_ratio = val1/val2;

    std::cout << "Greater = " << greater
                << "\nLesser = " << lesser
                << "\nSum = " << sum
                << "\nDifference = " << diff
                << "\nProduct = " << product
                << "\nRatio = " << integer_ratio << '\n';

    return 0;
}
