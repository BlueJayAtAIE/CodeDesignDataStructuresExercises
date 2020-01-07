#include <string>
#pragma once

using std::string;

class Book
{
public:
	Book();
	Book(string bookNumber, string bookTitle, string bookAuthor, int bookStatus, string bookDueDate, string bookBorrower);
	~Book();

	void printBook();

	string callNumber;
	string title;
	string author;
	int status; // (1 = in library, 2 = on loan, 3 = lost)
	string dueDate;
	string borrowersName;
};

