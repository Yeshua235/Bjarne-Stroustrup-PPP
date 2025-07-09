#include <iostream>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cmath>

std::string intro = "Welcome to our simple calculator.\nThe calculator supports the following arithmetic operations:\nAddition(+), Subtraction(-), Division(/), multiplication(*), factorial(!), modulus(%) square root (sqrt()) and exponentiation(^).\nYou can also make use of named variables and predefined constants.\nFor addition  technical information enter (h), enter (;) to end an expression and enter (q) to quit the application.\n";

std::string help_text = "USING NAMED VARIABLES.\n1. You can define variables using the keyword 'let', followed by a space and then the name of the variable, and an equality sign (=) followed by the value you wish to assign to the variable.\n2. You can assign a integer, floating-point literal or an expression (in parentheses) to a variable.\n3. Variable definitions are to be seperated by a comma, and a semi-colon (;) is to print the result of the expression that has been entered.\n4. Enter ('l') to see a list of all the variables in memory.\nRESERVED KEYWORDS\n1. Based on the use of the letters (q, h and l) as command keywords, they cannot be used as the name of a variable.\nADDITIONAL INFO\n1. Note that the use of the factorial function for non-integer value results in the truncation of the numbers after the decimal point.\n2. Taking square root of negative numbers is prohibited.\n";

constexpr char number_kind = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char help = 'h';
constexpr char variable_list = 'l';
constexpr std::string prompt = "> ";
constexpr std::string result = "Ans = ";

const char variable = 'a'; //name token
const char let = 'L'; //declaration token
const char square_root = 's';   //sqrt token
const char power = 'p'; //pow token
const std::string declkey = "let"; //declaration key word
const std::string sqrt_key = "sqrt";    //key word for square root operation

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
        case '(':
        case ')':
        case '{':
        case '}':
        case '+':
        case '-':
        case '^':
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
                if (s == sqrt_key) return Token(square_root);
                if (s == "l") return Token(variable_list);
                if (s == "h") return Token(help);
                if (s == "q") return Token(quit);
                return Token(variable, s);
            }
            throw std::runtime_error("Bad token");
    }
}

class Symbol_table {
    private:
        std::vector<Variable> var_table;
    public:
        bool is_declared(std::string var);
        double declare (std::string var, double val);
        double get (std::string var);
        void var_list();
        void set(std::string var, double val);
};

Token_stream ts;
Symbol_table variable_table;

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

void Symbol_table::set(std::string var, double val) {
    var_table.emplace_back(var, val);
}

bool Symbol_table::is_declared(std::string var) {
    for (const Variable& v : var_table) {
        if (v.name == var) return true;
    }
    return false;
}

double Symbol_table::declare(std::string var, double val) {
    if (variable_table.is_declared(var)) throw std::runtime_error("duplicate declarion of variable");
    set(var, val);
    return val;
}

double Symbol_table::get(std::string var) {
    for (const Variable& v : var_table){
        if (v.name == var) return v.value;
    }
    throw std::runtime_error("undefined variable identified");
}

void Symbol_table::var_list() {
    for (const Variable& v : var_table) {
        std::cout << v.name << " = " << v.value << '\n';
    }
}

double get_square_root(double num) {
    if (num < 0) throw std::runtime_error("attempting to get square root of a negative number: Not Allowed");
    return std::sqrt(num);
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

        case square_root: {
            double d = expression();
            return get_square_root(d);
        }

        case ',':
            return statement();

        case number_kind:
            return t.value;

        case variable:
            std::cout << t.name << '\n';
            return variable_table.get(t.name);

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

double tertiary() {
    double left = secondary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '^':
                left = std::pow(left, secondary());
                t = ts.get();
                break;

            default:
                ts.putback(t);
                return left;
        }
    }
}

double term(){
    double left = tertiary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '*':
                left *= tertiary();
                t = ts.get();
                break;

            case '/': {
                double d = tertiary();
                if (d==0) throw std::runtime_error("Math Error: division by zero");
                left /= d;
                t = ts.get();
                break;
            }

            case '%': {
                double d = tertiary();
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
    variable_table.declare(t.name, d);
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

            if(t.kind == help) {
                std::cout << help_text << '\n';
                continue;
            }

            if(t.kind == variable_list) {
                variable_table.var_list();
                continue;
            }

            if (t.kind == print) {
                std::cout << result << calc << '\n';
                continue;
            }

            ts.putback(t);
            calc = statement();

        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            error_recovery();
        }
    }
}

int main() {
    std::cout << intro;

    try {
        variable_table.declare("pi", 3.1415926535);
        variable_table.declare("e", 2.7182818284);

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
ADDED FEATURE (exercise 4)

1. Ability of the user to see a list of all the variables together with their values that are available in memory
*/
