#include <iostream>
#include <complex>

bool check_real_root(double, double, double);

int main(){
    double a, b, c, x1, x2;
    std::cout << "what the coefficient of x^2: ";
    std::cin >> a;
    std::cout << "what is the coefficient of x: ";
    std::cin >> b;
    std::cout << "what is the constant: ";
    std::cin >> c;

    if(check_real_root(a, b, c)) {
        x1 = (-b - (pow((pow(b,2) - 4.0*a*c), 0.5)))/2.0*a;
        x2 = (-b + (pow((pow(b,2) - 4.0*a*c), 0.5)))/2.0*a;
        std::cout << "x1 = " << x1 << "\nx2 = " << x2 << "\n";
    } else {
        std::complex<double> ai = a, bi = b, ci = c, cx1, cx2;
        std::cout << "The equation has no real roots.\nThe complex roots are: \n";
        cx1 = (-bi - (pow((pow(bi,2) - 4.0*ai*ci), 0.5)))/2.0*ai;
        cx2 = (-bi + (pow((pow(bi,2) - 4.0*ai*ci), 0.5)))/2.0*ai;
        std::cout << "x1 = " << cx1 << "\nx2 = " << cx2 << "\n";
    }

    return 0;
}

bool check_real_root(double a, double b, double c) {
    if ((pow(b,2) - 4*a*c) > 0){
        return true;
    } else {
        return false;
    }
}
