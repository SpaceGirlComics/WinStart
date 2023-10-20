/**
*
* @
* @author Chris Turner
* @version 0.1.5.5.2020
* @since 0.1.5.5.2020
*/

#ifndef BOX_H
#define BOX_H


#include "Point.h"

class Box : public Object
{
public:
	Box();
	Box(const String& _id);
	Box(const Box& _cpy);

	//virtual void update(int _time);
	virtual List<Message*> update(int _time);

	Box& operator = (const Box& _rhs);

	void translate(float _x, float _y);
	void reposition(float _x, float _y);
	void scale(float _x);
	void resize(float _x, float _y);
	void relativeResize(float _x, float _y);

	float getWidth();
	float getHeight();
	float getX();
	float getY();

	void getDimensions(float* _x, float* _y);
	void getPosition(float* _x, float* _y);
	Point getDimensions();
	Point getPosition();

	~Box();

protected:
	Point position;
	Point dimensions;
};
#endif
