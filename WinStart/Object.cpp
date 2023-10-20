#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Object.h"

int Object::count = 0;

Object::Object()
{
	type = "Object";
	id = type + count;
	time = 0;
	delta = 0;
	sp = 0;
	status = 0;
	left = right = acc = 0;

	count++;
}

Object::Object(const String _id)
{
	type = "Object";
	id = _id;
	time = 0;
	delta = 0;
	sp = 0;
	status = 0;
	left = right = acc = 0;
	count++;
}

Object::Object(const Object& _cpy)
{
	type = _cpy.type;
	id = _cpy.id;
	time = _cpy.time;
	delta = _cpy.delta;
	sp = _cpy.sp;
	status = _cpy.status;
	left = _cpy.left;
	right = _cpy.right;
	acc = _cpy.acc;

	inbox = _cpy.inbox;
	outbox = _cpy.outbox;
	subs = _cpy.subs;
	count++;
}

Object& Object::operator=(const Object& _rhs)
{
	if (this == &_rhs)
	{
		return(*this);
	}
	type = _rhs.type;
	id = _rhs.id;
	time = _rhs.time;
	delta = _rhs.delta;
	sp = _rhs.sp;
	status = _rhs.status;
	left = _rhs.left;
	right = _rhs.right;
	acc = _rhs.acc;

	inbox = _rhs.inbox;
	outbox = _rhs.outbox;
	subs = _rhs.subs;
	return(*this);
}

void Object::sendMessage(Message* _msg)
{
	inbox.push(_msg);
}

void Object::sendMessage(unsigned int _oc, XPARAM _wParam, YPARAM _lParam, const String& _target)
{
	Message* msg = new Message(_oc, _wParam, _lParam, _target);
	inbox.push(msg);
}

List<Message*> Object::update(int _delta)
{
	delta = _delta;
	time += delta;

	outbox.clear();
	// clear previous update's outbox
	//while (outbox.getLength())
	//{
	//	delete(outbox.remove());
	//}

	subs.reset();	// To do: Figure out what's not resetting this list!
	for (int x = 0; x < subs.getLength(); x++)
	{
		inbox.append(subs.get()->update(_delta));
		subs.next();
	}
	subs.reset();

	pump();
	return(outbox);
}

String Object::getType()
{
	return(type);
}

String Object::getId()
{
	return(id);
}

int Object::getTime()
{
	return(time);
}

int Object::setType(String _type)
{
	type = _type;
	return(0);
}

int Object::setId(String _id)
{
	id = _id;
	return(0);
}

/**
* Checks this object, it's children, and their decendants
* to see if _id is a ditinct identiufier
**/
int Object::distinctionCheck(const String& _id)
{
	int c = 0;
	if (id == _id)
	{
		c++;
	}
	for (int x = 0; x < subs.getLength(); x++)
	{
		c += subs.get()->distinctionCheck(_id);
		subs.next();
	}
	subs.reset();
	return(c);
}

/**
* Checks this object and it's children to see if _id is a ditinct identifier
**/
int Object::localDistinctionCheck(const String& _id)
{
	int c = 0;
	if (id == _id)
	{
		c++;
	}
	for (int x = 0; x < subs.getLength(); x++)
	{
		if (subs.get()->getId() == _id)
		{
			c++;
		}
		subs.next();
	}
	subs.reset();
	return(c);
}

int Object::addSubObject(Object* _o)
{
	return(subs.add(_o));
}

unsigned int Object::getStatus()
{
	return(status);
}

Object::~Object()
{
	subs.clear();
}

