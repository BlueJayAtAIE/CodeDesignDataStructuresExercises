#include <iostream>
#include "tVector.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	tVector<int> test;

	// Most of this uses .at() instead of [] because I made the [] operator last.
	// The first two examples use it just to show that it works.

	cout << endl << "Assignment Test:" << endl;
	test.pushBack(4);
	cout << "Hey, heres the number at index 0: " << test[0] << endl;
	test.pushBack(5);
	cout << "Hey, heres the number at index 1: " << test[1] << endl;
	test.pushBack(6);
	cout << "Hey, heres the number at index 2: " << test[2] << endl;
	cout << "Hey, heres the number at index 3 (not assigned): " << test.at(3) << endl;
	// ---------------------------------------------------------------------------------------------------------------
	cout << endl << "Copy Test:" << endl;
	tVector<int> copy(test);
	cout << "Copying first vector to another..." << endl;
	cout << "Hey, heres the number at index 0 (of the second vector): " << copy[0] << endl;
	cout << "Hey, heres the number at index 1 (of the second vector): " << copy[1] << endl;
	cout << "Hey, heres the number at index 2 (of the second vector): " << copy[2] << endl;
	cout << "Hey, heres the number at index 3 (of the second vector) (not assigned): " << copy.at(3) << endl;
	// ---------------------------------------------------------------------------------------------------------------
	cout << endl << "Popback Test:" << endl;
	test.popBack();
	cout << "Popback." << endl;
	cout << "Hey, heres the number at index 0: " << test.at(0) << endl;
	cout << "Hey, heres the number at index 1: " << test.at(1) << endl;
	cout << "Hey, heres the number at index 2 (removed): " << test.at(2) << " (this 0 is actually a null)." << endl;
	// ---------------------------------------------------------------------------------------------------------------
	cout << endl << "Copy Test....... 2!:" << endl;
	cout << "Hey, heres the number at index 0 (of the second vector): " << copy.at(0) << endl;
	cout << "Hey, heres the number at index 1 (of the second vector): " << copy.at(1) << endl;
	cout << "Hey, heres the number at index 2 (of the second vector): " << copy.at(2) << endl;
	cout << "Hey, heres the number at index 3 (of the second vector) (not assigned): " << copy.at(3) << endl;
	cout << "THESE VALUES SHOULD BE THE SAME AS AT THE END OF THE FIRST TEST." << endl;
	// ---------------------------------------------------------------------------------------------------------------
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
	// ---------------------------------------------------------------------------------------------------------------
	cout << endl << "Resize Test:" << endl;
	cout << "My size is: " << test.size() << endl;
	test.resize(10);
	cout << "Attempt to make resize value 10..." << endl;
	cout << "My size is: " << test.size() << endl;
	cout << "Hey, heres the number at index 0: " << test.at(0) << endl;
	cout << "Hey, heres the number at index 1: " << test.at(1) << endl;
	cout << "Hey, heres the number at index 2: " << test.at(2) << endl;
	cout << "Hey, heres the number at index 3: " << test.at(3) << endl;
	cout << "Hey, heres the number at index 4: " << test.at(4) << endl;
	cout << "Hey, heres the number at index 9: " << test.at(9) << endl;
	cout << "Hey, heres the number at index 10 (not assigned): " << test.at(10) << endl;
	cout << "Hey, heres the number at index 11 (not assigned): " << test.at(11) << endl;
	test.resize(5);
	cout << "Attempt to make resize value 5..." << endl;
	cout << "My size is: " << test.size() << endl;
	cout << "Hey, heres the number at index 0: " << test.at(0) << endl;
	cout << "Hey, heres the number at index 1: " << test.at(1) << endl;
	cout << "Hey, heres the number at index 2: " << test.at(2) << endl;
	cout << "Hey, heres the number at index 3: " << test.at(3) << endl;
	cout << "Hey, heres the number at index 4: " << test.at(4) << endl;
	cout << "Hey, heres the number at index 5 (not assigned): " << test.at(5) << endl;
	cout << "Hey, heres the number at index 6 (not assigned): " << test.at(6) << endl;
	// ---------------------------------------------------------------------------------------------------------------
	cout << endl << "Shrink-to-Fit Test:" << endl;
	cout << "My size is: " << test.size() << endl;
	cout << "My capacity is: " << test.capacity() << endl;
	cout << "Changing capacity to fit size..." << endl;
	test.shrinkToFit();
	cout << "My size is: " << test.size() << endl;
	cout << "My capacity is: " << test.capacity() << endl;
	// THIS GOES AT THE VERY END
	// ---------------------------------------------------------------------------------------------------------------
	cout << endl << "Clear Test:" << endl;
	cout << "Hey, heres the number at index 0: " << test.at(0) << endl;
	cout << "Hey, heres the number at index 1: " << test.at(1) << endl;
	cout << "Clearing..." << endl;
	test.clear();
	cout << "Hey, heres the number at index 0 (not assigned): " << test.at(0) << endl;
	cout << "Hey, heres the number at index 1 (not assigned): " << test.at(1) << endl;
	cout << "My size is: " << test.size() << endl;
	cout << "My capacity is: " << test.capacity() << endl;
	// ---------------------------------------------------------------------------------------------------------------
	cout << endl << "Copy Test 3: The Revengance:" << endl;
	cout << "Hey, heres the number at index 0 (of the second vector): " << copy.at(0) << endl;
	cout << "Hey, heres the number at index 1 (of the second vector): " << copy.at(1) << endl;
	cout << "Hey, heres the number at index 2 (of the second vector): " << copy.at(2) << endl;
	cout << "Hey, heres the number at index 3 (of the second vector) (not assigned): " << copy.at(3) << endl;
	cout << "THESE VALUES SHOULD BE THE SAME AS AT THE END OF THE OTHER TESTS." << endl;
	// ---------------------------------------------------------------------------------------------------------------
	cout << endl << "Final Test:" << endl;
	cout << "Hey, heres the number at index -1: " << test.at(-1) << endl;


	return 0;
}