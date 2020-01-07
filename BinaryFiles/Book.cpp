#include "Book.h"
#include <iostream>

Book::Book()
{
	callNumber = "000.000.0";
	title = "Placeholder Title";
	author = "Mr. Placeholder";
	status = 1;
	dueDate = "00/00/0000";
	borrowersName = "No One";
}

Book::Book(string bookNumber, string bookTitle, string bookAuthor, int bookStatus, string bookDueDate, string bookBorrower)
{
	callNumber = bookNumber;
	title = bookTitle;
	author = bookAuthor;
	status = bookStatus;
	dueDate = bookDueDate;
	borrowersName = bookBorrower;
}

Book::~Book() { }

void Book::printBook()
{
	std::cout << callNumber << ": " << title << ", By " << author << " | ";
	switch (status)
	{
	case 1:
	default:
		std::cout << "Not Checked Out";
		break;
	case 2:
		std::cout << "Checked out by: ";
		break;
	case 3:
		std::cout << "Lost; last checked to: ";
		break;
	}
	if (status > 1)
	{
		std::cout << borrowersName << ", to be returned on: " << dueDate;
	}
	std::cout << std::endl;
}
