#include "Wnd.h"


Wnd::Wnd() : Object()
{
	type = "OSHandle";
	id = type + count;
	hWnd = (HWND)0;
}

Wnd::Wnd(String _id) : Object(_id)
{
	type = "OSHandle";
	hWnd = (HWND)0;
}

Wnd::Wnd(const Wnd& _cpy) : Object((Object) _cpy)
{
	hWnd = _cpy.hWnd;
}

Wnd& Wnd::operator = (const Wnd& _rhs)
{
	if (this == &_rhs)
	{
		return(*this);
	}
	//hWnd = (HWND)0;
	hWnd = _rhs.hWnd;
	return(*this);
}

BOOL Wnd::create(LPCSTR _className, LPCSTR _windowName, DWORD _style, int _x, int _y, int _width, int _height, HWND _parent, HMENU _menu)
{
	hWnd = CreateWindowEx(NULL, _className, _windowName, _style, _x, _y, _width, _height, _parent, _menu, GetModuleHandle(NULL), (LPVOID)this);
	if (hWnd)
	{
		return(true);
	}
	return(false);
}

BOOL Wnd::show(DWORD _time, DWORD _flag)
{
	if (!IsWindowVisible(hWnd))
	{
		return(AnimateWindow(hWnd, _time, _flag));
	}
	return(AnimateWindow(hWnd, _time, _flag | AW_HIDE));
}

BOOL Wnd::hide(bool _sw)
{
	BOOL x;
	if (_sw)
	{
		x=AnimateWindow(hWnd, 20, AW_CENTER | AW_ACTIVATE);

	}
	else
	{
		x = AnimateWindow(hWnd, 20, AW_CENTER | AW_HIDE);
	}
	return(x);
}

void Wnd::setWindowText(String _s)
{
	if (hWnd)
	{
		char s[256];
		_s.get(s);
		SetWindowText(hWnd, s);
	}
}

HWND Wnd::grab()
{
	return(hWnd);
}

void Wnd::onCommand(UINT _com) {}
void Wnd::onLButtonDown(float _x, float _y) {}
void Wnd::onLButtonUp(float _x, float _y) {}
void Wnd::onRButtonDown(float _x, float _y) {}
void Wnd::onRButtonUp(float _x, float _y) {}
void Wnd::onMButtonDown(float _x, float _y) {}
void Wnd::onMButtonUp(float _x, float _y) {}
void Wnd::onWheelDown() {}
void Wnd::onWheelUp() {}
void Wnd::onMouseOut() {}
//void Wnd::onMouseIn() {}
void Wnd::onMouseMove(float _x, float _y) {}
void Wnd::onKeyDown(DWORD _k) {}
void Wnd::onKeyUp(DWORD _k) {}
void Wnd::onPaint() {}
void Wnd::onClose() {}
void Wnd::onFocus() {}
void Wnd::onBlur() {}

Wnd::~Wnd()
{
	hWnd = (HWND)0;
}

void Wnd::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
{
	switch (_oc)
	{
		case LBD:
		{
			onLButtonDown((float)_wParam, (float)_lParam);
			break;
		}

		case LBU:
		{
			onLButtonUp((float)_wParam, (float)_lParam);
			break;
		}

		case RBD:
		{
			onRButtonDown((float)_wParam, (float)_lParam);
			break;
		}

		case RBU:
		{
			onRButtonUp((float)_wParam, (float)_lParam);
			break;
		}

		case MBD:
		{
			onMButtonDown((float)_wParam, (float)_lParam);
			break;
		}

		case MBU:
		{
			onMButtonUp((float)_wParam, (float)_lParam);
			break;
		}

		case WHU:
		{
			onWheelUp();
			break;
		}

		case WHD:
		{
			onWheelDown();
			break;
		}

		case MSO:		//onMouseOut() {}
		{
			onMouseOut();
			break;
		}

		//case MSI:		//onMouseIn() {}
		//{
		//	onMouseIn();
		//	break;
		//}
		case MSM:		//onMouseMove(float _x, float _y) {}
		{
			onMouseMove((float)_wParam, (float)_lParam);
			break;
		}

		case OKD:		//onKeyDown(DWORD _k) {}
		{
			onKeyDown(_lParam);
			break;
		}
		case OKU:		//onKeyUp(DWORD _k) {}
		{
			onKeyUp(_lParam);
			break;
		}
		case WDP:		//onPaint() {}
		{
			onPaint();
			break;
		}
		case WCL:		//onClose() {}
		{
			onClose();
			break;
		}
		case WFO:		//onFocus() {}
		{
			onFocus();
			break;
		}
		case WBL:		//onBlur() {}
		{
			onBlur();
			break;
		}

		case CMD:
		{
			onCommand(_wParam);
			break;
		}

		case SWT:
		{
			setWindowText(*(String*)_wParam);
			break;
		}

		default:
		{
			Object::proc(_oc, _wParam, _lParam);
			break;
		}
	}
}
