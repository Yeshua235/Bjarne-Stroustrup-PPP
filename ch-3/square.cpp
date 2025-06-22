#include <iostream>

int square(int x);

int main() {
    int n{};
    std::cout << "Enter an integer you'd like to square: \n";
    std::cin >> n;
    std::cout << "square of " << n << " = " << square(n) << '\n';
    return 0;
}

int square(int x){
    if (x < 0)
        x = -x;

    const int num = x;
    for(int i=0; i<(num-1); ++i) {
        x+=num;
    }
    return x;
}
