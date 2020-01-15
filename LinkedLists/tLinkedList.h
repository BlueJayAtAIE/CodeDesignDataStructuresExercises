#pragma once

template <typename T>
class tLinkedList
{
	struct Node
	{
		// Data for the element stored.
		T data;

		// Pointer to the node following this Node.
		Node * next;
	};

	// Pointer to the head of the Linked List.
	Node * head;

public:
	class iterator
	{
		// Current node being operated upon.
		Node * current;

	public:
		// Initializes an empty iterator pointing to NULL.
		iterator()
		{
			current = nullptr;
		}

		// Initializes an empty iterator pointing to the given Node.
		iterator(Node * startNode)
		{
			current = startNode;
		}


		// Returns true if the iterator points to the same node.
		bool operator==(const iterator& rhs) const 
		{
			if (current->data == rhs.current->data && current->next == rhs.current->next)
			{
				return true;
			}

			return false;
		}

		// Returns true if the iterator does not point to the same node.
		bool operator!=(const iterator& rhs) const
		{
			if (current->data != rhs.current->data && current->next != rhs.current->next)
			{
				return true;
			}

			return false;
		}

		// Returns a reference to the element pointed to by the current Node.
		T& operator*() const
		{
			return current->data;
		}

		// Pre-increment (returns a reference to this iterator after it is incremented).
		iterator& operator++()
		{
			current = current->next;
			return *this;
		}

		// Post-increment (returns an iterator to the current Node while incrementing the existing iterator).
		iterator operator++(int)
		{
			return (*this)++;
		}
	};

	iterator begin()
	{
		iterator temp(head);
		return temp;
	}

	iterator end()
	{
		iterator temp(head);
		while (*temp != NULL)
		{
			++temp;
		}
		return temp;
	}

	// Initializes Head to NULL.
	tLinkedList()
	{
		Node * temp = new Node;
		temp->data = NULL;
		temp->next = nullptr; // Is this needed? Maybe not but but helps me read this better.
		head = temp;
	}

	// Copy-Constructor.
	tLinkedList(const tLinkedList& list)
	{
		*this = list;
	}

	// Delete all nodes upon destruction.
	~tLinkedList()
	{
		// TODO
	}

	// Adds an element to the front (Head).
	void pushFront(const T& val)
	{
		Node * temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
	}

	// Removes element from the front.
	void popFront()
	{
		if (head->data != NULL)
		{
			head = head->next;
		}
	}

	// Returns the element at the head.
	T& front()
	{
		return head->data;
	}

	// Returns the element at the head (const).
	const T& front() const
	{
		return head->data;
	}

	// Removes ALL elements equal to the value.
	void remove(const T& val)
	{
		for (auto it = begin(); it != end(); ++it)
		{
			if (true)
			{
				// TODO
			}
		}
	}

	// Returns true if there are no elements.
	bool empty() const
	{
		if (head->data == NULL && head->next == nullptr) return true;
		return false;
	}

	// Destroys every single node in the linked list (but doesn't destroy the list itself!).
	void clear()
	{
		for (auto it = begin(); it != end(); ++it)
		{
			popFront();
		}
	}

	// Resizes the linked list to contain the given number of elements.
	// New elements are default-initialized.
	void resize(size_t newSize)
	{
		int currentSize = 0;
		for (auto it = begin(); it != end(); ++it)
		{
			currentSize++;
		}

		if (newSize > currentSize)
		{
			for (size_t i = currentSize; i < newSize; i++)
			{
				pushFront(1); // TODO, having this be 0 messes with iterators going through, who see 0 as NULL.
			}
		}
	}

	// Copy-assignment.
	tLinkedList& operator=(const tLinkedList & rhs)
	{
		// TODO
	}
};