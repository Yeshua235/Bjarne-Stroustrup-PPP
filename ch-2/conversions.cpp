#include <iostream>

int main() {

    double d = 0;

    while (std::cin >> d) {
        int i = d;
        char c = i;

        std::cout << "d == " << d
                << "\ni == " << i
                << "\nc == " << c
                << "\nchar(" << c << ")\n";
    }
}