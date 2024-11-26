#include "library.hpp"

#include <iostream>

#include "book.hpp"
#include "customer.hpp"

Library::Library(const std::string& name)
{
}

const std::string Library::GetName()
{
	return std::string();
}

std::vector<Book>& Library::GetBooks()
{
	// TODO: insert return statement here
}

Book Library::FindBookByName(const std::string& booktitle)
{
	bool a = false;
	for (auto& i : Library::books_) {
		if (i.GetName() == booktitle)
			a = true;
		return i;
	}
	if (!a) {
		
		std::string name, author, isbn;
		std::cout << "enter the book's name";
		std::cin >> name;

		std::cout << "enter the book author's name";
		std::cin >> author;

		std::cout << "enter the book's isbn";
		std::cin >> isbn;

		Book newbook(name, author, isbn, bool status = false, Date due_date = { 0, 0, 0 })
	}
}

Book Library::FindBooksByAuthor(const std::string& booktauthor)
{
	std::vector<Book> vectorbookauthor = {};
	bool a = false;
	for (auto& i : Library::books_) {
		if (i.GetAuthor() == booktauthor)
			vectorbookauthor.push_back(i)
	}
	return vectorbookauthor;
}

std::vector<Book>& Library::FindAllLoanedBooks()
{
	bool a = false;
	std::vector<Book> loanedbooks = {};
	for (auto& i : Library::books_) {
		if (i.GetStatus())
			loanedbooks.push_back(i);
	}
	return loanedbooks; 
}

Customer Library::FindCustomer(const std::string& customerid)
{
	bool a = false;
	for (auto& i : cutomers_) {
		if (i.GetID() == customerid) {
			return i;
			a = true;
			break;
		}
	}
	if (!a) {
		std::string name, id;
		std::cout << "enter the customer's name";
		std::cin >> name;

		std::cout << "enter the book customer's id";
		std::cin >> id;
		Customer(name, id)
	}
}
