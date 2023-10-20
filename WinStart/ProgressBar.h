#ifndef PROGRESS_BAR
#define PROGRESS_BAR

#include "Wnd.h"
#include <CommCtrl.h>

class ProgressBar : public Wnd
{
public:
	ProgressBar();
	ProgressBar(String _id);
	ProgressBar(const ProgressBar& _cpy);

	ProgressBar& operator= (const ProgressBar& _rhs);

	virtual BOOL create(LPCSTR _windowName, DWORD _style, int _x, int _y, int _width, int _height, HWND _hParent);

	void setProgress(int _percent);
	void addProgress(int _progress);
	void reset();

	//virtual List<Message*> update(int _delta);

};

#endif
