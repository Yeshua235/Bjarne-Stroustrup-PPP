#include <iostream>

int main() {

    // std::string name; //declaration
    //get input from user including whitespace util a newline character is encountered, unlike cin that stops only at whitespaces
    // std::getline(std::cin, name);

    using namespace std;
    cout << "Please enter your first name and then your age(followed by 'enter'):\n";
    string first_name;
    double age;
    cin >> first_name >> age;
    cout << "Hello, " + first_name + "! You are " << age << " years old.\n";
    cout << "Perhaps we should say " << age*12 << " months old.\n";

    return 0;
}
