#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>

enum class Month {
    Jan = 1, Feb, Mar, Apr, May, Jun,
    Jul, Aug, Sep, Oct, Nov, Dec
};

struct Year {
    int year;
};

int to_int(Month m);

std::ostream& operator<<(std::ostream& os, Month m);

std::ostream& operator<<(std::ostream& os, Year y);

bool operator==(Year& y1, Year& y2);

Year operator+(Year& y1, Year& y2);

Year operator-(Year& y1, Year& y2);

class Date {
    public:
        // constructors
        Date() {}
        Date(Year yy): y{yy} {}
        Date(int yy): y{Year{yy}} {}

        Date(Year yy, Month mm): y{yy}, m{mm} {}
        Date(Year yy, int mm): y{yy}, m{Month(mm)} {}
        Date(int yy, Month mm): y{Year{yy}}, m{mm} {}
        Date(int yy, int mm): y{Year{yy}}, m{Month(mm)} {}

        Date(Year yy, Month mm, int dd): y{yy}, m{mm}, d{dd} {}
        Date(Year yy, int mm, int dd): y{yy}, m{Month(mm)}, d{dd} {}
        Date(int yy, Month mm, int dd): y{Year{yy}}, m{mm}, d{dd} {}
        Date(int yy, int mm, int dd): y{Year{yy}}, m{Month(mm)}, d{dd} {}

        int day() const;
        Month month() const;
        Year year() const;
        bool is_valid() const;
        bool leapyear();

        void add_day(int);
        void add_month(int);
        void add_year(int);

    private:
        Year y = Year{2001};
        Month m = Month::Jan;
        int d = 1;
};

std::ostream& operator<<(std::ostream& os, Date date);

bool is_leapyear(int num);

int week_of_year(Date date);

#endif // DATE_H