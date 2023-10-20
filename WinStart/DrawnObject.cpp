#include "DrawnObject.h"

DrawnObject::DrawnObject() : Object()
{
	type = "DrawnObject";
	angle = x = y = 0;
}

DrawnObject::DrawnObject(const String& _id) : Object(_id)
{
	type = "DrawnObject";
	angle = x = y = 0;
}

DrawnObject::DrawnObject(const DrawnObject& _cpy) : Object((Object&)_cpy)
{
	type = _cpy.type;
	x = _cpy.x;
	y = _cpy.y;
	angle = _cpy.angle;
}

int DrawnObject::draw()
{
	return(0);
}

int DrawnObject::getx()
{
	return(x);
}

int DrawnObject::gety()
{
	return(y);
}

int DrawnObject::getAngle()
{
	return(angle);
}

void DrawnObject::setx(int _x)
{
	x = _x;
}

void DrawnObject::sety(int _y)
{
	y = _y;
}

void DrawnObject::setAngle(int _a)
{
	angle = _a;
}

void DrawnObject::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
{
	switch (_oc)
	{
		case STX:		// Set X
		{
			setx(_lParam);
			break;
		}

		case STY:		// Set Y
		{
			sety(_lParam);
			break;
		}

		case STA:		// Set Angle
		{
			setAngle(_lParam);
			break;
		}

		default:
		{
			Object::proc(_oc, _wParam, _lParam);
		}
	}
}

DrawnObject::~DrawnObject()
{

}
