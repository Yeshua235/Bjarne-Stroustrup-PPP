#include <iostream>
#include <cmath>

int max{}, min{1}, mid{}, stopping_point{}, game_range{};
char answer{};
char ask(int value);
int mid_calc(int, int);

int main(){

    std::cout << "Welcome to my quessing game.\n"
                << "You can answer me by typing either y or n, for yes and no respectively.\n"
                << "You will choose any natural number between 1 and any stopping point you want and by asking you few questions, i will correctly determine the number you guessed.\n"
                << "Type any integer greater than 1 below, as the stopping point of your game session: \n";

    std::cin >> stopping_point;
    game_range = int(std::log(stopping_point)/std::log(2));

    std::cout << "I will only ask you " << game_range << " questions to correctly determine your chosen number\n\n";
    max = stopping_point;
    mid = mid_calc(max, min);

    for(int i=0; i<game_range; ++i) {
        answer = ask(mid);
        if(answer == 'y'){
            min = mid + 1;
            mid = mid_calc(max, min);
        } else {
            max = mid;
            mid = mid_calc(max, min);
        }
    }
    std::cout<<"The number is " << mid << '\n';

}

char ask(int value){
    std::cout << "is the number greater than " << value << '\n';
    char ans{};
    std::cin >> ans;
    return ans;
}

int mid_calc(int max, int min){
    mid = (max + min)/2;
    return mid;
}
