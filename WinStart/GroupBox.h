#ifndef GROUPBOX_H
#define GROUPBOX_H


#include "Wnd.h"

class GroupBox : public Wnd
{
public:
	GroupBox();
	GroupBox(String _id);
	GroupBox(const GroupBox& _cpy);

	//void update(int _time);
	virtual List<Message*> update(int _time);

	BOOL create(LPCSTR _windowName, int _x, int _y, int _width, int _height, HWND _parent);
protected:

	void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);
};
#endif
