#include "Edit.h"

Edit::Edit() : Wnd()
{
	type = "Edit";
	id = type + count;
}

Edit::Edit(String _id) : Wnd(_id)
{
	type = "Edit";
}

Edit::Edit(const Edit& _cpy) : Wnd(_cpy)
{
	char t[250];
	GetWindowText(_cpy.hWnd, t, 249);
	SetWindowText(hWnd, t);
}

//void Edit::update(int _time)
List<Message*> Edit::update(int _time)
{
	return(Wnd::update(_time));
	/*for (int x = 0; x < subs.getLength(); x++)
	{
		(*subs.pointTo())->update(_time);
		subs.next();
	}
	subs.reset();*/
}

String Edit::getText()
{
	int tLength = GetWindowTextLength(hWnd);
	if (tLength)
	{
		char* txt = new char[tLength + 1];
		GetWindowText(hWnd, txt, tLength+1);
		String ret;
		ret = txt;
		delete(txt);
		return(ret);
	}
	return("");
}

String Edit::setText(String _text)
{
	String old = getText();
	char* x;
	_text.get(&x);
	SetWindowText(hWnd, x);
	return(old);
}

Edit& Edit::operator=(const Edit& _rhs)
{
	if (this == &_rhs)
	{
		return(*this);
	}
	int tLength = GetWindowTextLength(hWnd);
	if (tLength)
	{
		char* txt = new char[tLength + 1];
		GetWindowText(_rhs.hWnd, txt, tLength + 1);
		SetWindowText(hWnd, txt);
		delete[](txt);
	}
	placeholder = _rhs.placeholder;
	return(*this);
}

BOOL Edit::create(int _x, int _y, int _w, int _h, HWND _parent)
{
	hWnd = CreateWindowEx(NULL, "EDIT", NULL, WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL, _x, _y, _w, _h, _parent, NULL, GetModuleHandle(NULL), NULL);
	if (hWnd)
	{
		placeholder.create("", 5, 2, hWnd);
		return(TRUE);
	}
	return(FALSE);
}

BOOL Edit::create(int _x, int _y, int _w, int _h, HWND _parent, UINT _rcId)
{
	hWnd = CreateWindowEx(NULL, "EDIT", NULL, WS_BORDER | WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL, _x, _y, _w, _h, _parent, (HMENU)_rcId, GetModuleHandle(NULL), NULL);
	if (hWnd)
	{
		placeholder.create("", 5, 2, hWnd);
		return(TRUE);
	}
	return(FALSE);
}

void Edit::onFocus()
{
	pldisplay = FALSE;
	placeholder.hide(false);
}

void Edit::onBlur()
{
	pldisplay = TRUE;
	//if (!placeholder.get().getLength())
	if(getText().getLength()==0)
	{
		placeholder.hide(true);
	}
}

void Edit::setPlaceholder(String _pl)
{
	placeholder.setWindowText(_pl);
}

Edit::~Edit()
{

}

void Edit::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
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
