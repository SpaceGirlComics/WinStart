#include "Box.h"

Box::Box() : Object()
{
	type = "Box";
	id = type;
	id += count;
	position.setId("Position");
	dimensions.setId("Dimensions");

	Point* temp = new Point("Position");
	Point* temp2 = new Point("Dimensions");

	subs.add(temp);
	subs.add(temp2);

	sendMessage(LDA, 0, 10, "Position");
}

Box::Box(const String& _id) : Object(_id)
{
	type = "Box";
	position.setId("Position");
	dimensions.setId("Dimensions");

	Point* temp = new Point("Position");
	Point* temp2 = new Point("Dimensions");

	subs.add(temp);
	subs.add(temp2);
}

Box::Box(const Box& _cpy) : Object((Object&)_cpy)
{
	position.setId("Position");
	dimensions.setId("Dimensions");
	position = _cpy.position;
	dimensions = _cpy.dimensions;
}

//void Box::update(int _time)
List<Message*> Box::update(int _time)
{
	return(Object::update(_time));
}

Box& Box::operator = (const Box & _rhs)
{
	if (&_rhs == this)
	{
		return(*this);
	}
	position = _rhs.position;
	dimensions = _rhs.dimensions;
	return(*this);
}

void Box::translate(float _x, float _y)
{
	position.translate(_x, _y);
}

void Box::reposition(float _x, float _y)
{
	position.setPosition(_x, _y);
}

void Box::scale(float _x)
{
	dimensions.setScale(_x);
	position.setScale(_x);
}

void Box::resize(float _x, float _y)
{
	dimensions.setPosition(_x, _y);
}

void Box::relativeResize(float _x, float _y)
{
	dimensions.translate(_x, _y);
}

float Box::getWidth()
{
	return(dimensions.getX());
}

float Box::getHeight()
{
	return(dimensions.getY());
}

float Box::getX()
{
	return(position.getX());
}

float Box::getY()
{
	return(position.getY());
}

void Box::getDimensions(float* _x, float* _y)
{
	*_x = dimensions.getX();
	*_y = dimensions.getY();
}

void Box::getPosition(float* _x, float* _y)
{
	*_x = position.getX();
	*_y = position.getY();
}

Point Box::getDimensions()
{
	return(dimensions);
}

Point Box::getPosition()
{
	return(position);
}

Box::~Box()
{

}
