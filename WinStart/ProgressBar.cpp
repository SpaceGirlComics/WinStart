#include "ProgressBar.h"

ProgressBar::ProgressBar() : Wnd()
{
	type = "ProgressBar";
	id = "ProgBar";
	id += count;
}

ProgressBar::ProgressBar(String _id) : Wnd(_id)
{
	type = "ProgressBar";
}

ProgressBar::ProgressBar(const ProgressBar& _cpy)
{
	
}

ProgressBar& ProgressBar::operator=(const ProgressBar& _rhs)
{
	return(*this);
}

BOOL ProgressBar::create(LPCSTR _windowName, DWORD _style, int _x, int _y, int _width, int _height, HWND _hParent)
{
	hWnd = CreateWindowEx(NULL, PROGRESS_CLASS, _windowName, WS_VISIBLE | WS_CHILD | PBS_SMOOTH, _x, _y, _width, _height, _hParent, NULL, GetModuleHandle(NULL), NULL);
	if (hWnd)
	{
		return(true);
	}
	return(false);
}

void ProgressBar::setProgress(int _percent)
{
	if (hWnd)
	{
		SendMessage(hWnd, PBM_SETPOS, _percent, NULL);
	}
}

void ProgressBar::addProgress(int _progress)
{
	if (hWnd)
	{
		SendMessage(hWnd, PBM_DELTAPOS, _progress, NULL);
	}
}

void ProgressBar::reset()
{
	if (hWnd)
	{
		SendMessage(hWnd, PBM_SETPOS, 0, NULL);
	}
}
