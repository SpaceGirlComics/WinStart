#ifndef EDIT_H
#define EDIT_H

//#include "Wnd.h"
#include "Label.h"

class Edit : public Wnd
{
public:
	Edit();
	Edit(String _id);
	Edit(const Edit& _cpy);

	//void update(int _time);
	virtual List<Message*> update(int _time);

	String getText();
	String setText(String _text);

	/*String getPlaceholder();
	String setPlaceholder(String _ph);*/

	Edit& operator=(const Edit& _rhs);

	BOOL create(int _x, int _y, int _w, int _h, HWND _parent);
	BOOL create(int _x, int _y, int _w, int _h, HWND _parent, UINT _rcId);

	/*	virtual void onPaint();*/
	virtual void onFocus();
	virtual void onBlur();

	void setPlaceholder(String _pl);

	~Edit();
protected:
	/*String placeholder;*/
	Label placeholder;
	int pldisplay;

	void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);
};

#endif
