#ifndef FRAME_H
#define FRAME_H

#include "Wnd.h"

class Frame : public Wnd
{
public:
	Frame();
	Frame(String _id);
	Frame(const Frame& _cpy);

	virtual BOOL create(LPCSTR _windowName, DWORD _style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		int _x = 0, int _y = 0, int _width = 1280, int _height = 800,
		HWND _parent = (HWND)NULL, HMENU _menu = (HMENU)NULL, DWORD _exStyle = WS_EX_APPWINDOW);

	//void update(int _time);
	//virtual List<Message*> update(int _delta);

	virtual void modalize();
	virtual void demodalize();

	BOOL moveTo(int _x, int _y);
	BOOL lineTo(int _x, int _y);

	void text(char* _s, int _x, int _y);

	static const unsigned int MDZ = 0x00000037;						// Make Frame Modal
	static const unsigned int MDS = 0x00000038;						// Make Frame Modeless

	~Frame();
protected:
	RECT client;
	HDC dc;

	virtual void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);
};
#endif
