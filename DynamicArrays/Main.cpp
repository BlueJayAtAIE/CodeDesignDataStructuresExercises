#include <iostream>
#include "tVector.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	tVector<int> test;
	test.pushBack(4);
	test.pushBack(5);
	test.pushBack(6);

	cout << "Hey, heres the number at index 0: " << test.at(0) << endl;
	cout << "Hey, heres the number at index 1: " << test.at(1) << endl;
	cout << "Hey, heres the number at index 2: " << test.at(2) << endl;
	cout << "Hey, heres the number at index 3 (not assigned): " << test.at(3) << endl;

	test.popBack();
	cout << endl << "Popback." << endl;
	cout << "Hey, heres the number at index 0: " << test.at(0) << endl;
	cout << "Hey, heres the number at index 1: " << test.at(1) << endl;
	cout << "Hey, heres the number at index 2 (removed): " << test.at(2) << " (this 0 is actually a null)." << endl;

	cout << endl << "Reserve Test:" << endl;
	cout << "My capacity is: " << test.capacity() << endl;
	test.reserve(5);
	cout << "Attempt to make reserve value 5..." << endl;
	cout << "My capacity is: " << test.capacity() << endl;
	test.reserve(15);
	cout << "Attempt to make reserve value 15..." << endl;
	cout << "My capacity is: " << test.capacity() << endl;
	cout << "Hey, heres the number at index 0: " << test.at(0) << endl;
	cout << "Hey, heres the number at index 1: " << test.at(1) << endl;
	cout << "Hey, heres the number at index 2 (not assigned): " << test.at(2) << endl;

	while (true) { }
	return 0;
}