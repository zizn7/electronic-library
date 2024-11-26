﻿﻿#ifndef ELEC_AS_CPP_BOOK
#define ELEC_AS_CPP_BOOK

#include <ctime>
#include <string>

/**
 * \brief Date structure
 *
 */
    struct Date {
    int day, month, year;

    Date(int d = 0, int m = 0, int y =0) : month(m), day(d), year(y){}

    static Date Today() {
        Date d;
        std::time_t t = time(0);
        struct tm* now = localtime(&t);
        d.day = now->tm_mday;
        d.month = now->tm_mon + 1;
        d.year = now->tm_year + 1900;
        return d;
    }
};

class Book {
public:
    Book(const std::string& name, const std::string& author, const std::string& isbn, bool status, Date due_date = { 0, 0, 0 });

         std::string GetName() const;
         std::string GetAuthor() const;
         std::string GetISBN() const;
         bool GetStatus() const;
         Date GetDueDate() const;
         
         bool Loan();
         void Restore();
         void Print() const;
           

private:
    std::string name_;
    std::string author_;
    std::string isbn_;
    bool loaned_;
    Date due_date_;
};

#endif
