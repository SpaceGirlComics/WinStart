#ifndef LABEL_H
#define LABEL_H

#include "Wnd.h"

class Label : public Wnd
{
public:
	Label();
	Label(String _id);
	Label(const Label& _cpy);

	Label& operator = (const Label& _rhs);

	String get();
	void setFont(String _s);

	static const unsigned int FNT = 0x0000002C;		// SetFont

	BOOL create(LPCSTR _text, int _x, int _y, HWND _parent);

protected:

	virtual void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);
};



#endif
