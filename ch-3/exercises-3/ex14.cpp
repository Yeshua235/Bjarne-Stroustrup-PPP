#include <iostream>
#include <algorithm>
#include <vector>

bool check_prime(int);

int main() {
    std::vector<int> primes;
    std::cout << "Input any integer greater than 0, to know the primes less than that number: \n";

    for (int num; std::cin >> num;) {
        if (num > 2){
            primes.push_back(2);
            for(int i = 3; i <= num; i++) {
                bool is_prime = check_prime(i);
                if (is_prime == true){
                    int count = 0;
                    for(int prime : primes){
                        if (i == prime){
                            count = 1;
                            break;
                        }
                    }
                    if (count == 0) primes.push_back(i);
                }
            }
        } else if (num == 2) {
            primes.push_back(num);
        }

        if(primes.size() != 0){
            std::ranges::sort(primes);
            std::cout << "\nThe Prime numbers are: \n";
            for(int prime : primes){
                    std::cout << prime << '\t';
                }
                std::cout << '\n' << std::endl;
        } else {
            std::cout << "There are no positive primes less than that." << std::endl;
        }
        primes = {};
    }
    return 0;
}

bool check_prime(int var) {
    for (int i = 2; i < var; ++i) {
        if((var % i) == 0){
            return false;
        }
    }

    return true;
}