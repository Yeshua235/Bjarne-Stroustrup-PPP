#include "foo2.h"
#include <iostream>

int foo = 0;

void print_foo() {
    std::cout << "foo2 prints ...\n" << foo << std::endl;
}

void set_foo(int x) {
    foo = x;
}

void print(int x) {
    std::cout << "print from foo2: " << x << std::endl;
}
