#include <iostream>

int main(){
    int num;

    while (true) {
        std::cout << "Enter an integer: \n";
        std::cin >> num;

        if (num%2 == 0) {
            std::cout << "The number " << num << " is an even number.\n";
        } else {
            std::cout << "The number " << num << " is an odd number.\n";
        }
    } ;

    return 0;
}
