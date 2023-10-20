#include "ListBox.h"

ListBox::ListBox() : Wnd()
{
	type = "ListBox";
	id = type + count;
}

ListBox::ListBox(String _id) : Wnd(_id)
{
	type = "ListBox";
}

ListBox::ListBox(const ListBox& _cpy) : Wnd(_cpy)
{
	if (_cpy.hWnd)
	{
		RECT rect;
		GetWindowRect(_cpy.hWnd, &rect);
		create(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, GetParent(_cpy.hWnd));

		int x = 0;
		while (int s = (int)SendMessage(_cpy.hWnd, LB_GETTEXTLEN, x, NULL) != LB_ERR)
		{
			String b;
			char* c = new char[++s];
			SendMessage(_cpy.hWnd, LB_GETTEXT, x++, (LPARAM)c);
			add(c);
			delete[] c;
		}
		if (!IsWindowVisible(_cpy.hWnd))
		{
			show(0);
		}
	}
}

ListBox& ListBox::operator=(const ListBox& _rhs)
{
	if (this == &_rhs)
	{
		return(*this);
	}
	if (_rhs.hWnd)
	{
		if (hWnd)
		{
			DestroyWindow(hWnd);
		}
		RECT rect;
		GetWindowRect(_rhs.hWnd, &rect);
		create(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, GetParent(_rhs.hWnd));

		int x = 0;
		while (int s = (int)SendMessage(_rhs.hWnd, LB_GETTEXTLEN, x, NULL) != LB_ERR)
		{
			String b;
			char* c = new char[++s];
			SendMessage(_rhs.hWnd, LB_GETTEXT, x++, (LPARAM)c);
			add(c);
			delete[] c;
		}
		if (!IsWindowVisible(_rhs.hWnd))
		{
			show(0);
		}
	}
	return(*this);
}

void ListBox::setSelection(int _i)
{
	SendMessage(hWnd, LB_SETCURSEL, _i, 0);
}

void ListBox::unshift(String _i)
{
	char* s;
	_i.get(&s);
	SendMessage(hWnd, LB_INSERTSTRING, 0, (LPARAM)s);
	delete[] s;
}

void ListBox::add(String _i)
{
	char* c;
	int s = (int)SendMessage(hWnd, LB_GETCURSEL, NULL, NULL);
	if (s != LB_ERR)
	{
		//MessageBox(NULL, "hi", "po", MB_OK);
		_i.get(&c);
		SendMessage(hWnd, LB_INSERTSTRING, s, (LPARAM)c);
		delete[] c;
	}
	else
	{
		push(_i);
	}
}

void ListBox::insert(String _i)
{
	char* c;
	int s = (int)SendMessage(hWnd, LB_GETCURSEL, NULL, NULL);
	if (s != LB_ERR)
	{
		//MessageBox(NULL, "hi", "po", MB_OK);
		_i.get(&c);
		SendMessage(hWnd, LB_INSERTSTRING, ++s, (LPARAM)c);
		delete[] c;
	}
	else
	{
		push(_i);
	}
}

void ListBox::push(String _i)
{
	char* s;
	_i.get(&s);
	SendMessage(hWnd, LB_ADDSTRING, NULL, (LPARAM)s);
	delete[] s;
}

String ListBox::shift()
{
	return(remove(0));
}

String ListBox::remove()
{
	int s = (int)SendMessage(hWnd, LB_GETCURSEL, NULL, NULL);
	return(remove(s));
}

String ListBox::remove(int _i)
{
	int s = (int)SendMessage(hWnd, LB_GETTEXTLEN, _i, NULL);
	String b;
	if (s != LB_ERR)
	{
		char* c = new char[++s];
		SendMessage(hWnd, LB_GETTEXT, _i, (LPARAM)c);
		SendMessage(hWnd, LB_DELETESTRING, _i, NULL);
		b = c;
		delete[] c;
	}
	return(b);
}

String ListBox::pop()
{
	int s = (int)SendMessage(hWnd, LB_GETCOUNT, NULL, NULL);
	return(remove(--s));
}

String ListBox::get()
{
	int s = (int)SendMessage(hWnd, LB_GETCURSEL, NULL, NULL);
	return(get(s));
}

String ListBox::get(int _i)
{
	int s = (int)SendMessage(hWnd, LB_GETTEXTLEN, _i, NULL);
	String b;
	if (s != LB_ERR)
	{
		char* c = new char[++s];
		SendMessage(hWnd, LB_GETTEXT, _i, (LPARAM)c);
		b = c;
		delete[] c;
	}
	return(b);
}

int ListBox::getSelectedIndex()
{
	return((int)SendMessage(hWnd, LB_GETCURSEL, NULL, NULL));
}

int ListBox::getCount()
{
	return((int)SendMessage(hWnd, LB_GETCOUNT, NULL, NULL));
}

void ListBox::raiseSelected()
{
	int index = getSelectedIndex();
	int s = (int)SendMessage(hWnd, LB_GETTEXTLEN, index, NULL);
	String b;
	if (s != LB_ERR && index >0)
	{
		char* c = new char[++s];
		SendMessage(hWnd, LB_GETTEXT, index, (LPARAM)c);
		SendMessage(hWnd, LB_DELETESTRING, index, NULL); 
		SendMessage(hWnd, LB_INSERTSTRING, index - 1, (LPARAM)c);
		delete[] c;
	}
}

void ListBox::lowerSelected()
{
	int count = getCount()-1;
	int index = getSelectedIndex();
	int s = (int)SendMessage(hWnd, LB_GETTEXTLEN, index, NULL);
	String b;
	if (s != LB_ERR && index < count)
	{
		char* c = new char[++s];
		SendMessage(hWnd, LB_GETTEXT, index, (LPARAM)c);
		SendMessage(hWnd, LB_DELETESTRING, index, NULL);
		SendMessage(hWnd, LB_INSERTSTRING, index+1, (LPARAM)c);
		delete[] c;
	}
}

BOOL ListBox::create(int _x, int _y, int _width, int _height, HWND _parent)
{
	hWnd = CreateWindowEx(NULL, "LISTBOX", NULL, WS_CHILD | WS_VISIBLE | LBS_STANDARD, _x, _y, _width, _height, _parent, NULL, GetModuleHandle(NULL), NULL);
	if (hWnd)
	{
		return(TRUE);
	}
	return(FALSE);
}

ListBox::~ListBox()
{

}

void ListBox::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
{
	switch (_oc)
	{
		case SSL:
		{
			setSelection(_lParam);
			break;
		}

		case USL:
		{
			unshift(*(String*)_wParam);
			break;
		}

		case ADS:
		{
			add(*(String*)_wParam);
			break;
		}

		case INS:
		{
			insert(*(String*)_wParam);
			break;
		}

		case PSH:
		{
			push(*(String*)_wParam);
			break;
		}

		case SFT:
		{
			shift();
			break;
		}

		case REM:
		{
			remove();
			break;
		}

		case RMI:
		{
			remove(_lParam);
			break;
		}

		case POP:
		{
			pop();
			break;
		}

		case RAS:
		{
			raiseSelected();
			break;
		}

		case LWS:
		{
			lowerSelected();
			break;
		}

		default:
		{
			Wnd::proc(_oc, _wParam, _lParam);
			break;
		}
	}
}
