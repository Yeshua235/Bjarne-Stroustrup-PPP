#include <iostream>
#include <cmath>

int check_minimum_grains(int);
double total_max_squares();

constexpr int square = 64;
int thousand{}, million{}, billion{}, num_rubbish{};
int total_grains_int{};
double total_grains_double{}, total{};

int main(){
    thousand = check_minimum_grains(1000);
    million = check_minimum_grains(1000000);
    billion = check_minimum_grains(1000000000);
    num_rubbish = check_minimum_grains(2099999999);
    total = total_max_squares();

    std::cout   << "1,000 grains = " << thousand << "squares\n"
                << "1,000,000 grains = " << million << "squares\n"
                << "1,000,000,000 grains = " << billion << "squares\n"
                << "total number of squares for double = " << total << "squares\n"
                << "maximum squares for calculating numbeer of grains for int: " << num_rubbish << '\n';

    for (int i=0; i<square; ++i){
        total_grains_int += std::pow(2,i);
        total_grains_double += std::pow(2,i);
    }
    std::cout << "total number of grains in int = " << total_grains_int << '\n';
    std::cout << "total number of grains in double = " << total_grains_double << '\n';
    return 0;
}

int check_minimum_grains(int value){
    int index{}, grains{};
    for (int i=0; i<square; ++i){
        grains += std::pow(2,i);
        if(grains >= value){
            index = i + 1;
            break;
        }
    }
    return index;
}

double total_max_squares(){
    double index{}, grains{};
    for (int i=0; i<square; ++i){
        grains += std::pow(2,i);
        if(grains >= 1.84467e+19){
            index = i + 1;
            break;
        }
    }
    return index;
}
