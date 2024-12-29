#ifndef ELEC_AS_CPP_LIBRARY
#define ELEC_AS_CPP_LIBRARY

#include <string>
#include <vector>

#include "book.hpp"
#include "customer.hpp"

class Library {
public:
	Library(const std::string& name);
	

	// Getters
	const std::string GetName();
	std::vector<Book>& GetBooks();
	std::vector<Customer>& GetCustomers();

	//methods
	Book FindBookByName(const std::string& booktitle);
	
	std::vector<Book> FindBooksByAuthor(const std::string& booktauthor);

	std::vector<Book>& FindAllLoanedBooks();

	Customer FindCustomer(const std::string& customerid);

private:
	std::string name_;
	std::vector<Book> books_;
	std::vector<Customer> Customers_;
};

#endif
