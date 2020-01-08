#include <iostream>
#include "tVector.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	tStack<int> testStack;
	testStack.push(7);
	testStack.push(8);
	testStack.push(9);

	cout << "STACK TESTS ---------------------------" << endl;
	cout << "Top Test:" << endl;
	cout << "The top value is currently: " << testStack.top() << endl; // Should be 9
	cout << "My size is: " << testStack.size() << endl << endl; // Should be 3

	cout << "Pop Test:" << endl;
	testStack.pop();
	cout << "Pop!" << endl;
	cout << "The top value is currently: " << testStack.top() << endl; // Should be 8
	cout << "My size is: " << testStack.size() << endl << endl; // Should be 2

	cout << "QUEUE TESTS ---------------------------" << endl;

	return 0;
}