#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int N{0}, sum{0};

    try {
        std::cout << "please enter the number of values you want to sum: \n";
        if(std::cin >> N) {
            if (N < 0) throw std::runtime_error("wrong input for number of sum");
        } else {
            throw std::runtime_error("Error reading in input. You are to input an integer number");
        }

        std::cout << "please enter some integers and terminate with any other character: \n";
        for(int num; std::cin >> num;) {
            numbers.push_back(num);
        }

        for (int i = 0; i < N; ++i) {
            sum += numbers.at(i);
        }
        std::cout << "The sum of the first " << N << " integers is: " << sum << std::endl;
    } catch (const std::runtime_error& rte) {
        std::cerr << rte.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception encountered: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Oops! An unknown error occured.\n";
    }

    return 0;
}
