#include <iostream>
#include <vector>

int main() {
    double a = 1, b = 1, temp = 0, N;

    std::cout << "How many first N fibonacci series do you want? : \n";
    std::cin >> N;

    for (int i=1; i<N+1; ++i) {
        if (i<3){
            std::cout << b << " ";
        } else {
            temp = b;
            b += a;
            a = temp;
            std::cout << b << " ";
        }
    }
    std::cout << ".\n";
    return 0;
}


