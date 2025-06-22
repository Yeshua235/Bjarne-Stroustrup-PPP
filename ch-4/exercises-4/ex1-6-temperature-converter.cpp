#include <iostream>
#include <stdexcept>

double c_and_k(double, char);
double c_and_f(double, char);
double k_and_f(double, char);

bool c_check(double);
bool k_check(double);
bool f_check(double);

int main() {
    double temp = 0, output = 0;
    char unit_from, unit_to;
    try {
        std::cout << "Input a temperature value: ";
        std::cin >> temp;
        std::cout << "Input in small letter, the first letter of the unit you are converting from: ";
        std::cin >> unit_from;
        std::cout << "Input in small letter, the first letter of the unit you are converting to: ";
        std::cin >> unit_to;

        if((unit_to=='c' && unit_from=='k') || (unit_to=='k' && unit_from=='c')) {
            output = c_and_k(temp, unit_from);
        } else if ((unit_to=='f' && unit_from=='c') || (unit_to=='c' && unit_from=='f')) {
            output = c_and_f(temp, unit_from);
        } else if ((unit_to=='f' && unit_from=='k') || (unit_to=='k' && unit_from=='f')) {
            output = k_and_f(temp, unit_from);
        } else {
            std::cout << "Unknown temperature unit.\nExiting the program now...\n";
            return -2;
        }

        std::cout << temp << unit_from << " = " << output << unit_to << "\n";

    } catch (const std::exception& e) {
            std::cout << e.what() << "\n";
            return -1;
    } catch(...) {
        std::cout << "Oops: An unknown error occured.\n";
        return -3;
    }

    return 0;
}


double c_and_k(double temp, char unit){
    bool check = false;
    switch(unit){
    case 'c':
        check = c_check(temp);
        if(check) {
            double k =  temp + 273.25;
            return k;
        } else {
            throw std::runtime_error("The temperature you input is less the lowest possible temperature (-273.15 celsius)");
        }
        break;
    case 'k':
        check = k_check(temp);
        if(check) {
            double c = temp - 273.25;
            return c;
        } else {
            throw std::runtime_error("The temperature you input is less the lowest possible temperature (0 kelvin)");
        }
        break;
    default:
        throw std::invalid_argument("Unknown temperature unit.\nExiting the program now...");
    }
}

double c_and_f(double temp, char unit){
    bool check = false;
    switch(unit) {
    case 'c':
        check = c_check(temp);
        if(check) {
            double f =  temp*(9.0/5.0) + 32.0;
            return f;
        } else {
            throw std::runtime_error("The temperature you input is less the lowest possible temperature (-273.15 celsius)");
        }
        break;
    case 'f':
        check = f_check(temp);
        if(check) {
            double c = (temp - 32.0)*5.0/9.0;
            return c;
        } else {
            throw std::runtime_error("The temperature you input is less the lowest possible temperature (-169.528 fahrenheit)");
        }
        break;
    default:
        throw std::invalid_argument("Unknown temperature unit.\nExiting the program now...");
        break;
    }
}

double k_and_f(double temp, char unit){
    bool check = false;
    switch(unit){
    case 'k':
        check = k_check(temp);
        if(check) {
            double temp_c = c_and_k(temp, unit);
            unit = 'c';
            double f = c_and_f(temp_c, unit);
            return f;
        } else {
            throw std::runtime_error("The temperature you input is less the lowest possible temperature (0 kelvin)");
        }
        break;
    case 'f':
        check = f_check(temp);
        if(check) {
            double temp_c = c_and_f(temp, unit);
            unit = 'c';
            double k = c_and_k(temp_c, unit);
            return k;
        } else {
            throw std::runtime_error("The temperature you input is less the lowest possible temperature (-169.528 fahrenheit)");
        }
        break;
    default:
        throw std::invalid_argument("Unknown temperature unit.\nExiting the program now...");
        break;
    }
}


bool c_check(double temp) {
    if(temp < -273.15) {
        return false;
    } else {
        return true;
    }
}

bool k_check(double temp) {
    if(temp < 0) {
        return false;
    } else {
        return true;
    }
}

bool f_check(double temp) {
    if(temp < -169.528) {
        return false;
    } else {
        return true;
    }
}