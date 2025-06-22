#include <iostream>

int main() {
    constexpr double yen_to_dol = 0.007, pound_to_dol = 1.332, kroner_to_dol = 0.152;

    double amount{}, new_amount{};
    char unit{' '};
    std::string full_unit, message;
    std::cout << "Enter any amount followed the unit (y for Yen, p for Pounds or k for Kroner): \n";
    std::cin >> amount >> unit;

    if (unit == 'y'){
        new_amount = amount*yen_to_dol;
        full_unit = "Yen";
    } else if (unit == 'p'){
        new_amount = amount*pound_to_dol;
        full_unit = "£";
    } else if (unit == 'k'){
        new_amount = amount*kroner_to_dol;
        full_unit = "kroner";
    } else {
        message = "I don't know such a currency.\n";
    }

    if (message == "") {
        std::cout << amount << full_unit << " == " << '$' << new_amount << '\n';
    } else {
        std::cout << message;
    }
    return 0;
}
