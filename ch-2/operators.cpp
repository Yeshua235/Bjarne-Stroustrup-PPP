#include <iostream>
#include <cmath>

int main() {
    // % (modulo) operator only applies to integer

    std::cout << "Enter a floating-point number: ";
    double n=0;
    std::cin >> n;

    std::cout << "n == " << n
                <<"\nn+1 == " << n+1
                <<"\nthree times n == " << 3*n
                <<"\ntwice n == " << n+n
                <<"\nn squared == " << n*n
                <<"\nhalf of n == " << n/2
                <<"\nsquare root of n == " << std::sqrt(n)
                <<"\n";

    std::cout << "Enter your fullname: ";
    std::string name;
    std::getline(std::cin >> std::ws, name); // td::ws -to clear only whitespaces left by the previus use of std::cin,
                                            // a more verbose alternative to this is shown below, can be used to clear any junk left in the input buffer.

                                            //---the initial std::cin >> variable;
                                            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                            // std::type variable
                                            // std::getline(std::cin, variable);


    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // std::getline(std::cin, name);
    std::cout << "Hello " << name << "!\n";

    std::string first, second, concatenated_name;
    std::cout << "Enter your firstname and lastname:\n";
    std::cin >> first >> second;

    concatenated_name = first + ' ' + second;
    std::cout << "Hello, " << concatenated_name << '\n';

}
