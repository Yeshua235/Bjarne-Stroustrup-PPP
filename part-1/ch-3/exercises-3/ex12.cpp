#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> primes;
    std::cout << "Input any integer greater than 0, to know if it's a prime or not: \n";

    for (int num; std::cin >> num;) {
        if (num > 2) {
            for (int i = 2; i < num; ++i) {
                if((num % i) == 0){
                    num = 0;
                    break;
                }
            }
            if (num != 0){
                int count = 0;
                for(int prime : primes){
                    if (num == prime){
                        count = 1;
                        break;
                    }
                }
                if (count == 0) primes.push_back(num);
            }
        } else if (num == 2) {
            primes.push_back(num);
        }

    if (primes.size() != 0){
        std::ranges::sort(primes);
        std::cout << "\nThe Prime numbers you have entered yet are: \n";
        for(int prime : primes){
                std::cout << prime << '\t';
            }
            std::cout << "\n\n";
        }
    }
    return 0;
}
