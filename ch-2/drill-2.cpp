#include <iostream>

int main() {
    std::string first_name, friend_name;
    int age{};

    std::cout << "Enter the name and age of the person you want to write to: \n";
    std::cin >> first_name >> age;

    while (age <= 0 || age >= 110) {
        std::cout << "You're kidding!\n" << "Enter the age of the person you want to write to: \n";;
        std::cin >> age;
    }

    std::cout << "Enter the name of another friend: \n";
    std::cin >> friend_name;

    std::cout << "\n\nDear " << first_name << ",\n"
                << "\tHow are you? I am fine. I miss you. I miss your smile and dimples, your glowing face and sweet voice.\n"
                << "Moreover, not only do i miss you, but i also look forward to when we willl meet again. I love you dearly!\n"
                << "Have you seen " << friend_name << " lately?\n"
                << "I heard you just had a birthday and you are " << age << " years old.";

    if (age < 12) {
        std::cout << " Next year you'll be " << age + 1 << '.';
    } else if (age == 17) {
        std::cout << " Next year you'll be able to vote.";
    } else if (age > 70) {
        std::cout << " Are you retired?";
    }

    std::cout << "\n\nYours Sincerely,\n\n" << "Joshua King.\n";
}
