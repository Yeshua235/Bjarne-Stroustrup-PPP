#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> input_converter(std::string, std::string);

const std::vector <std::string> num_word = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const std::vector <std::string> num_digit = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int main() {

    double result{0};
    bool invalid_input{false};
    std::string input1, input2, operation;

    double var1{0}, var2(0);
    char op{'%'};

    std::cout << "+, -, x and /\n" << "Input two integers (written in words or digits) in the range [0-9] followed by any of the symbols above to add, subtract, multiply or divide them respectively. All seperated by spaces: \n";

    while (std::cin >> input1 >> input2 >> op) {

        std::tie(var1, var2) = input_converter(input1, input2);

        switch (op)
        {
        case '+':
            result = var1 + var2;
            operation = "sum";
            break;

        case '-':
            result = var1 - var2;
            operation = "difference";
            break;

        case 'x':
            result = var1 * var2;
            operation = "product";
            break;

        case '/':
            result = var1 / var2;
            operation = "quotient";
            break;

        default:
            invalid_input = true;
            break;
        }

        if (var1 == -7 || var2 == -7) {
            std::cout << "You did not follow the instructions on the input you are to provide. Try again:\n";
        } else if (invalid_input) {
            std::cout << op << " is not a valid operand. Try again:\n";
        } else if (!invalid_input) {
            std::cout << "The " << operation << " of the inputs is " << result << '\n';
        }
    }

}

std::pair<int, int> input_converter(std::string v1, std::string v2) {
    int var1{-7}, var2{-7};
    for (int i=0; i < 10; i++) {
        if (v1 == num_word[i] || v1 == num_digit[i]) var1 = i;
        if (v2 == num_word[i] || v2 == num_digit[i]) var2 = i;
    }

    return std::make_pair(var1, var2);
}
