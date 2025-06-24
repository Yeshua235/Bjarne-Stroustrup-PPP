#include <iostream>
#include <stdexcept>
#include <vector>
#include <cctype>

constexpr char number_kind = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr std::string prompt = "> ";
constexpr std::string result = "Ans = ";

const char variable = 'a'; //name token
const char let = 'L'; //declaration token
const std::string declkey = "let"; //declaration key word

class Variable {
    public:
        std::string name;
        double value;

        Variable(): name{}, value{} {};
        Variable(std::string var): name{var}, value{} {};
        Variable(std::string var, double val): name{var}, value{val} {};
};

class Token {
    public:
        char kind;
        double value;
        std::string name;

        Token(): kind{'0'} {}; //added a default constructor
        Token(char ch): kind{ch} {}; //construct for one value
        Token(char ch, double val): kind{ch}, value{val} {}; //construct for two values
        Token(char ch, std::string n): kind{ch}, name{n} {};
};

class Token_stream {
    public:
        Token get();
        void putback(Token t);
        void ignore(char c);
    private:
        bool full = false;
        Token buffer;
};

void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full =  false;
        return;
    }
    full = false;
    char ch;
    while(std::cin >> ch) {
        if (ch == c) return;
    }
}

void Token_stream::putback(Token t) {
    if (full) throw std::runtime_error("you cannot putback() into a full buffer.");
    buffer = t;
    full = true;
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }

    char ch = 0;
    if (!(std::cin >> ch)) throw std::runtime_error("Error reading input.");

    switch (ch) {
        case print:
        case quit:
        case '(':
        case ')':
        case '{':
        case '}':
        case '+':
        case '-':
        case '*':
        case '/':
        case '!':
        case '%':
        case '=':
        case ',': // for seperating variable declarations
            return Token(ch); // let each character represent itself

        case '.': // a floating point literal can start with a decimal point
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                std::cin.putback(ch);
                double val = 0;
                std::cin >> val;
                return Token(number_kind, val);
            }
        default:
            if (std::isalpha(ch)) {
                std::string s;
                s += ch;
                while (std::cin.get(ch) && (std::isalpha(ch) || std::isdigit(ch))) s += ch;
                std::cin.putback(ch);
                if (s == declkey) return Token(let);
                return Token(variable, s);
            }
            throw std::runtime_error("Bad token");
    }
}

Token_stream ts;
std::vector<Variable> var_table;

double expression();    //so that primary() can call expression
double statement();   //so that primary can call declaration

int factorial(int num){
    if (num < 0) throw std::runtime_error("The Factorial function is not defined for negative numbers.");
    if (num == 0) return 1; else return num *= factorial(num - 1);
}

double fmod(double a, double b){
    if (b==0) throw std::runtime_error("Math Error %: division by zero");
    if (a < b) return a; else return (a-b)*int(a/b);
}

void error_recovery() {
    ts.ignore(print);
}

bool is_declared(std::string var) {
    for (const Variable& v : var_table) {
        if (v.name == var) return true;
    }
    return false;
}

double define_name(std::string var, double val) {
    if (is_declared(var)) throw std::runtime_error("duplicate declarion of variable");
    var_table.push_back(Variable(var, val));
    return val;
}

double get_variable_value(std::string var) {
    for (const Variable& v : var_table){
        if (v.name == var) return v.value;
    }
    throw std::runtime_error("undefined variable identified");
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

        case ',':
            return statement();

        case number_kind:
            return t.value;

        case variable:
            return get_variable_value(t.name);

        case '-':
            return -primary();

        case '+':
            return +primary();

        default:
            throw std::runtime_error("A Primary is expected.");
    }
}

double secondary() {
    double left = primary();
    Token t = ts.get();

    switch (t.kind) {
        case '!': {
            int d = left;
            int val = factorial(d); // defined above
            left = val;
            return left;
        }

        default:
            ts.putback(t);
            return left;
    }
}

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
                if (d==0) throw std::runtime_error("Math Error: division by zero");
                left /= d;
                t = ts.get();
                break;
            }

            case '%': {
                double d = secondary();
                left = fmod(left, d); // floating-point module defined above
                t = ts.get();
                break;
            }

            default:
                ts.putback(t);
                return left;
        }
    }
}

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
}

double declaration() {
    Token t = ts.get();
    if (t.kind != variable) throw std::runtime_error("name expected in variable declaration.");

    Token t2 = ts.get();
    if (t2.kind != '=') throw std::runtime_error("'=' missing in declaration of variable");

    double d = expression();
    define_name(t.name, d); // define_name is defined above
    return d;
}

double statement() {
    Token t = ts.get();

    switch (t.kind) {
        case let:
            return declaration();

        default:
            ts.putback(t);
            return expression();
    }
}

void calculate() {
    double calc = 0;

    while (std::cin) {
        try {
            std::cout << prompt;
            Token t = ts.get();

            if(t.kind == quit) break;

            if (t.kind == print) {
                std::cout << result << calc << '\n';
            } else {
                ts.putback(t);
                calc = statement();
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            error_recovery();
        }
    }
}

int main() {
    std::cout << "Welcome to our simple calculator.\nYou are free to enter expressions using floating-point numbers.\nThe calculator supports the following arithmetic operations:\nAddition(+), Subtraction(-), Division(/), multiplication(*), factorial(!) and modulus(%).\nNote that the use of the factorial function for non-integer value results in the truncation of the numbers after the decimal point.\nEnter (;) to end an expression and enter (q) to quit the application.\n";

    try {
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);

        calculate();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "An error occured." << '\n';
        return 2;
    }
};


/*
## BUGS

*/