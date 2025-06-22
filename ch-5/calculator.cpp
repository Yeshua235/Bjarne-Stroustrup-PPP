#include <iostream>
#include <stdexcept>

class Token {
    public:
        char kind;
        double value;

        Token(): kind('0'), value(0.0) {}; //added a default constructor

        Token(char k): kind{k}, value{0.0} {} //construct for one value
        Token(char k, double v): kind{k}, value{v} {} //construct for two values
};

class Token_stream {
    public:
        Token get();
        void putback(Token t);
    private:
        bool full = false;
        Token buffer;
};

void Token_stream::putback(Token t) {
    if (full) throw std::runtime_error("you cannot putback() into a full buffer.");
    buffer = t;
    full = true;
};

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }

    char ch = 0;
    if (!(std::cin >> ch)) throw std::runtime_error("Error reading input.");

    switch (ch) {
        case '=':    //to print result of calculation
        case 'q':    //for quit
        case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
            return Token(ch);
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                std::cin.putback(ch);
                double val = 0;
                std::cin >> val;
                return Token('8', val);
            }
        default:
            throw std::runtime_error("Bad token");
    }
};

Token_stream ts;

double expression();    //declaration so that primary() can call expression

int factorial(int num){
    if (num < 0) throw std::runtime_error("The Factorial function is not defined for negative numbers.");
    if (num == 0) return 1; else return num *= factorial(num - 1);
}

double primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '{': {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') throw std::runtime_error("'}' is expected.");
            return d;
        }

        case '(': {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') throw std::runtime_error("')' is expected.");
            return d;
        }

        case '8':
            return t.value;
        default:
            throw std::runtime_error("A Primary is expected.");
    }
};

double secondary() {
    double left = primary();
    Token t = ts.get();

    switch (t.kind) {
        case '!': {
            int d = left;
            int val = factorial(d);
            left = val;
            return left;
        }

        default:
            ts.putback(t);
            return left;
    }
};

double term(){
    double left = secondary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '*':
                left *= secondary();
                t = ts.get();
                break;

            case '/': {
                double d = secondary();
                if (d==0) throw std::runtime_error("division by zero");
                left /= d;
                t = ts.get();
                break;
            }

            default:
                ts.putback(t);
                return left;
        }
    }
};

double expression() {
    double left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;

            case '-':
                left -= term();
                t = ts.get();
                break;

            default:
                ts.putback(t);
                return left;
        }
    }
};

int main() {
    std::cout << "Welcome to our simple calculator.\nYou are free to enter expressions using floating-point numbers.\nThe calculator supports the following arithmetic operations:\nAddition(+), Subtraction(-), Division(/), multiplication(*) and factorial(!).\nEnter (=) to end an expression and enter (q) to quit the application.\n";

    try {
        double calc = 0;

        while (std::cin) {
            Token t = ts.get();

            if(t.kind == 'q') break;
            if(t.kind == '=') {
                std::cout << "Answer = " << calc << '\n';
            } else {
                ts.putback(t);
                calc = expression();
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An error occured." << '\n';
        return 2;
    }
    return 0;
};


/*
## BUGS

1. The program doesn't identify negative numbers as a distinct input.
2. Calculation result get lost if inputs are not chained (connected together) by operators
*/