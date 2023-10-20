#include "Frame.h"


Frame::Frame() : Wnd()
{
}

Frame::Frame(String _id) : Wnd(_id)
{
}

Frame::Frame(const Frame& _cpy) : Wnd((Wnd&)_cpy)
{
}

BOOL Frame::create(LPCSTR _windowName, DWORD _style, int _x, int _y, int _width, int _height, HWND _parent, HMENU _menu, DWORD _exStyle)
{
	Wnd::create("wcFrame", _windowName, _style, _x, _y, _width, _height, _parent, _menu);
	if (hWnd)
	{
		return(TRUE);
	}
	return(FALSE);
}

void Frame::modalize()
{
}

void Frame::demodalize()
{
}

/*List<Message*> Frame::update(int _delta)
{
	return(Wnd::update(_delta));
}*/

BOOL Frame::moveTo(int _x, int _y)
{
	return(MoveToEx(dc, _x, _y, NULL));
}

BOOL Frame::lineTo(int _x, int _y)
{
	return(LineTo(dc, _x, _y));
}

void Frame::text(char* _s, int _x, int _y)
{
	if (dc)
	{
		RECT r;
		r.top = _y;
		r.left = _x;
		r.bottom = 26;
		r.right = 200;
		TextOut(dc, _x, _y, _s, strlen(_s));
	}
}

Frame::~Frame()
{
}

void Frame::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
{
	switch (_oc)
	{
		case MDZ:						// Make Frame Modal
		{
			modalize();
			break;
		}
		case MDS:						// Make Frame Modeless
		{
			demodalize();
			break;
		}
		case 0:
		{
			SetWindowText(hWnd, (char*)_lParam);
			break;
		}

		case 1:
		{
			MoveWindow(hWnd, 0, 0, _wParam, _lParam, TRUE);
			break;
		}

		case 2:
		{
			AnimateWindow(hWnd, _wParam, _lParam);
			break;
		}

		case 3:
		{
			create("Win");
			break;
		}

		default:
		{
			Wnd::proc(_oc, _wParam, _lParam);
			break;
		}
	}
}
