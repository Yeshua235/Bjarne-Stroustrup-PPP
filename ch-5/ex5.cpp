#include <iostream>
#include <stdexcept>

class Token {
    public:
        char kind;
        int value;

        Token(): kind{'0'}, value{0} {};
        Token(char k): kind{k}, value{0} {};
        Token(char k, int v): kind{k}, value{v} {};
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
        case '=':    //to print result of bitwise calculation
        case 'q':    //for quit
        case '(': case ')': case '{': case '}': case '&': case '^': case '|': case '~': case '!':
            return Token(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                std::cin.putback(ch);
                int val = 0;
                std::cin >> val;
                return Token('8', val);
            }
        default:
            throw std::runtime_error("Bad token");
    }
};

Token_stream ts;

int expression();    //declaration so that primary() can call expression

int primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '{': {
            int d = expression();
            t = ts.get();
            if (t.kind != '}') throw std::runtime_error("'}' is expected.");
            return d;
        }

        case '(': {
            int d = expression();
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

int tertiary() {
    int left = primary();
    Token t = ts.get();

    switch (t.kind) {
        case '!':
            return !left;

        case '~':
            return ~left;

        default:
            ts.putback(t);
            return left;
    }
};

int secondary(){
    int left = tertiary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '&':
                left &= secondary();
                t = ts.get();
                break;

            default:
                ts.putback(t);
                return left;
        }
    }
};

int term(){
    int left = secondary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '^':
                left ^= secondary();
                t = ts.get();
                break;

            default:
                ts.putback(t);
                return left;
        }
    }
};

int expression() {
    int left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '|':
                left |= term();
                t = ts.get();
                break;

            default:
                ts.putback(t);
                return left;
        }
    }
};

int main() {
    std::cout << "Welcome to our simple bitwise calculator.\nAll operations are defined only for integers.\nThe calculator supports the following bitwise operations:\nAND(&), XOR(^), OR(|), NOT(!) and COMPLEMENT(~).\nEnter (=) to end an expression and enter (q) to quit the application.\n";

    try {
        int calc = 0;

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
