#include "Button.h"

Button::Button() : Wnd()
{
	hTip = (HWND)0;
	type = "Button";
	id = type + count;
}

Button::Button(String _id) : Wnd(_id)
{
	hTip = (HWND)0;
	type = "Button";
}

Button::Button(const Button & _cpy) : Wnd(_cpy)
{
	char t[250];
	if (_cpy.hWnd)
	{
		GetWindowText(_cpy.hWnd, t, 249);
		if (hWnd)
		{
			SetWindowText(hWnd, t);
		}
	}
}

//void Button::update(int _time)
List<Message*> Button::update(int _time)
{
	return(Wnd::update(_time));
	/*for (int x = 0; x < subs.getLength(); x++)
	{
		(*subs.pointTo())->update(_time);
		subs.next();
	}
	subs.reset();*/
}

void Button::setIcon(unsigned int _icon, int _width, int _height)
{
	HICON ic = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(_icon), IMAGE_ICON, _width, _height, NULL);
	SendMessage(hWnd, BM_SETIMAGE, IMAGE_ICON, (LPARAM)ic);
}

void Button::setTip(String _tipText)
{
	char* tiptext;
	_tipText.get(&tiptext);
	if (hTip)
	{
		DestroyWindow(hTip);
		hTip = (HWND)0;
	}

	if (hWnd)
	{
		hTip = CreateWindowEx(NULL, 
							TOOLTIPS_CLASS, 
							NULL,
							WS_POPUP | TTS_ALWAYSTIP, 
							CW_USEDEFAULT, 
							CW_USEDEFAULT,
							CW_USEDEFAULT, 
							CW_USEDEFAULT, 
							GetParent(hWnd), 
							NULL,
							GetModuleHandle(NULL), 
							NULL);
		if (hTip)
		{
			TOOLINFO ti = { 0 };
			ti.cbSize = sizeof(TOOLINFO);
			ti.hwnd = GetParent(hWnd);
			ti.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
			ti.uId = (UINT_PTR)hWnd;
			ti.lpszText = tiptext;
			SendMessage(hTip, TTM_ADDTOOL, 0, (LPARAM)&ti);
		}
	}
}

BOOL Button::create(LPCSTR _windowName, DWORD _style, int _x, int _y, int _width, int _height, HWND _parent, UINT _rcId)
{
	hWnd = CreateWindowEx(NULL, /*WC_BUTTON*/"BUTTON", _windowName, WS_TABSTOP | WS_VISIBLE | WS_CHILD | _style, _x, _y, _width, _height, _parent, (HMENU)_rcId, GetModuleHandle(NULL), NULL);
	if(hWnd)
	{
		return(TRUE);
	}
	return(FALSE);
}

void Button::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
{
	//switch (_oc)
	//{
	//	default:
	//	{
			Wnd::proc(_oc, _wParam, _lParam);
	//		break;
	//	}
	//}
}
