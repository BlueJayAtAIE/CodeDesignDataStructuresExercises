#include <iostream>
#include "tLinkedList.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	tLinkedList<int> blah;

	// This List empty...
	if (blah.empty())
	{
		std::cout << "YEET" << std::endl << std::endl;
	}

	blah.pushFront(4);
	blah.pushFront(2);
	blah.pushFront(5);
	blah.pushFront(6);

	for (auto it = blah.begin(); it != blah.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	std::cout << std::endl;

	blah.resize(7);

	for (auto it = blah.begin(); it != blah.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	std::cout << std::endl;

	blah.popFront();

	for (auto it = blah.begin(); it != blah.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	blah.clear();

	// This List empty...
	if (blah.empty())
	{
		std::cout << std::endl << "YEET" << std::endl;
	}

	while (true) { }

	return 0;
}