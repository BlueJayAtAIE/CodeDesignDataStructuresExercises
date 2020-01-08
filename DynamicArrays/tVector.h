#include <iostream>
#include <cassert>
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
		*this = vec;
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
			// I COULD do arrCapacity * 2 in here but I wanted to actually use GROWTH_FACTOR.
			// Plus doubling it every time seems like a bit much.
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
		if ((index >= arrSize || index < 0))
		{
			std::cout << "Error! Trying to get a number out of range." << std::endl;
		}

		// You should use this assert, but since this debug test replies on things going out of bounds 
		// for demonstrative purposes, thats counter productive.
		//assert((index >= arrSize || index < 0) && "Error! Trying to get a number out of range.");

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
	void resize(size_t t)             
	{
		// If t is greater than arrCapacity, then reallocate (reserve).
		if (t > arrCapacity)
		{
			reserve(t);
		}

		// If t is greater than arrSize but less than arrCapacity, set values in cells up to t with a value (0 maybe?)
		if (t > arrSize && t <= arrCapacity)
		{
			for (size_t i = arrSize; i < t; i++)
			{
				pushBack(0);
			}
		}

		// if t is smaller than arrSize, it is reduced to t via popBack.
		if (t < arrSize)
		{
			for (size_t i = 0; i < t; i++)
			{
				popBack();
			}
		}
	}

	// Resizes the capacity to match it's size.
	void shrinkToFit()                
	{
		arrCapacity = arrSize;
	}

	// Empties the vector, destrying all elements (but not destroying the vector!). This also changes size back to 0.
	void clear()                      
	{
		for (size_t i = arrSize; i > 0; i--)
		{
			popBack();
		}
		arrSize = 0;
	}

	// Operator Overloads --------------------------------------------------------------------------------------
	
	// Copies the conents FROM THE PROVIDED vector TO THIS vector
	tVector& operator=(const tVector &vec)
	{
		reserve(vec.arrCapacity);

		for (size_t i = 0; i < vec.arrSize; i++)
		{
			pushBack(vec.arr[i]);
		}

		return *this;
	}

	T& operator[] (size_t index)
	{
		return arr[index];
	}
};

