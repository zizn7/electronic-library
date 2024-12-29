#include "book.hpp"

#include <ctime>
#include <iostream>


Book::Book(const std::string& name, const std::string& author, const std::string& isbn, bool status, Date due_date) : name_(name), author_(author), isbn_(isbn), loaned_(status), due_date_(due_date){}

std::string Book::GetName() const
{
	return name_;
}

std::string Book::GetAuthor() const
{
	return author_;
}

std::string Book::GetISBN() const
{
	return isbn_;
}

bool Book::GetStatus() const
{
	return loaned_;
}

Date Book::GetDueDate() const
{
	return due_date_;
}

bool Book::Loan()
{
	if (!loaned_) { // Prefer concise syntax for checking `loaned_`
		loaned_ = true;
		due_date_ = Date::Today();
		due_date_.month += 1;

		if (due_date_.month > 12) {
			due_date_.month -= 12; // Fix subtraction logic
			due_date_.year += 1;
		}
		return true; // The book was successfully loaned
	}

	// If the book is already loaned
	return false;
}


void Book::Restore()
{
	due_date_ = { 0, 0, 0 };
	loaned_ = false;
}
static std::ostream& operator<< (std::ostream& os, const Date& date) {
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}
void Book::Print() const
{
	std::cout << "Book: " << name_ 
		<< " author: " << author_ 
		<< " ISBN: " << isbn_ 
		<< " Loaned: " << loaned_ 
		<< " Due Date: " << due_date_ << "\n";
}