void Object::pump()
{
	Message* m;
	String target, newtarget;
	inbox.reset();
	while (sp < inbox.getLength())
	{
		if (inbox.get(sp)->getProcOption() & MSG_ONPRC_REMOVE)
		{
			m = inbox.remove(sp);
		}
		else
		{
			m = inbox.get(sp);
			inbox.next();
		}

		target = m->getTarget();
		newtarget = target.snip('/');
		//temp = m->getSource();


		if (target == "")										// This is the target
		{
			proc(m->getCode(), m->getWParam(), m->getLParam());
		}
		else if (target == "@")									// Target is all children
		{
			for (int x = 0; x < subs.getLength(); x++)
			{
				(subs.get())->sendMessage(m->getCode(), m->getWParam(), m->getLParam(), newtarget);
				//(*subs.pointTo())->sendMessage(m->getCode(), m->getWParam(), m->getLParam(), newtarget);
				subs.next();
			}
			subs.reset();
		}
		else if (target == ">")									// pre process here, then all children
		{
			proc(m->getCode(), m->getWParam(), m->getLParam());
			for (int x = 0; x < subs.getLength(); x++)
			{
				(subs.get())->sendMessage(m->getCode(), m->getWParam(), m->getLParam(), newtarget);
				//(*subs.pointTo())->sendMessage(m->getCode(), m->getWParam(), m->getLParam(), newtarget);
				subs.next();
			}
			subs.reset();
		}
		else if (target == "<")									// process all children, then this object
		{
			for (int x = 0; x < subs.getLength(); x++)
			{
				(subs.get())->sendMessage(m->getCode(), m->getWParam(), m->getLParam(), newtarget);
				//(*subs.pointTo())->sendMessage(m->getCode(), m->getWParam(), m->getLParam(), newtarget);
				subs.next();
			}
			subs.reset();
			proc(m->getCode(), m->getWParam(), m->getLParam());
		}
		else													// send the message to a specific child
		{
			for (int x = 0; x < subs.getLength(); x++)
			{
				if (subs.isSelected() && (subs.get())->getId() == target)
				{
					(subs.get())->sendMessage(m->getCode(), m->getWParam(), m->getLParam(), newtarget);
				}
				/*if ((*subs.pointTo())->getId() == target)
				{
					(*subs.pointTo())->sendMessage(m->getCode(), m->getWParam(), m->getLParam(), newtarget);
				}*/
				subs.next();
			}
			subs.reset();
		}
		sp++;
	}
	sp = 0;
}

void Object::proc(unsigned int _oc, XPARAM _wParam, YPARAM _lParam)
{
	switch (_oc)
	{
	case LDA:
	{
		acc = _lParam;
		break;
	}

	case  LDL:
	{
		left = _lParam;
		break;
	}

	case  LDR:
	{
		right = _lParam;
		break;
	}

	case  TAL:
	{
		left = acc;
		break;
	}

	case  TAR:
	{
		right = acc;
		break;
	}

	case  TSL:
	{
		left = sp;
		break;
	}

	case  TLA:
	{
		acc = left;
		break;
	}

	case  TLS:
	{
		sp = left;
		break;
	}

	case  TRA:
	{
		acc = right;
		break;
	}

	case  SWP:
	{
		_lParam = left;
		left = right;
		right = _lParam;
		break;
	}

	case  ADD:
	{
		acc = left + right;
		break;
	}

	case  SUB:
	{
		acc = left - right;
		break;
	}

	case  MUL:
	{
		acc = left * right;
		break;
	}

	case  DIV:
	{
		acc = left / right;
		break;
	}

	case JPL:
	{
		if (acc < _lParam)
		{
			sp += _wParam;
		}
		break;
	}

	case JPG:
	{
		if (acc > _lParam)
		{
			sp += _wParam;
		}
		break;
	}

	case JEQ:
	{
		if (acc == _lParam)
		{
			sp += _wParam;
		}
		break;
	}

	case JEZ:
	{
		if (!acc)
		{
			sp += _wParam;
		}
		break;
	}

	case JNZ:
	{
		if (acc)
		{
			sp += _wParam;
		}
		break;
	}

	case KIL:
	{
		for (int x = 0; x < subs.getLength(); x++)
		{
			if (subs.get(x)->getId() == *(String*)_wParam)
			{
				delete(subs.remove(x));
				x += subs.getLength() + 1;
			}
		}
		break;
	}

	default:
	{
		outbox.add(new Message(-1, 0, 0, ""));
		break;
	}
	}
}
