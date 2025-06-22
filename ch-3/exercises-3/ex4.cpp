#include <iostream>
#include <vector>

int main(){
    std::vector<double> distances;
    double max{}, min{}, mean{}, total{0};

    for(double distance; std::cin>>distance;){
        distances.push_back(distance);
    }

    if (distances.size() != 0){
        min = distances[0];
        max = distances[0];
        for(double distance : distances){
            if (distance > max) max = distance;
            if (distance < min) min = distance;
            total += distance;
        }
        mean = total/(distances.size());

        std::cout << "total distance = " << total << '\n'
                    << "smallest distance = " << min << '\n'
                    << "greatest distance = " << max << '\n'
                    << "mean distance = " << mean << '\n';
    } else {
        std::cout << "you did not input any distance.\n";
    }
    return 0;
}
