#include <iostream>
#include <vector>
#include <cctype>
#include "date.h"

//import date;

class ISBN{
    public:
        std::string serial_number{};

        ISBN() {}
        ISBN(std::string isbn_number): serial_number{isbn_number} {}

        bool is_valid() const;
};

bool ISBN::is_valid() const {
    int token_count{0};
    std::string token{""};
    char stop_char = '-';

    for (char character : serial_number) {
        if (token_count != 3) {
            if (std::isdigit(character)) {
                token += character;
            } else if (character == stop_char) {
                token_count += 1;
                token = "";
            } else {
                return false;
            }
        } else {
            if (std::isalnum(character)) {
                token += character;
            } else {
                return false;
            }
        }

    }
    return true;
}

bool operator==(const ISBN& isbn1, const ISBN& isbn2) {
    return (isbn1.serial_number == isbn2.serial_number);
}

bool operator!=(const ISBN& isbn1, const ISBN& isbn2) {
    return (!(isbn1.serial_number == isbn2.serial_number));
}

std::ostream& operator<<(std::ostream& os, const ISBN& isbn_object) {
    return os << isbn_object.serial_number;
}

enum class Genre {
    fiction=0, nonfiction, programming, spiritual, biography, comic
};

std::vector<std::string> genre_list = {"Fiction", "non-Fiction", "Programming", "Spiritual", "Biography", "Comic"};

std::ostream& operator<<(std::ostream& os, const Genre& genre) {
    return os << genre_list[static_cast<int>(genre)];
}

class Book {
    public:
        Book(ISBN isb_num, std::string _title, std::string _author, Date cp_date)
            : isbn_number{isb_num}, title{_title}, author{_author}, _genre{Genre::fiction}, copyright_date{cp_date} {
                if(!(isb_num.is_valid())) throw std::runtime_error("Invalid ISBN number");
                if(!(cp_date.is_valid())) throw std::runtime_error("Invalid date for the copyright date");
            }

        Book(ISBN isb_num, std::string _title, std::string _author, Genre genre, Date cp_date)
            : isbn_number{isb_num}, title{_title}, author{_author}, _genre{genre}, copyright_date{cp_date} {
                if(!(isb_num.is_valid())) throw std::runtime_error("Invalid ISBN number");
                if(!(cp_date.is_valid())) throw std::runtime_error("Invalid date for the copyright date");
            }

        bool checked_out() const {return ischeck_out;}
        void check_in() {ischeck_out = false;}
        void check_out() {ischeck_out = true;}

        std::string book_title() const {return title;}
        std::string book_author() const {return author;}
        ISBN book_isbn() const {return isbn_number.serial_number;}
        Date copyright() const {return copyright_date;}
        Genre book_genre() const {return _genre;}
    private:
        ISBN isbn_number;
        std::string title;
        std::string author;
        Genre _genre;
        Date copyright_date;
        bool ischeck_out{false};
};

bool operator==(const Book& book1, const Book& book2) {
    return (book1.book_isbn() == book2.book_isbn());
}

bool operator!=(const Book& book1, const Book& book2) {
    return (!(book1.book_isbn() == book2.book_isbn()));
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    return os << " Book Title: " << book.book_title() << '\n'
                << " Book Author: " << book.book_author() << '\n'
                << " Genre: " << book.book_genre() << '\n'
                << " ISBN: " << book.book_isbn() << ' ';
}

class Patron {
    public:
        Patron(std::string username) : _name{username}, _card_number{++num_gen} {}

        void pay_debt(double amount);
        void set_fee(double amount);

        std::string name() const {return _name;}
        unsigned long card_number() const {return _card_number;}
        double fee() const {return _fee;}
        bool debt() const {return _debt;}

    private:
        std::string _name;
        const unsigned long _card_number;
        double _fee{0};
        bool _debt{false};

        static unsigned long num_gen;
};

unsigned long Patron::num_gen = 0;

bool operator==(const Patron& patron1, const Patron& patron2) {
    return (patron1.name() == patron2.name());
}

bool operator!=(const Patron& patron1, const Patron& patron2) {
    return (!(patron1.name() == patron2.name()));
}

std::ostream& operator<<(std::ostream& os, const Patron& library_customer) {
    return os << " Patron name: " << library_customer.name() << '\n'
                << " Patron card number: " << library_customer.card_number() << '\n'
                << " Library fee owed: $" << library_customer.fee() << ' ';
}

void Patron::pay_debt(double amount) {
    if (amount > _fee) throw std::runtime_error("Error: You are not allowed to pay more than you owe");
    _fee -= amount;
    if (_fee == 0) _debt=false;
}

void Patron::set_fee(double amount) {
    _fee = amount;
    _debt = true;
}

struct Transaction{
    public:
        Transaction(Book book, Patron customer, Date date) :
        _book{book}, _customer{customer}, _date{date}, _transaction_id{++transaction_id_num} {
            if (!(_date.is_valid())) throw std::runtime_error("cannot accept invalid date for transaction");
            if (customer.debt()) throw std::runtime_error("Error: a debtor cannot transact");
        }

        Book book() const {return _book;}
        Patron patron() const {return _customer;}
        Date date() const {return _date;}
        unsigned long transaction_id() const {return _transaction_id;}

    private:
        Book _book;
        Patron _customer;
        Date _date;
        unsigned long _transaction_id;

        static unsigned long transaction_id_num;
};

unsigned long Transaction::transaction_id_num = 0;

