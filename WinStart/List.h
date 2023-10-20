#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

/**
* A simple linked list class
*
* @
* @author Chris Turner
* @version 0.1.8.2.2020
* @see ListNode.h
* @todo Add sorting
* @todo Add search
* @since 0.1.10.24.2020 added indexing
*/
template <typename T>class List
{
public:
	/**
	* Default Constructor
	* @since 0.1.4.21.2020
	*/
	List()
	{
		head = tail = current = (ListNode<T>*)0;							// Initialize Pointers to NULL
		length = 0;															// Initialize length to zero
		selected = -1;														// Set selected index to -1 (none selected)
	}

	/**
	* create list with first item
	* @param _item - the initial item in the list
	* @since 0.1.4.21.2020
	*/
	List(T _item)
	{
		start(_item);														// Create the first node in the sequence with _item
		length = 1;															// set length to 1
		//selected = 0;														// set selected index to 0 (the first node)
	}

	/**
	* Copy Constructor
	* makes a copy of _cpy
	* @since 0.1.4.21.2020
	*/
	List(const List<T>& _cpy)
	{
		head = tail = current = (ListNode<T>*)0;							// Initialize Pointers to NULL 
		ListNode<T>* c = _cpy.head;											// create a pointer (c) to the fist node in cpy 
		length = 0;															// Initialize length to zero 
		selected = -1;														// Set selected index to -1 (none selected)
		while (c)															// while c is not NULL
		{
			push(c->get());													// push a copy of the contents of c to the sequence 
			if (!current)													// if current is null 
			{
				selected++;													// increase selected index
			}
			if (c == _cpy.current)											// if c points to the selection in _cpy
			{
				current = tail;												// set selected index to the node created
			}
			c = c->next();													// point c to the next in the sequence
		}
	}

	/**
	* Assignment operator
	* @since 0.1.4.21.2020
	*/
	List<T>& operator=(const List<T>& _rhs)
	{
		if (this == &_rhs)													// if self assigning
		{
			return(*this);													// just return
		}
		clear();															// clear this list
		ListNode<T>* c = _rhs.head;											// create pointer (c) to the first node in _rhs
		while (c)															// while c is not pointing to nothing
		{
			push(c->get());													// push a copy of the node in _rhs to this sequence
			if (!current)													// if current is unassigned
			{
				selected++;													// increase selected index
			}
			if (c == _rhs.current)											// if c is pointing to the selected node in _rhs
			{
				current = tail;												// assign current to this node
			}
			c = c->next();													// point c to the next in _rhs sequence
		}
		return(*this);
	}

	/**
	* Sets the Current Pointer to Head
	* @since 0.1.4.21.2020
	*/
	void reset()
	{
		current = head;														// point current to the head of the sequence
		if (current)														// if current is not nullified
		{
			selected = 0;													// set selected index to zero
		}
	}

	/**
	* Places a new node at the end of the sequence and points tail to it
	* @since 0.1.4.21.2020
	* @param _item new item being added to the sequence
	* @returns The length of the sequence afte the new node is added
	*/
	int push(T _item)
	{
		if (tail)															// if there is a sequence already
		{
			tail->push(_item);												// place the new node after tail
			tail = tail->next();											// point tail to the new end of the sequence
		}
		else																// otherwise
		{
			start(_item);													// begin a new sequence
		}
		return(++length);													// return the new length
	}

	/**
	* Removes the tail node and, if it exists, points tail to the
	* previous node
	* @since 0.1.4.21.2020 - Original
	* @since 0.1.8.2.2020 - Removed Existance Checking.
	* @returns The contents of the popped node
	*/
	T pop()
	{
		ListNode<T>* temp = tail;											// create a pointer to the current tail
		T i = temp->get();													// get the contents of the tail
		if (tail == head)													// if the sequence is 1 node in length
		{
			delete(tail);													// delete the tail
			tail = head = current = (ListNode<T>*)0;						// nullify the pointers 
			selected = -1;													// set selected index to -1 (none selected)
		}
		else																// if the sequence length > 1
		{
			if (tail == current)											// if the tail is the selected node
			{
				current = current->prev();									// point the current to the previous node
				selected--;													// decrement selected index
			}
			tail = tail->prev();											// point tail to the previous node
			temp->untie();													// remove the old tail from the sequence
			delete(temp);													// delete the old tail
		}
		length--;															// decrement the length of the sequence
		return(i);															// remove the old tails contents
	}

	/**
	* adds a new node to the beginning of the sequence
	* and points head to it
	* @since 0.1.4.21.2020
	* @param _item - new item being added to the sequence
	* @returns The new length of the sequence
	*/
	int unshift(T _item)
	{
		if (head)															// if there is already a sequence started
		{
			head->unshift(_item);											// place a new node before the head
			head = head->prev();											// point head to the new beginning node
			selected++;														// increase selected index
		}
		else																// if this is a new sequence
		{
			start(_item);													// create a new node and point to it
		}
		return(++length);													// return the new length
	}

	/**
	* Removes the head node from the list and, if it exists,
	* points head to the next node
	* @since 0.1.4.21.2020 - Original
	* @since 0.1.8.2.2020 - Removed Existance Checking.
	* @returns the contents of the old head node
	*/
	T shift()
	{
		ListNode<T>* temp = head;											// create a pointer to the first node in the sequence
		T i = head->get();													// get the contents of the first node
		if (head == tail)													// if the sequence is one node in length
		{
			delete(head);													// delete head
			head = tail = current = (ListNode<T>*)0;						// nullify the pointers
			selected = -1;													// set the selected index to -1 (none selected)
		}
		else																// if the sequence length > 1
		{
			if (head == current)											// if the head is the selected node
			{
				current = current->next();									// point current to the next node
				selected = 0;												// set selected to zero
			}
			else															// if head is not the selected node
			{
				selected--;													// decrement selected index
			}
			head = head->next();											// point head to next
			temp->untie();													// remove the first node
			delete(temp);													// delete the old head
		}
		length--;															// decrement the length
		return(i);															// return the contents of the old head
	}

	/**
	* places a new node after current
	* @since 0.1.4.21.2020
	* @param _item - content being added
	* @returns the length of the sequence after adding the new contents
	*/
	int add(T _item)
	{
		if (current)														// if there is already a sequence
		{
			if (current == tail)											// if the selected node is the tail (or current is NULL)
			{
				return(push(_item));										// add via the push function
			}
			else															// otherwise
			{
				current->push(_item);										// insert after the selected node

			}
		}
		else																// if there is not an existing sequence
		{
			start(_item);													// begin a new list
		}
		return(++length);													// return the new length
	}

	/**
	* places a new node before current
	* @since 0.1.4.21.2020
	* @param _item - content being added
	* @returns the length of the sequence after adding the new contents
	*/
	int insert(T _item)
	{
		if (current)														// if there is already a list
		{
			if (current == head)											// and current node is the head (or current is null)
			{
				return(unshift(_item));										// add via the unshift function
			}
			else															// if the current is not the head
			{
				current->unshift(_item);									// add a new node before the current
				selected++;													// increment selected index
			}
		}
		else																// if ther is no list
		{
			start(_item);													// begin a new list
		}
		return(++length);													// return the new length
	}

	/**
	* Removes the current node.
	* @since 0.1.4.21.2020 - Original
	* @since 0.1.8.2.2020 - Removed Existance Checking.
	* @returns the contents of the selected node. if no node is selected, behaviour is undefined
	*/
	T remove()
	{
		if (current == head)												// if the selected node is the first
		{
			return(shift());												// remove via the shift function
		}
		else if (current == tail)											// if the selected nodeis the last
		{
			return(pop());													// remove via the pop function
		}
		else																// otherwise
		{
			ListNode<T>* temp = current;									// create a temporary pointer to the selected node
			T i = temp->get();												// get the contents of the selected node
			current = current->next();										// point current to the next in the list
			temp->untie();													// remove the previously selected node
			length--;														// decrement the length
			delete(temp);													// delete the removed node
			return(i);	/**/												// return the contents of the deleted node
		}
	}

	/**
	* Removes the node at _index.
	* @since 0.1.4.21.2020 - Original
	* @since 0.1.8.2.2020 - Removed Existance Checking.
	* @param _index index of the node being removed
	* @returns the contents of the node at _index. if no node is selected, behaviour is undefined
	*/
	T remove(int _index)
	{
		ListNode<T>* temp = head;											// create a pointer to the head of the list
		for (int x = 0; x < _index; x++)									// until temp is pointing to the node at index
		{
			temp = temp->next();											// point temp to the next in sequence
		}
		if (temp == head)													// if temp is pointing to the head
		{
			return(shift());												// remove via shift
		}
		else if (temp == tail)												// if temp is pointing to the tail
		{
			return(pop());													// remove via pop
		}
		else																// otherwise
		{
			if (temp == current)											// if temp is pointing to current
			{
				current = current->next();									// point current to next
			}
			T i = temp->get();												// get contents of temp
			temp->untie();													// remove temp from the sequence
			length--;														// decrement the length
			delete(temp);													// delete the removed node
			return(i);	/**/												// return the deleted node's contents
		}
	}

	/**
	* moves current up in the sequence.
	* @since 0.1.4.21.2020
	* @returns non zero if the selected node changes
	*/
	int next()
	{
		if (current)														// if there is an existing sequence
		{
			current = current->next();										// point current to its next
			return(1);														// and return 1
		}
		return(0);															// otherwise return 0;
	}

	/**
	* moves current down the sequence
	* @since 0.1.4.21.2020
	* @returns non zero if the selected node changes
	*/
	int prev()																// if there is an existing sequence
	{
		if (current)
		{
			current = current->prev();										// point current to its previous
			return(1);														// and return 1
		}
		return(0);															// otherwise return 0;
	}

	/**
	* retrives the current item
	* @since 0.1.4.21.2020 - Original
	* @since 0.1.8.2.2020 - Removed Existance Checking.
	* @returns the content of the current node. if no node is selected, behaviour is undefined
	*/
	T get()
	{
		return(current->get()); /**/
	}

	/**
	* retrives the item at index
	* @since 0.1.8.2.2020
	* @param _index - the index of the node being requested
	* @returns the contents of the node at _index. if no node is selected, behaviour is undefined
	*/
	T get(int _index)
	{
		ListNode<T>* temp = head;											// create a temporary pointer to the first node in the sequence
		for (int x = 0; x < _index; x++)									// while x is less than the specified index
		{
			temp = temp->next();											// point temp to the next node in the sequence
		}
		return(temp->get()); /**/											// return the contents of the temporary selection
	}

	/**
	* sets the current item
	* @since 0.1.4.21.2020
	*/
	int set(T _item)
	{
		if (current)														// if there is a selected node
		{
			current->set(_item);											// set its contents to _item
			return(1);														// and return 1
		}
		return(0);															// otherwise just return 0;
	}

	/**
	* Gets the length of the sequence
	* @since 0.1.4.21.2020
	* @returns the number of nodes in the squence
	*/
	int getLength()
	{
		return(length);
	}

	/**
	*
	* @since 0.1.4.21.2020
	* @returns non zero if current is pointing to a node
	*/
	bool isSelected()
	{
		return(current != (ListNode<T>*)0);
	}

	/**
	*
	* @since 0.1.8.2.2020
	* @returns Nonzero if the current node is selected and is set
	*/
	bool isSet()
	{
		if (current)														// if there is a selected node
		{
			return((bool)current->isSet());									// return the "set" status if the selected node
		}
		return(false);														// if there is none selected, return false
	}

	/**
	* deletes All nodes in this list
	* @since 0.1.4.21.2020
	*/
	void clear()
	{
		reset();															// select the beginning node of the list
		while (current)														// while there is a selected node
		{
			remove();														// remove the selected node from the sequence
			//next();															// move to the next node
		}
	}

	/**
	* Adds copies of all the contents of _lst to this list
	*/
	void append(const List<T>& _lst)
	{
		ListNode<T>* temp = _lst.head;										// create a pointer to the head of _lst 
		//_lst.reset();
		for (int x = 0; x < _lst.length; x++)								// for each node in _lst sequence
		{
			push(temp->get());												// add the selected node in _lst to this sequence
			temp = temp->next();											// move temp to the next node
		}
		//_lst.current = temp;
	}

	/**
	* Returns the index of the current selection
	* @since 0.1.10.24.2020
	**/
	int getSelectedIndex()
	{
		return(selected);
	}

	/**
	* Moves current to the node at position _i
	* negative numbers count from the end of the sequence
	* @returns a negative number if unsuccessful
	* @since 0.1.10.24.2020
	**/
	int setSelectedIndex(int _i)
	{
		if (_i == selected)
		{
			return(0);
		}
		if (_i >= length)													// if _i is greater than the length of the sequence 
		{
			return(-1);														// return -1
		}
		else if (_i < 0)													// if _i is less than zero
		{
			if (_i < (0 - length))											// if _i is less than -length
			{
				return(-1);													// return -1
			}
			_i = length + _i;												// make _i a positive index
		}
		current = head;														// set current to head
		for (int x = 0; x < _i; x++)										// while x is less than _i
		{
			next();															// point current to the next node in sequence
		}
		return(0);
	}

	/**
	* Destructor
	*/
	~List()
	{
		clear();
	}

protected:
	ListNode<T>* head;			/** first node in the sequence */
	ListNode<T>* tail;			/** last node in the sequence */
	ListNode<T>* current;		/** selected node in the sequence */
	int length;					/** amount of nodes in the sequence **/
	int selected;				/** index of the selected node */

	/**
	* creates the first node
	* @since 0.1.4.21.2020
	*/
	void start(T _item)
	{
		tail = head = current = new ListNode<T>(_item);
		selected = 0;
	}
};
#endif
