#include <iostream>

int main(){
    int num1, num2;

    std::cout << "Enter another two integers: \n";

    while (std::cin >> num1 >> num2){
        std::cout << "<---\t" << num1 << '\t' << num2 << "\t--->\n";
    }
    return 0;
}
