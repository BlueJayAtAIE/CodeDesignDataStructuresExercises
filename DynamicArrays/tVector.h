#include <iostream>
#pragma once

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 10;

	T *arr;              // Pointer to the underlying array.
	size_t arrSize;      // Stores the current number of USED elements
	size_t arrCapacity;  // Stores the maximum amount of elements we CAN STORE.

public:
	// Initializes the vector's default values.
	tVector()                         
	{
		T* temp = new T[10];
		arr = temp;
		arrSize = 0;
		arrCapacity = 10;
	}

	// Copy constructs a vector from another.
	tVector(const tVector &vec)
	{

	}

	// Destroys the underlying array.
	~tVector()                        
	{
		delete[] arr;
	}

	// Returns a pointer to the underlying array (arr).
	T *data()                         
	{
		return arr;
	}

	// Resizes the vector to at least this many (the provided amount) elements.
	void reserve(size_t newCapacity)  
	{
		// ONLY RESERVE IF NEWCAPACITY IS GREATER.
		if (newCapacity > arrCapacity)
		{
			// Make a new array of expanded size (temp).
			T* temp = new T[newCapacity];
			// Copy over old data.
			for (size_t i = 0; i < arrSize; i++)
			{
				temp[i] = arr[i];
			}
			// Delete old array.
			delete[] arr;
			// Set arr pointer to this new array.
			arr = temp;
			// Change capacity to match new capacity- size stays the same.
			arrCapacity = newCapacity;
		}
	}

	// Adds an element with the value of (value) to the end of the vector.
	void pushBack(const T &value)     
	{
		// Check to see if size = capacity.
		if (arrSize == arrCapacity)
		{
			// If it does, run reserve real fast.
			reserve(arrCapacity + GROWTH_FACTOR);
		}
		// Add value to the array at size, then size++.
		arr[arrSize] = value;
		arrSize++;
	}

	// Drops the last element of the vector.
	void popBack()
	{
		arrSize--;
		arr[arrSize] = NULL;
	}

	// Returns the element at the given index.
	T &at(size_t index)               
	{
		if (index >= arrSize)
		{
			std::cout << "Error! Trying to get a number out of range." << std::endl;
		}
		return arr[index];
	}

	// Returns the current number of USED elements. (arrSize).
	size_t size() const               
	{
		return arrSize;
	}

	// Returns the maximum amount of elements we CAN STORE. (arrCapacity).
	size_t capacity() const           
	{
		return arrCapacity;
	}

	// Utility functions ---------------------------------------------------------------------------------------

	// Returns true if the vector contains no elements.
	bool empty() const                
	{
		if (arrSize == 0) return true;
		return false;
	}

	// Resizes the vector to contain the given number of elements.
	void resize(size_t newCapacity)             
	{
		// TODO: THIS NEEDS WORK STILL.
		if (newCapacity > arrCapacity)
		{
			reserve(newCapacity);
		}

		if (newCapacity < arrCapacity)
		{
			for (size_t i = 0; i < (arrCapacity - newCapacity); i++)
			{
				popBack();
			}
		}
	}

	// Resizes the capacity to match it's size.
	void shrinkToFit()                
	{
		// TODO
	}

	// Empties the vector, destrying all elements (but not destroying the vector!).
	void clear()                      
	{
		// TODO I'm not sure if this counts as deleting everything- technically it's all still there.
		// OH SH-OO-T MAYBE REPLACE ALL THE OTHER STUFF WITH NULL?
		arrSize = 0;
	}

	// Operator Overloads --------------------------------------------------------------------------------------
	
	// Copies the conents FROM THE PROVIDED vector TO THIS vector
	tVector& operator=(const tVector &vec)
	{
		size_t whosGreater;
		if (arrSize > vec.arrSize) whosGreater = arrSize;
		else whosGreater = vec.arrSize;

		for (size_t i = 0; i < whosGreater; i++)
		{
			arr[i] = vec.arr[i];
		}

		arrSize = vec.arrSize;
	}
};

