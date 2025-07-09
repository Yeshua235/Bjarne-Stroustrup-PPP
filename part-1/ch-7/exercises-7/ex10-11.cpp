#include <iostream>
#include <vector>
#include <algorithm>

struct Vector_stats {
    double smallest{0};
    double largest{0};
    double mean{0};
    double median{0};
};

double median_func(std::vector<double>& vec) {
    if (vec.size() == 0) throw std::runtime_error("you passed an empty vector to median.");

    std::ranges::sort(vec);
    double median{0};

    if (vec.size()%2 == 0) {
        int half = vec.size()/2;
        double sum = vec[half] + vec[half - 1];
        median = sum/2;
    } else {
        int mid_point = (vec.size()/2) + (vec.size()%2);
        median = vec[mid_point-1];
    }
    return median;
}

double mean_func(const std::vector<double>& vec) {
    if (vec.size() == 0) throw std::runtime_error("you passed an empty vector to median.");

    double sum{0}, mean{0};
    for (double num : vec) {
        sum += num;
    }
    mean = sum/vec.size();
    return mean;
}

std::pair<double, double> largest_and_smallest(std::vector<double>& vec){
    if (vec.size() == 0) throw std::runtime_error("you passed an empty vector to median.");
    std::ranges::sort(vec);

    double largest = vec[vec.size() - 1];
    double smallest = vec[0];

    return std::make_pair(largest, smallest);
}


int main() {
    std::vector<double> my_vec = {40, 5.5, 6, 8.8, 9, 10, 12, 73, 61};

    Vector_stats my_vec_stats;
    double largest{0}, smallest{0};

    std::tie(largest, smallest) = largest_and_smallest(my_vec);

    my_vec_stats.mean = mean_func(my_vec);
    my_vec_stats.median = median_func(my_vec);
    my_vec_stats.largest = largest;
    my_vec_stats.smallest = smallest;

    std::cout << "mean = " << my_vec_stats.mean << '\n'
                << "median = " << my_vec_stats.median << '\n'
                << "largest element = " << my_vec_stats.largest << '\n'
                << "smallest element = " << my_vec_stats.smallest << std::endl;
    return 0;
}
