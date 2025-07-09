#include <iostream>
#include <cctype>
#include <cstdlib>

class Rational {
    public:
        Rational(int num) : numerator{num}, denominator{1} {}
        Rational(int num, int denom) : numerator{num}, denominator{denom} {
            if(denom == 0) throw std::runtime_error("Math Error: Division by zero");
            if(denom < 0) {
                denominator = std::abs(denom);
                numerator = 0-num;
            }
        }

        double to_double();

        int get_numerator() const {return numerator;}
        int get_denominator() const {return denominator;}
    private:
        int numerator;
        int denominator;
};

double Rational::to_double() {
    double num = static_cast<double>(numerator);
    double denom = static_cast<double>(denominator);
    return num/denom;
}

std::pair<int, int> add_rational(Rational num1, Rational num2) {
    int new_denominator = num1.get_denominator()*num2.get_denominator();
    int new_numerator = num1.get_numerator()*num2.get_denominator() + num2.get_numerator()*num1.get_denominator();
    return std::make_pair(new_numerator, new_denominator);
}

std::pair<int, int> subtract_rational(Rational num1, Rational num2) {
    int new_denominator = num1.get_denominator()*num2.get_denominator();
    int new_numerator = num1.get_numerator()*num2.get_denominator() - num2.get_numerator()*num1.get_denominator();
    return std::make_pair(new_numerator, new_denominator);
}

std::pair<int, int> muliply_rational(Rational num1, Rational num2) {
    int new_denominator = num1.get_denominator()*num2.get_denominator();
    int new_numerator = num1.get_numerator()*num2.get_numerator();
    return std::make_pair(new_numerator, new_denominator);
}

std::pair<int, int> divide_rational(Rational num1, Rational num2) {
    int new_denominator = num1.get_denominator()*num2.get_numerator();
    int new_numerator = num1.get_numerator()*num2.get_denominator();
    return std::make_pair(new_numerator, new_denominator);

}

Rational operator+(const Rational& num1, const Rational& num2) {
    int numerator, denominator;
    std::tie(numerator, denominator) =  add_rational(num1, num2);
    return Rational(numerator, denominator);
}

Rational operator-(const Rational& num1, const Rational& num2) {
    int numerator, denominator;
    std::tie(numerator, denominator) =  subtract_rational(num1, num2);
    return Rational(numerator, denominator);
}

Rational operator*(const Rational& num1, const Rational& num2) {
    int numerator, denominator;
    std::tie(numerator, denominator) =  muliply_rational(num1, num2);
    return Rational(numerator, denominator);
}

Rational operator/(const Rational& num1, const Rational& num2) {
    int numerator, denominator;
    std::tie(numerator, denominator) =  divide_rational(num1, num2);
    return Rational(numerator, denominator);
}

bool operator==(Rational& num1, Rational& num2) {
    return (num1.to_double() == num2.to_double());
}

std::ostream& operator<<(std::ostream& os, const Rational& num) {
    return os << num.get_numerator() << '/' << num.get_denominator() << " ";
}

int main() {
    try{
        Rational number1{21, 17};
        Rational number2{12, -13};

        Rational number3{4, 2};
        Rational number4{2};

        std::cout << "first number: " << number1 << "second number: " << number2
                    << "\nAddition : " << number1+number2 << '\n'
                    << "Subtraction: " << number1-number2 << '\n'
                    << "Multiplication: " << number1*number2 << '\n'
                    << "Division: " << number1/number2 << '\n'
                    << "first number: " << number1.to_double() << '\n'
                    << "second number: " << number2.to_double() << '\n';

        if(number3==number4) {
            std::cout << number3 << "is equal to " << number4 << std::endl;
        } else {
            std::cout << number3 << "is not equal to " << number4 << std::endl;
        }

        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Oops! An unknown error occured." << std::endl;
    }
}

