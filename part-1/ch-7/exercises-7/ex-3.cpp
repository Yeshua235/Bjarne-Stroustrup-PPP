#include <iostream>
#include <vector>

std::vector<int> fib_vec{};

std::vector<int> fibonacci(int x, int y, std::vector<int>& vec, int n) {
    if (y < x || x < 0 || n < 2) throw std::runtime_error("Improper arguments.");

    int a = x;
    int b = y;
    int temp{0};

    vec.push_back(x);
    vec.push_back(y);

    if (n == 2) return vec;

    for (int i = 0; i < (n-2); i++) {
        temp = b;
        b += a;
        a = temp;
        vec.push_back(b);
    }

    return vec;
}

void print(const std::string st, const std::vector<int>& vec) {
    for(int v : vec) {
        std::cout << st << v << '\n';
    }
}


int main() {
    try {
        print("fibonacci series ", fibonacci(1, 2, fib_vec, 7));
        return 0;
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
