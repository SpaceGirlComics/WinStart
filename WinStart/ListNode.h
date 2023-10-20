#ifndef LISTNODE_H
#define LISTNODE_H

/**
* A node for a linked list
*
* @
* @author Chris Turner
* @version 0.1.4.21.2020
* @since 0.01.4.21.2020
* @see List.h
*/
template<typename T>class ListNode
{
public:
	/** Default Constructor */
	ListNode()
	{
		n = p = (ListNode<T>*) 0;
		status = 0x00000000;
	}

	/** Initialized CTor */
	ListNode(T _item)
	{
		item = _item;
		n = p = (ListNode<T>*) 0;
		status = 0x00000001;
	}

	/** Copy CTor */
	ListNode(const ListNode<T>& _cpy)
	{
		if (_cpy.isSet())
		{
			item = _cpy.item;
		}
		n = _cpy.n;
		p = _cpy.p;
		status = _cpy.status;
	}

	/**
	* for checking if the value contained in this node is set
	* @return one if the value has been set, otherwise zero
	*/
	int isSet()
	{
		return(status & 0x00000001);
	}

	/**
	* Marks this node as unset, the contained value can be retrieved
	* @param _item	pointer to a variable that can hold the
	*				contained value
	* @return one if the node is unset, two if the value of *_item changes, otherwise zero
	*/
	T unset()
	{
		status &= 0xfffffffe;
		return(item);
	}

	/**
	* Returns the next node in the sequence
	*/
	ListNode<T>* next()
	{
		return(n);
	}

	/**
	* Returns the previous node in the sequence
	*/
	ListNode<T>* prev()
	{
		return(p);
	}

	/**
	* Puts _n into sequence after this node
	* @param _n	New node to the sequence
	*/
	void push(ListNode<T>* _n)
	{
		if (n)
		{
			n->p = _n;
			_n->n = n;
			status |= 0x00000004;
		}
		_n->p = this;
		n = _n;
		status |= 0x00000002;
	}

	/**
	* wraps _item in a ListNode and places it after
	* this node
	* @param _item	item being placed into sequence
	*/
	void push(T _item)
	{
		push(new ListNode<T>(_item));
	}

	/**
	* Puts _p into sequence before this node
	* @param _p	New node to the sequence
	*/
	void unshift(ListNode<T>* _p)
	{
		if (p)
		{
			p->n = _p;
			_p->p = p;
			status |= 0x00000002;
		}
		_p->n = this;
		p = _p;
		status |= 0x00000004;
	}

	/**
	* wraps _item in a ListNode and places it before
	* this node
	* @param _item	item being placed into sequence
	*/
	void unshift(T _item)
	{
		unshift(new ListNode<T>(_item));
	}

	/**
	* Removes this node from sequence
	*/
	void untie()
	{
		if (p)
		{
			if (!n)
			{
				p->status &= 0xFFFFFFFB;
			}
			p->n = n;
		}
		if (n)
		{
			if (!p)
			{
				n->status &= 0xFFFFFFFD;
			}
			n->p = p;
		}

		n = p = (ListNode<T>*)0;
		status &= 0xFFFFFFF9;
	}

	/**
	* swaps this node with the one after it
	* @return one for a successful swap, otherwise zero
	*/
	int fwdSwap()
	{
		ListNode<T>* temp = n;
		if (temp)
		{
			untie();
			temp->push(this);
			return(1);
		}
		return(0);
	}

	/**
	* swaps this node with the one before it
	* @return one for a successful swap, otherwise zero
	*/
	int bwdSwap()
	{
		ListNode<T>* temp = p;
		if (temp)
		{
			untie();
			temp->unshift(this);
			return(1);
		}
		return(0);
	}

	/**
	* Helper function for bubble sort function
	* Swaps this node with the next if it's value
	* is determined to be less.
	* @returns 1 if there was a rearrangment
	*/
	int bsort()
	{
		if (n && n->isSet() && n->item < item)
		{
			return(fwdSwap());
		}
		return(0);
	}

	/**
	* for retriving contained values and objects
	* @param _item	pointer to a variable that will hold
	*				the value
	* @return one if the value pointed at by _item changes
	* 		otherwise zero
	*/
	T get()
	{
		return(item);
	}

	/**
	* Sets the value contained in the object
	* @param _item	the new value
	*/
	void set(T _item)
	{
		item = _item;
		status |= 0x00000001;
	}

	/**
	* Assignment Overload
	* Copies the item in _cpy to this node. next and previous in
	* this node are not changed. if _cpy is empty, this node is unset
	*/
	ListNode<T>& operator = (const ListNode<T>& _rhs)
	{
		if (this == &_rhs)
		{
			return(*this);
		}
		if (_rhs.isSet())
		{
			item = _rhs.item;
			status = _rhs.status;
			n = _rhs.n;
			p = _rhs.p;
		}
		else
		{
			status &= 0xFFFFFFF9;
		}
		return(*this);
	}

	/**
	* standard deconstructor
	*/
	~ListNode()
	{
		untie();
	}

protected:
	/** The Contained Value */
	T item;

	/** The next node in the sequence */
	ListNode<T>* n;
	/** The Previous node in the sequence */
	ListNode<T>* p;

	/** Status of the node */
	unsigned int status;
};
#endif
