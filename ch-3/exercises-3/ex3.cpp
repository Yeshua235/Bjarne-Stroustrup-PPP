#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<double> temps;
    double median_temp;

    for(double temp; std::cin>>temp;){
        temps.push_back(temp);
    }

    std::ranges::sort(temps);
    
    if (temps.size() != 0){
        int mid_point = temps.size()/2;

        if(mid_point%2 == 0){
            double sum = temps[mid_point] + temps[mid_point - 1];
            median_temp = sum/2;
        } else {
            median_temp = temps[mid_point];
        }
        std::cout << "Median Temperature: " << median_temp << '\n';
    } else {
        std::cout << "YOu did not input any temperature.\n";
    }
    return 0;
}
