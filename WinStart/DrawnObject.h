/**
* Base class for ojects that are drawn on the screen.
*
* @
* @author Chris Turner
* @version 0.1.5.5.2020
* @since 0.1.5.5.2020
*/

#ifndef DRAWNOBJECT_H
#define DRAWNOBJECT_H

#include "Object.h"


class DrawnObject : public Object
{
public:
	DrawnObject();
	DrawnObject(const String& _id);
	DrawnObject(const DrawnObject& cpy);

	virtual int draw();

	int getx();
	int gety();
	int getAngle();

	void setx(int _x);
	void sety(int _y);
	void setAngle(int a);

	//virtual List<Message*> update(int _time);

	static const unsigned int STX = 0x0000001B;		// Set X
	static const unsigned int STY = 0x0000001C;		// Set Y
	static const unsigned int STA = 0x0000001D;		// Set Angle

	~DrawnObject();

protected:
	int x;
	int y;
	int angle;

	void proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam);
};
#endif
