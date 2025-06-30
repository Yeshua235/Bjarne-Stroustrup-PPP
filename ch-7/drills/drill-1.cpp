#include <iostream>

void swap_p(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/*
This doesn't compile

void swap_cr(const int& a, const int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
*/

int main() {
    int x{7}, y{9};
    //const int cx{7}, cy{9};
    //double dx{7.7}, dy{9.9};

    std::cout << "Before swap\nx = " << x << "\ny = " << y << '\n';
    swap_r(x, y);
    std::cout << "After swap\nx = " << x << "\ny = " << y << '\n';
}