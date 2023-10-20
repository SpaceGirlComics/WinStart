#ifndef WND_H
#define WND_H

#include <Windows.h>
#include "Object.h"

class Wnd : public Object
{
public:
	Wnd();
	Wnd(String _id);
	Wnd(const Wnd& _cpy);

	Wnd& operator = (const Wnd& _rhs);

	virtual BOOL create(LPCSTR _className, LPCSTR _windowName, DWORD _style, int _x, int _y, int _width, int _height, HWND _parent, HMENU _menu);
	BOOL show(DWORD _time, DWORD _flag = AW_BLEND | AW_CENTER | AW_ACTIVATE);
	BOOL hide(bool _sw);

	void setWindowText(String _s);

	HWND grab();

	static const unsigned int CMD = 0x00001800;		// Command
	static const unsigned int SWT = 0x00001900;		// Set Text
	static const unsigned int LBD = 0x0000001B;		// Left Mouse Button Down
	static const unsigned int LBU = 0x0000001C;		// Left Mouse Button Up
	static const unsigned int RBD = 0x0000001D;		// Right Mouse Button Down
	static const unsigned int RBU = 0x0000001E;		// Right Mouse Button Up
	static const unsigned int MBD = 0x0000001F;		// Middle Button Down
	static const unsigned int MBU = 0x00000020;		// Middle Button UP
	static const unsigned int WHU = 0x00000021;		// Wheel up
	static const unsigned int WHD = 0x00000022;		// Wheel Down
	static const unsigned int MSO = 0x00000023;		//onMouseOut() {}
	//static const unsigned int MSI = 0x00000024;		//onMouseIn() {}
	static const unsigned int MSM = 0x00000025;		//onMouseMove(float _x, float _y) {}
	static const unsigned int OKD = 0x00000026;		//onKeyDown(DWORD _k) {}
	static const unsigned int OKU = 0x00000027;		//onKeyUp(DWORD _k) {}
	static const unsigned int WDP = 0x00000028;		//onPaint() {}
	static const unsigned int WCL = 0x00000029;		//onClose() {}
	static const unsigned int WFO = 0x0000002A;		//onFocus() {}
	static const unsigned int WBL = 0x0000002B;		//onBlur() {}

	virtual void onCommand(UINT _com);
	virtual void onLButtonDown(float _x, float _y);
	virtual void onLButtonUp(float _x, float _y);
	virtual void onRButtonDown(float _x, float _y);
	virtual void onRButtonUp(float _x, float _y);
	virtual void onMButtonDown(float _x, float _y);
	virtual void onMButtonUp(float _x, float _y);
	virtual void onWheelDown();
	virtual void onWheelUp();
	virtual void onMouseOut();
	//virtual void onMouseIn();
	virtual void onMouseMove(float _x, float _y);
	virtual void onKeyDown(DWORD _k);
	virtual void onKeyUp(DWORD _k);
	virtual void onPaint();
	virtual void onClose();
	virtual void onFocus();
	virtual void onBlur();

	~Wnd();
protected:

	HWND hWnd;
	virtual void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);

	List<Wnd> ctrls;
};

#endif
