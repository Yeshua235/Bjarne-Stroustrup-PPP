#include <iostream>

int factorial(int num) {
    if (num < 0) throw std::runtime_error("operation not defined for negative integers");
    if (num == 0) return 1; else return num*factorial(num-1);
}

int permutation(int a, int b) {
    if (a < 0 || b < 0) {
        throw std::runtime_error("Math Error: operation not defined for negative integers");
    } else if(b > a) {
        throw std::runtime_error("the second operand cannot be greater than the first operand");
    } else {
        return (factorial(a)/factorial(a-b));
    }
}

int combination(int a, int b) {
    if (a < 0 || b < 0) {
        throw std::runtime_error("Math Error: operation not defined for negative integers");
    } else if(b > a) {
        throw std::runtime_error("the second operand cannot be greater than the first operand");
    } else {
        return (permutation(a, b)/factorial(b));
    }
}


int main() {
    std::cout << "Input two integers you would like to perform either a permutation or combination on: \n";

    try {
        int a{0}, b{0}, result{0};
        char op{};
        std::string operation;

        if (std::cin >> a >> b) {
            std::cout << "Enter 'p' to perform permutation or 'c' to perform combination: \n";
            if (std::cin >> op) {
                switch (op) {
                    case 'c':
                        result = combination(a, b);
                        operation = "combination";
                        break;
                    case 'p':
                        result = permutation(a, b);
                        operation = "permutation";
                        break;
                    default:
                        throw std::runtime_error("Unrecognized input for operation to perform");
                }
            } else {
                    throw std::runtime_error("There was an error reading in your input");
            }
        } else {
            throw std::runtime_error("There was an error reading in your input");
        }
        std::cout << operation << '(' << a << ',' << b << ") = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Oops! An exception occured." << std::endl;
    }
    return 0;
}
