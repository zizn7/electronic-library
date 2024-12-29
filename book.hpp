#ifndef BOOK_HPP
#define BOOK_HPP
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
        std::time_t t = time(0);   // Get current time in time_t format
        struct tm now;              // Define a tm structure to store local time
        errno_t err = localtime_s(&now, &t);  // Use localtime_s with correct argument types

        if (err == 0) {  // Check if there was no error
            d.day = now.tm_mday;
            d.month = now.tm_mon + 1;  // tm_mon is 0-based, so add 1
            d.year = now.tm_year + 1900;  // tm_year is years since 1900
        }
        return d;
    }


class Book {
public:
    Book(const std::string& name, const std::string& author, const std::string& isbn, bool status=false, Date due_date = { 0, 0, 0 });

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