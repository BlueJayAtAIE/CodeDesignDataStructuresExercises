#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"

using std::cout;
using std::cin;
using std::endl;
using std::getline;

// THIS IS ALL HEAVILY TEMP

int main()
{
	std::fstream datRecord;

	Book libraryRecord[] = { Book(), Book(), Book() , Book() , Book() , Book() , Book() , Book() , Book() , Book() }; // Array of 10 books.
	Book libraryRecordFromDat[] = { Book(), Book(), Book() , Book() , Book() , Book() , Book() , Book() , Book() , Book() }; // Array of 10 books.
	int count = sizeof(libraryRecord) / sizeof(Book);

	// Edit some books just to see how they look in the hex viewer that way.
	libraryRecord[0].callNumber = "001.645.2";
	libraryRecord[0].title = "Learning C++";
	libraryRecord[0].author = "Gregory Harrison";
	libraryRecord[1].callNumber = "001.721.3";
	libraryRecord[1].title = "C++ for beginners";
	libraryRecord[1].author = "Quentin Resnick";
	libraryRecord[1].status = 2;
	libraryRecord[1].dueDate = "25/09/1999";
	libraryRecord[1].borrowersName = "Me";

	datRecord.open("data.dat", std::ios_base::out | std::ios_base::binary);
	if (datRecord.is_open())
	{
		for (size_t i = 0; i < count; i++)
		{
			datRecord.write((char*)&libraryRecord[i], sizeof(Book));
		}

		datRecord.close();
	}

	libraryRecord[0].printBook();
	libraryRecord[1].printBook();
	libraryRecord[2].printBook();

	std::cout << endl << endl;

	datRecord.open("data.dat", std::ios_base::in | std::ios_base::binary);
	if (datRecord.is_open())
	{
		int place = 0;

		while (!datRecord.eof() && datRecord.peek() != EOF)
		{
			Book temp;
			datRecord.read((char*)&temp, sizeof(Book));
			libraryRecordFromDat[place].callNumber = temp.callNumber;
			libraryRecordFromDat[place].title = temp.title;
			libraryRecordFromDat[place].author = temp.author;
			libraryRecordFromDat[place].status = temp.status;
			libraryRecordFromDat[place].dueDate = temp.dueDate;
			libraryRecordFromDat[place].borrowersName = temp.borrowersName;

			place++;
		}

		datRecord.close();
	}

	libraryRecordFromDat[0].printBook();
	libraryRecordFromDat[1].printBook();
	libraryRecordFromDat[2].printBook();

	while (true) { }

	return 0;
}