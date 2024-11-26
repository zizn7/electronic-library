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
	std::vector<Book>& GetCustomers();


	Book FindBookByName(const std::string& booktitle);
	
	Book FindBooksByAuthor(const std::string& booktauthor);

	std::vector<Book>& FindAllLoanedBooks();

	

	Customer FindCustomer(const std::string& customerid);

		   /**
			* \brief Searches for a customer with specfied id
			*
			* Function identifier: FindCustomer
			*
			* \param id the id of the customer (a const reference to a string)
			*
			* \return A copy of the found customer. if a Customer is not found, a new
			* Customer with empty name and id is returned.
			*/


private:
	std::string name_;
	std::vector<Book> books_;
	std::vector<Customer> Customers_;
};

#endif
