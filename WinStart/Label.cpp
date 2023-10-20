#include "Label.h"

Label::Label() : Wnd()
{
	type = "Label";
	id = type + count;
}

Label::Label(String _id) : Wnd(_id)
{
	type = "Label";
}

Label::Label(const Label& _cpy) : Wnd(_cpy)
{
	if (_cpy.hWnd)
	{
		char t[255];
		RECT r;
		GetWindowRect(_cpy.hWnd, &r);
		GetWindowText(_cpy.hWnd, t, 255);
		create(t, r.left, r.top, GetParent(_cpy.hWnd));
		if (!IsWindowVisible(_cpy.hWnd))
		{
			show(0);
		}
	}
	else
	{
		hWnd = (HWND)0;
	}
}

Label& Label::operator=(const Label& _rhs)
{
	if (&_rhs == this)
	{
		return(*this);
	}
	if (_rhs.hWnd)
	{
		if (hWnd)
		{
			DestroyWindow(hWnd);
		}
		char t[255];
		RECT r;
		GetWindowRect(_rhs.hWnd, &r);
		GetWindowText(_rhs.hWnd, t, 255);
		create(t, r.left, r.top, GetParent(_rhs.hWnd));

		if (!IsWindowVisible(_rhs.hWnd))
		{
			show(0);
		}
	}
	else
	{
		hWnd = (HWND)0;
	}
	return(*this);
}

String Label::get()
{
	char buff[256];
	GetWindowText(hWnd, buff, 255);
	return(buff);
}

void Label::setFont(String _fontName)
{
	char fnt[256];
	_fontName.get(fnt);
	HFONT font = CreateFont(15, 0, 0, 0, FW_NORMAL, TRUE, FALSE, FALSE,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_MODERN, fnt);
	if (font)
	{
		SendMessage(hWnd, WM_SETFONT, (WPARAM)font, 0x00000001);
	}
}

BOOL Label::create(LPCSTR _text, int _x, int _y, HWND _parent)
{
	hWnd = CreateWindowEx(NULL, "STATIC", _text, WS_CHILD | WS_VISIBLE, _x, _y, 100, 17, _parent, NULL, GetModuleHandle(NULL), NULL);
	if (hWnd)
	{
		return(TRUE);
	}
	return(FALSE);
}

void Label::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
{
	switch (_oc)
	{
		case FNT:
		{
			setFont(*(String*)_wParam);
			break;
		}

		default:
		{
			Wnd::proc(_oc, _wParam, _lParam);
			break;
		}
	}
}
