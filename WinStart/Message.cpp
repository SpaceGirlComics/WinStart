#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Message.h"
//#include <string.h>

Message::Message()
{
	onProc = MSG_ONPRC_REMOVE;
	target = "";
	source = "";
}

Message::Message(unsigned int _opcode, XPARAM _wParam, YPARAM _lParam, const String& _target)
{
	source = "";
	opcode = _opcode;
	wParam = _wParam;
	lParam = _lParam;
	target = _target;
	onProc = MSG_ONPRC_REMOVE;
}

Message::Message(const Message& _cpy)
{
	source = "";
	opcode = _cpy.opcode;
	wParam = _cpy.wParam;
	lParam = _cpy.lParam;
	target = _cpy.target;
	onProc = _cpy.onProc;
}

unsigned int Message::getCode()
{
	return(opcode);
}

int Message::getWParam()
{
	return(wParam);
}

long Message::getLParam()
{
	return(lParam);
}

int Message::getProcOption()
{
	return(onProc);
}

void Message::setCode(unsigned int _opcode)
{
	opcode = _opcode;
}

void Message::setWParam(XPARAM _wParam)
{
	wParam = _wParam;
}

void Message::setLParam(YPARAM _lParam)
{
	lParam = _lParam;
}

void Message::setProcOption(int _onProc)
{
	onProc = _onProc;
}

String Message::getTarget()
{
	return(target);
}

void Message::clipTarget()
{
	target.snip('/');
}

String Message::getSource()
{
	return(source);
}

void Message::appendSource(String& _id)
{
	if (source.getLength())
	{
		source.splice(0, 0, "/");
		source.splice(0, 0, _id);
	}
	else
	{
		source = _id;
	}
}

Message& Message::operator = (const Message& _cpy)
{
	if (this == &_cpy)
	{
		return(*this);
	}

	opcode = _cpy.opcode;
	wParam = _cpy.wParam;
	lParam = _cpy.lParam;
	target = _cpy.target;
	return(*this);
}

Message::~Message()
{

}