std::ostream& operator<<(std::ostream& os, const Transaction& transact) {
    return os << " Transaction_ID: " << transact.transaction_id() << '\n'
                << " Book:\n" << transact.book() << '\n'
                << " Patron:\n" << transact.patron() << '\n'
                << " Date:\n" << transact.date() << '\n' << std::endl;
}

class Library{
    public:
        Library(std::string name) : _library_name{name} {}

        void add_book(const Book& book) {library_book_records.push_back(book);}
        void register_patron(Patron& patron) {library_patron_records.push_back(patron);}

        bool book_in_library(const Book& book) const;
        bool patron_in_library(const Patron& patron) const;
        void library_books() const;
        void library_patrons() const;
        void library_debtors() const;

        std::string library_name() const {return _library_name;}

        void library_transaction_records() const;
        void record_library_transaction(const Transaction& transact);

    private:
        std::string _library_name;
        std::vector<Book> library_book_records{};
        std::vector<Patron> library_patron_records{};
        std::vector<Transaction> _library_transaction_records{};
};

std::ostream& operator<<(std::ostream& os, const Library& library) {
    return os << "Library Name: " << library.library_name() << std::endl;
}

void Library::library_debtors() const {
    std::cout << "List of Patrons that owe the Library: \n";
    int num{1};
    for (Patron pat : library_patron_records) {
        if (pat.debt()) std::cout << num << ". " << pat.name() << '\n';
        ++num;
    }
}

void Library::library_transaction_records() const {
    std::cout << "List of the records of all transactions in the library.\n";
    int num{1};
    for (Transaction transact : _library_transaction_records) {
        std::cout << num << ". " << transact << '\n';
        ++num;
    }
}

void Library::record_library_transaction(const Transaction& transact) {
    if (!(book_in_library(transact.book()))) throw std::runtime_error("Error: book not in the library");
    if (!(patron_in_library(transact.patron()))) throw std::runtime_error("Error: unregistered Patron");

    _library_transaction_records.push_back(transact);
}

void Library::library_books() const {
    std::cout << "List of books that owe the Library: \n";
    int num{1};
    for (Book bk : library_book_records) {
        std::cout << num << '.' << bk << '\n';
        ++num;
    }
}

void Library::library_patrons() const {
    std::cout << "List of Patrons registered in the Library: \n";
    int num{1};
    for (Patron pat : library_patron_records) {
        std::cout << num << '.' << pat << '\n';
        ++num;
    }
}

bool Library::book_in_library(const Book& book) const {
    for (Book bk : library_book_records) {
        if (book == bk) return true;
    }
    return false;
}

bool Library::patron_in_library(const Patron& patron) const {
    for (Patron pat : library_patron_records) {
        if (pat == patron) return true;
    }
    return false;
}

int main() {
    try {
        std::cout << "********* BOOK AND PATRON TESTS ***********\n";
        Book my_book{ISBN{"2356-7853-8934-YHWH"}, "my first book", "Joshua King", Date{2025,6,4}};
        Book second_book{ISBN{"2356-7853-8934-A4DP"}, "OOP in C++", "Joshua King", Genre::programming, Date{2025,6,24}};
        Patron first_customer{"Jane Doe"};
        Patron second_customer{"Peter Parkar"};
        Patron another_customer{"Vanilla"};
        another_customer.set_fee(30);
        first_customer.set_fee(100.00);
        second_customer.set_fee(50.00);
        first_customer.pay_debt(20);
        another_customer.pay_debt(30);

        std::cout << my_book;
        std::cout << first_customer << second_customer << another_customer;

        if(first_customer.debt()) std::cout << first_customer.name() << " is a debtor\n";
        if(second_customer.debt()) std::cout << second_customer.name() << " is a debtor\n";
        if(another_customer.debt()) std::cout << another_customer.name() << " is a debtor\n";

        std::cout << "\n********* ADDITIONAL DATE TESTS ***********\n";
        if (my_book.copyright().leapyear()) {
            std::cout << "copyright date: " << my_book.copyright()  << " is a leap year.\n";
        } else {
            std::cout << "copyright date: " << my_book.copyright()  << " is not a leap year.\n";
        }

        std::cout << "week of year of copyright date: " << week_of_year(my_book.copyright()) << '\n';

        std::cout << "\n********* LIBRARY TESTS ***********\n";

        Library my_library{"King's Library"};
        my_library.add_book(my_book);
        my_library.add_book(second_book);
        my_library.register_patron(first_customer);
        my_library.register_patron(second_customer);
        my_library.register_patron(another_customer);

        std::cout << my_library << '\n';
        my_library.library_books(); std::cout << '\n';
        my_library.library_patrons(); std::cout << '\n';
        my_library.library_debtors(); std::cout << '\n';

        std::cout << "\n********* LIBRARY TRANSACTION TESTS ***********\n";
        //Transaction my_library_transaction1{my_book, first_customer, Date{2025,7,5}};
        //Transaction my_library_transaction2{second_book, second_customer, Date{2025,7,5}};
        Transaction my_library_transaction3{second_book, another_customer, Date{2025,7,5}};
        Transaction my_library_transaction4{my_book, another_customer, Date{2025,7,8}};

        //my_library.record_library_transaction(my_library_transaction1);
        //my_library.record_library_transaction(my_library_transaction2);
        my_library.record_library_transaction(my_library_transaction3);
        my_library.record_library_transaction(my_library_transaction4);

        //std::cout << my_library_transaction1 << std::endl;
        //std::cout << my_library_transaction2 << std::endl;
        std::cout << my_library_transaction3 << std::endl;
        std::cout << my_library_transaction4 << std::endl;
        my_library.library_transaction_records();

        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unknown error occured.\n";
    }
}
