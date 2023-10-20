#include "GroupBox.h"

GroupBox::GroupBox() : Wnd()
{
	type = "GroupBox";
	id = type + count;
}

GroupBox::GroupBox(String _id) : Wnd(_id)
{
	type = "GroupBox";
}

GroupBox::GroupBox(const GroupBox& _cpy) : Wnd(_cpy)
{

}

//void GroupBox::update(int _time)
List<Message*> GroupBox::update(int _time)
{
	return(Wnd::update(_time));
	/*for (int x = 0; x < subs.getLength(); x++)
	{
		(*subs.pointTo())->update(_time);
		subs.next();
	}
	subs.reset();*/
}

BOOL GroupBox::create(LPCSTR _windowName, int _x, int _y, int _width, int _height, HWND _parent)
{
	hWnd = CreateWindowEx(NULL, "BUTTON", _windowName, WS_CHILD | WS_VISIBLE | BS_GROUPBOX, _x, _y, _width, _height, _parent, NULL, GetModuleHandle(NULL), NULL);
	if (hWnd)
	{
		return(TRUE);
	}
	return(FALSE);
}

void GroupBox::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
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
