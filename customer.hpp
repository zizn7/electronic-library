
#include <string>
#include <vector>

#include "book.hpp"

class Customer {
public:
	Customer(const std::string& name, const std::string& reference);

//getters
	std::string GetName() const;
	std::string GetID() const;
	int GetLoanAmount() const;
	std::vector<Book> GetLoans() const;

	bool LoanBook(Book& loan_book);
	void ReturnBook(Book& loaned_book);
	void Print() const;

private:
	std::string name_;
	std::string id_;
	std::vector<Book> loans; 

};
