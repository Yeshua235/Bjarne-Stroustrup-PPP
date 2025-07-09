#include <iostream>
#include <vector>
#include <stdexcept>


int main(){

    try {
        std::vector<int> v;
        std::cout << "Type in some integers: \n";
        for (int i; std::cin >> i;) {
            v.push_back(i);
        }

        // alternatively:
        //for (std::vector<int>::size_type i =0; i <= v.size(); ++i)
        for (size_t i=0; i<=v.size(); ++i){
            std::cout << "v[" << i << "] == " << v.at(i) << '\n'; // [] operator is designed for performance and does not perform bounds checking, while at() function performs bounds checking and throws a std::out_of_range exception if the index is out of range.
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Oops! Range error:\t" << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Exceptions: something went wrong\n";
        return 2;
    }

    return 0;
}