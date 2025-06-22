#include <iostream>
#include <vector>

class place_value {
    public:
        std::string place;
        int value;

        place_value(std::string position, char size): place{position}, value(size - '0') {};
};

std::vector<place_value> input_list;
std::vector<char> input_buffer;
std::vector<std::string>pos{"thousands", "hundreds", "tens", "ones"};

int main() {

    std::cout << "Input a 'not more then' four digit integer and end it with ';' below:\n";

    for (char num; std::cin >> num;) {
        if (num != ';') input_buffer.push_back(num); else break;
    }

    if (input_buffer.size() < 5 ) {
        int j = 3;
        for (std::vector<char>::size_type i = input_buffer.size(); i > 0; --i) {
            input_list.emplace_back(pos[j], input_buffer[i-1]);
            --j;
        }

        for (place_value item : input_list) {
            std::cout << item.value << ' ' << item.place << '\n';
        }
    } else {
        std::cout << "Your input is more then 4 digit long.\n";
    }
}
