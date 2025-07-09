module;

#include <iostream>
#include <vector>

export module date;

export enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

std::vector<std::string> month_tbl{"Not a Month", "January", "February", "March", "April", "May", "June", "July", "August", "Septempber", "October", "November", "December"};

export int to_int(Month m) {
    return static_cast<int>(m);
}

export std::ostream& operator<<(std::ostream& os, Month m) {
    return os << month_tbl[to_int(m)];
}

export struct Year {
    int year;
};

export std::ostream& operator<<(std::ostream& os, Year y) {
    return os << y.year;
}

export bool operator==(Year& y1, Year& y2) {
    return y1.year == y2.year;
}

export Year operator+(Year& y1, Year& y2) {
    return Year{y1.year + y2.year};
}

export Year operator-(Year& y1, Year& y2) {
    return Year{y1.year - y2.year};
}


export class Date {
    public:
        // constructors
        Date() {}
        Date(Year yy): y{yy} {}
        Date(int yy): y{Year{yy}} {}

        Date(Year yy, Month mm): y{yy}, m{mm} {}
        Date(Year yy, int mm): y{yy}, m{Month{mm}} {}
        Date(int yy, Month mm): y{Year{yy}}, m{mm} {}
        Date(int yy, int mm): y{Year{yy}}, m{Month{mm}} {}

        Date(Year yy, Month mm, int dd): y{yy}, m{mm}, d{dd} {}
        Date(Year yy, int mm, int dd): y{yy}, m{Month{mm}}, d{dd} {}
        Date(int yy, Month mm, int dd): y{Year{yy}}, m{mm}, d{dd} {}
        Date(int yy, int mm, int dd): y{Year{yy}}, m{Month{mm}}, d{dd} {}

        int day() const;
        Month month() const;
        Year year() const;
        bool is_valid() const;

        void add_day(int);
        void add_month(int);
        void add_year(int);


    private:
        Year y = Year{2001};
        Month m = Month::jan;
        int d = 1;
};


// non-modifying member functions
export int Date::day() const {
    return d;
}

export Month Date::month() const {
    return m;
}

export Year Date::year() const {
    return y;
}

export bool Date::is_valid() const {
    return (!(to_int(m) < 0 || to_int(m) > 12 || d < 0 || d > 30 || y.year < 1)) ? true : false;
}

// modifying member functions
export void Date::add_day(int num) {
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

export void Date::add_month(int num) {
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

export void Date::add_year(int num) {
    if(!is_valid()) throw std::runtime_error("can't operate on an invalid date");
    Year y_to_add = Year{num};
    y = y + y_to_add;
    return;
}

/*
NOTE

1. Each month is taken to be exactly 30 days.
2. Leap year is not taken into consideration.
3. Each year is exactly 12 months

*/