#include "customer.hpp"
#include <iostream>

Customer::Customer(const std::string& name, const std::string& reference): name_(name), id_(reference){}

std::string Customer::GetName() const
{
	return name_;
}

std::string Customer::GetID() const
{
	return id_;
}

int Customer::GetLoanAmount() const
{
	return loans.size();
}

std::vector<Book> Customer::GetLoans() const
{
	return loans;
}
bool Customer::LoanBook(Book& loan_book) {
	if (loan_book.Loan()) {
		loans.push_back(loan_book);
		return true;
	 }
	return false;
}

void Customer::ReturnBook(Book& loaned_book)
{
	loaned_book.Restore();
}

void Customer::Print() const
{
	std::cout << "Customer: " << name_ << " Customer ID: " << id_ << " has " << loans.size() << " books on loan \n";
	for (const auto& i : loans) {
		i.Print();
	}
}
