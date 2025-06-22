#include <iostream>
#include <vector>

std::pair<double, double> ranker(const std::vector<double>&);
double convert_to_cm(double, std::string);

int main(){
    double num{}, largest{}, smallest{};
    std::string unit;
    std::vector<double> stored_values{};

    std::cout << "Enter another any real number with any of the following unit (cm, m, in, ft): \n";

    while (std::cin >> num >> unit){
        if ((unit == "cm") || (unit == "m") || (unit == "in") || (unit == "ft")) {
            num = convert_to_cm(num, unit);
            stored_values.push_back(num);
            std::tie(largest, smallest) = ranker(stored_values);
            std::cout << "The largest so far = " << largest << "cm\n" << "The smallest so far = " << smallest << "cm\n";
        } else {
            std::cout << "Invalid unit" << std::endl;
            std::cout << "Enter another any real number with any of the following unit (cm, m, in, ft): \n";
        }
    }
    return 0;
}

double convert_to_cm(double number, std::string unit){
    if(unit == "m"){
        number *= 100;
    } else if (unit == "in"){
        number *= 2.54;
    } else if (unit == "ft"){
        number *= 30.48;
    }
    return number;
}

std::pair<double, double> ranker(const std::vector<double> &store) {
    double min = store[0];
    double max = store[0];

    for (double num : store){
        if(num < min) min = num;
        if(num > max) max = num;
    }
    return std::make_pair(max, min);
}
