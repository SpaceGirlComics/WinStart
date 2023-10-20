/**
* A Single-Selection List Box
*
* @
* @author Chris Turner
* @version 0.1.4.21.2020
* @since 0.01.4.21.2020
* @see ListBox.cpp
*/

#ifndef LISTBOX_H
#define LISTBOX_H

#include "Wnd.h"

class ListBox : public Wnd
{
public:
	ListBox();
	ListBox(String _id);
	ListBox(const ListBox& _cpy);

	ListBox& operator=(const ListBox& _rhs);

	//void update(int _time);
	/*virtual List<Message*> update(int _time);*/

	void setSelection(int _i);

	void unshift(String _i);
	void add(String _i);
	void insert(String _i);
	void push(String _i);

	String shift();
	String remove();
	String remove(int _i);
	String pop();

	String get();
	String get(int _i);
	int getSelectedIndex();
	int getCount();

	void raiseSelected();
	void lowerSelected();

	BOOL create(int _x, int _y, int _width, int _height, HWND _parent);

	static const unsigned int SSL = 0x0000002C;		// Set Selection
	static const unsigned int USL = 0x0000002D;		// Unshift 
	static const unsigned int ADS = 0x0000002E;		// Add String at index
	static const unsigned int INS = 0x0000002F;		// Insert String after index
	static const unsigned int PSH = 0x00000030;		// Push String to end of list
	static const unsigned int SFT = 0x00000031;		// Shift
	static const unsigned int REM = 0x00000032;		// Remove selected String
	static const unsigned int RMI = 0x00000033;		// Remove String at Index
	static const unsigned int POP = 0x00000034;		// Pop string from the end of the list
	static const unsigned int RAS = 0x00000035;		// Raise selected
	static const unsigned int LWS = 0x00000036;		// Lower Selected

	~ListBox();
protected:

	virtual void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);
};


#endif
