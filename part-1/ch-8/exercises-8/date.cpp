#include <iostream>
#include <vector>
#include "date.h"

std::vector<std::string> month_tbl{"Not a Month", "January", "February", "March", "April", "May", "June", "July", "August", "Septempber", "October", "November", "December"};

int to_int(Month m) {
    return static_cast<int>(m);
}

std::ostream& operator<<(std::ostream& os, Month m) {
    return os << month_tbl[to_int(m)];
}

std::ostream& operator<<(std::ostream& os, Year y) {
    return os << y.year;
}

bool operator==(Year& y1, Year& y2) {
    return y1.year == y2.year;
}

Year operator+(Year& y1, Year& y2) {
    return Year{y1.year + y2.year};
}

Year operator-(Year& y1, Year& y2) {
    return Year{y1.year - y2.year};
}

// non-modifying member functions
int Date::day() const {
    return d;
}

Month Date::month() const {
    return m;
}

Year Date::year() const {
    return y;
}

bool Date::is_valid() const {
    return (!(to_int(m) < 0 || to_int(m) > 12 || d < 0 || d > 30 || y.year < 1)) ? true : false;
}

// modifying member functions
void Date::add_day(int num) {
    if(!is_valid()) throw std::runtime_error("can't operate on an invalid date");
    int new_day = d + num;
    if(new_day > 30) {
        add_month(new_day/30);
        d += new_day%30;
        return;
    } else {
        d = new_day;
        return;
    }
}

void Date::add_month(int num) {
    if(!is_valid()) throw std::runtime_error("can't operate on an invalid date");
    int new_month = to_int(m) + num;
    if (new_month > 12) {
        Year y_to_add = Year{new_month/12};
        y = y + y_to_add;
        new_month %= 12;
    }
    m = Month{new_month};
    return;
}

void Date::add_year(int num) {
    if(!is_valid()) throw std::runtime_error("can't operate on an invalid date");
    Year y_to_add = Year{num};
    y = y + y_to_add;
    return;
}

std::ostream& operator<<(std::ostream& os, Date date) {
    return os << '(' << date.year() << '/' << date.month() << '/' << date.day() << ") ";
}

bool is_leapyear(int num) {
    if (num % 4 == 0) return true;
    return false;
}

bool Date::leapyear() {
    if (is_leapyear(y.year)) return true;
    return false;
}

int week_of_year(Date date) {
    int number_of_days = ((to_int(date.month())-1)*30) + date.day();
    return number_of_days/7;
}


/*
NOTE

1. Each month is taken to be exactly 30 days.
2. Leap year is not taken into consideration.
3. Each year is exactly 12 months

*/