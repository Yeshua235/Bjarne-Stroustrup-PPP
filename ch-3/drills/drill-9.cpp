#include <iostream>
#include <vector>

std::pair<double, double> ranker(const std::vector<double>&);
double convert_to_cm(double, std::string);
double summing_up(const std::vector<double>&);


int main(){
    double num{}, largest{}, smallest{}, sum{};
    int number_of_values{};

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

    sum = summing_up(stored_values);
    number_of_values = stored_values.size();

    std::cout << "smallest = " << smallest << '\n'
                << "largest = " << largest << '\n'
                << "total number of values = " << number_of_values << '\n'
                << "sum of all values = " << sum << "m\n";
    return 0;
}

double summing_up(const std::vector<double> &num_store){
    double sum = 0;
    for (double number : num_store) sum += number;
    sum /= 100;
    return sum;
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
