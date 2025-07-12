#include <iostream>
#include <fstream>
#include <iomanip>
#include <format>
#include <vector>

struct Person {
    std::string lastname;
    std::string firstname;
    std::string telephone;
    std::string email;
};

struct Point {
    int x;
    int y;
};

bool operator==(const Point& p1, const Point& p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y));
}

bool operator!=(const Point& p1, const Point& p2) {
    return (!((p1.x == p2.x) && (p1.y == p2.y)));
}

std::ostream& operator<<(std::ostream& os, Point& p) {
    return os << '(' << p.x << ',' << p.y << ')';
}

std::istream& operator>>(std::istream& is, Point& p) {
    int x_point{0}, y_point{0};
    char ch1, ch2, ch3;
    is >> ch1 >> x_point >> ch2 >> y_point >> ch3;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
        is.clear(std::ios::failbit);
        return is;
    }
    p.x = x_point;
    p.y = y_point;
    return is;
}


int main() {
    /*
    * Drill 1 to 9
    */

    int birth_year = 2000;
    double age = 25;
    std::cout << std::format("representation\tbirth_year\nDecimal:\t{:d}\nHexadecimal:\t{:x}\nOctal:\t\t{:o}\n\nAge:\t\t{:f}\n", birth_year, birth_year, birth_year, age) << '\n';

    int a{1234}, b{1234}, c{1234}, d{1234};
    //std::cout << "Enter four numbers to be interpreted as decimal, octal, hexadecimal and hexadecimal numbers repectively:\n";
    //std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
    std::cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    /*
    * Drill 10
    */

    Person king = Person{"King", "Joshua", "+234 810 930 3116", "joshuaking12357@gmail.com"};
    Person josh = Person{"Ayanlowo", "Joshua", "+234 907 326 4473", "joshuaayanlowo235@gmail.com"};
    Person dev = Person{"Tech", "Dev", "Nil", "dev.tech7wqz@gmail.com"};
    Person jane = Person{"Doe", "Jane", "+1 923 476 934", "Nil"};
    Person emily =  Person{"Holmes", "Emily", "Nil", "Nil"};

    std::vector<Person> people{king, josh, dev, jane, emily};

    std::cout << std::setw(10) << "Firstname" << std::setw(12) << "Lastname" << std::setw(20) << "Telephone" << std::setw(30) << "Email" << '\n';

    for (Person man : people) {
        std::cout << std::setw(10) << man.firstname << std::setw(12) << man.lastname << std::setw(20) << man.telephone << std::setw(30) << man.email << '\n';
    }
    std::cout << '\n';

    /*
    * Drill 11 to 13
    */
    std::cout << "\n*****************************************\n\n";
    std::cout << "Enter seven point pairs (x,y) below: \n";

    std::vector<Point> original_points{};
    //for (Point points; std::cin >> points;) {
    //    original_points.push_back(points);
    //}

    std::ifstream ist{"my_inputs.txt"};
    if (!ist) {
        std::cout << "can't open input file.\n";
        return 1;
    }
    for (Point input_points; ist>>input_points;) {
        original_points.push_back(input_points);
    }
    ist.close();
    ist.clear();

    std::cout << "Points entered are:\n";
    for (Point points : original_points) {std::cout << points << '\t';}
    std::cout << '\n';

    /*
    * Drill 14
    */

    std::ofstream ost{"mydata.txt"};
    if (!ost) {
        std::cout << "can't open output file.\n";
        return 1;
    }

    std::cout << "reading points into file...\n";
    for (Point points : original_points) {
        ost << points << '\n';
    }
    ost.close();
    ost.clear();

    ist.open("mydata.txt");
    if (!ist) {
        std::cout << "can't open input file.\n";
        return 1;
    }

    Point points_from_file;
    std::vector<Point> processed_points{};
    while(ist >> points_from_file) {
        processed_points.push_back(points_from_file);
    }
    ist.close();

    std::cout << "reading points from file...\n";
    for (Point points : processed_points) {
        std::cout << points << '\n';
    }

    if (original_points.size() != processed_points.size()) std::cout << "something went wrong with the I/O operation\nReport different vector sizes\n";

    for (std::vector<Point>::size_type i = 0; i < original_points.size(); ++i) {
        if (processed_points[i] != original_points[i]) std::cout << "something went wrong with the I/O operation\nReporting missing or misplaced vector elements\n";
    }

    return 0;
}
