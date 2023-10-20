#ifndef BUTTON_H
#define BUTTON_H

#include "Wnd.h"
#include <CommCtrl.h>

class Button : public Wnd
{
public:
	Button();
	Button(String _id);
	Button(const Button& _cpy);

	//void update(int _time);
	virtual List<Message*> update(int _time);

	void setIcon(unsigned int _icon, int _width = 16, int _height = 16);

	void setTip(String _tipText);
	//int getTip(String& _tipText);

	BOOL create(LPCSTR _windowName, DWORD _style, int _x, int _y, int _width, int _height, HWND _parent, UINT _rcId);
protected:

	void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);

	//void createTip();
	HWND hTip;
};
#endif
