#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "String.h"
#include <stdio.h>
#include <string.h>

#define CHAR_STRING_LIMIT 2
#define SHORT_STRING_LIMIT 7
#define INT_STRING_LIMIT 12
#define LONG_STRING_LIMIT 12
#define FLOAT_STRING_LIMIT 50
#define DOUBLE_STRING_LIMIT 320
#define UCHAR_STRING_LIMIT 2
#define USHORT_STRING_LIMIT 6
#define UINT_STRING_LIMIT 11
#define ULONG_STRING_LIMIT 11
#define ULONGLONG_STRING_LIMIT 21
#define LONGLONG_STRING_LIMIT 20
#define LONGDOUBLE_STRING_LIMIT 500
#define BOOL_STRING_LIMIT 6

/**
*	Std. Constructor
*	Contained string is null, size and length are set to zero
*/
String::String()
{
	s = (char*)0;
	length = size = 0;
}

/**
*	Initializing Ctor.
*	Creates a String object with a duplicate of _s
*	length is the length of _s (not including the terminal null)
*	the size is length + 1
*	@param _s pointer to a character array that will be copied to this object
*/
String::String(char* _s)
{
	if (_s)
	{
		size = strlen(_s) + 1;
		s = new char[size];
		strcpy(s, _s);
		length = size - 1;
	}
	else
	{
		s = (char*)0;
		length = size = 0;
	}
}

/**
*	Copy Ctor
*	creates a copy of _cpy. siz3e and length are the same as _cpy
*/
String::String(const String& _cpy)
{
	if (_cpy.s)
	{
		size = _cpy.size;
		length = _cpy.length;
		s = new char[size];
		strcpy(s, _cpy.s);
	}
	else
	{
		s = (char*)0;
		length = size = 0;
	}
}

String& String::operator = (const String& _rhs)
{
	if (&_rhs == this)
	{
		return(*this);
	}
	if (s)
	{
		delete(s);
	}
	if (_rhs.s)
	{
		length = _rhs.length;
		size = _rhs.size;
		s = new char[size];
		strcpy(s, _rhs.s);
	}
	else
	{
		s = (char*)0;
		length = size = 0;
	}
	return(*this);
}

String& String::operator = (const char* _rhs)
{
	if (s == _rhs)
	{
		return(*this);
	}
	if (s)
	{
		delete(s);
	}
	if (_rhs)
	{
		length = strlen(_rhs);
		size = length + 1;
		s = new char[size];
		strcpy(s, _rhs);
	}
	else
	{
		s = (char*)0;
		length = size = 0;
	}
	return(*this);
}

String& String::operator = (const char& _rhs)							// %c
{
	if (s)
	{
		delete(s);
	}
	size = CHAR_STRING_LIMIT;
	s = new char[size];
	s[0] = _rhs;
	s[1] = '\0';
	length = strlen(s);
	return(*this);
}

String& String::operator = (const short& _rhs)							// %hi
{
	if (s)
	{
		delete(s);
	}
	size = SHORT_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%hi", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const int& _rhs)							// %d
{
	if (s)
	{
		delete(s);
	}
	size = INT_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%d", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const long& _rhs)							// %li
{
	if (s)
	{
		delete(s);
	}
	size = LONG_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%d", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const float& _rhs)							// %f
{
	if (s)
	{
		delete(s);
	}
	size = FLOAT_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%f", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const double& _rhs)						// %lf
{
	if (s)
	{
		delete(s);
	}
	size = DOUBLE_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%lf", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const unsigned char& _rhs)					// %c
{
	if (s)
	{
		delete(s);
	}
	size = UCHAR_STRING_LIMIT;
	s = new char[size];
	s[0] = _rhs;
	s[1] = '\0';
	length = strlen(s);
	return(*this);
}

String& String::operator = (const unsigned short& _rhs)				// %hu
{
	if (s)
	{
		delete(s);
	}
	size = USHORT_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%hu", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const unsigned int& _rhs)					// %u
{
	if (s)
	{
		delete(s);
	}
	size = UINT_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%u", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const unsigned long& _rhs) 				// %u
{
	if (s)
	{
		delete(s);
	}
	size = ULONG_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%u", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const unsigned long long& _rhs)			// %llu
{
	if (s)
	{
		delete(s);
	}
	size = ULONGLONG_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%llu", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const long long& _rhs)						// %lli
{
	if (s)
	{
		delete(s);
	}
	size = LONGLONG_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%lli", _rhs);
	length = strlen(s);
	return(*this);
}
String& String::operator = (const long double& _rhs)					// %Lf
{
	if (s)
	{
		delete(s);
	}
	size = LONGDOUBLE_STRING_LIMIT;
	s = new char[size];
	sprintf(s, "%Lf", _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator = (const bool& _rhs)
{
	if (s)
	{
		delete(s);
	}
	size = BOOL_STRING_LIMIT;
	s = new char[size];
	if (_rhs)
	{
		strcpy(s, "true");
	}
	else
	{
		strcpy(s, "false");
	}
	return(*this);
}

String& String::operator += (const String& _rhs)
{
	if (&_rhs == this)
	{
		return(*this);
	}
	ensureCapacity(_rhs.length);
	strcat(s, _rhs.s);
	length = strlen(s);
	return(*this);
}

String& String::operator += (const char* _rhs)
{
	if (_rhs == s)
	{
		return(*this);
	}
	ensureCapacity(strlen(_rhs));
	strcat(s, _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator += (const char& _rhs)
{
	ensureCapacity(CHAR_STRING_LIMIT);
	sprintf(s, "%s%c", s, _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator += (const short& _rhs)
{
	ensureCapacity(SHORT_STRING_LIMIT);
	sprintf(s, "%s%hi", s, _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator += (const int& _rhs)
{
	ensureCapacity(INT_STRING_LIMIT);
	sprintf(s, "%s%d", s, _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator += (const long& _rhs)
{
	ensureCapacity(LONG_STRING_LIMIT);
	sprintf(s, "%s%d", s, _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator += (const float& _rhs)
{
	ensureCapacity(FLOAT_STRING_LIMIT);
	sprintf(s, "%s%f", s, _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator += (const double& _rhs)
{
	ensureCapacity(DOUBLE_STRING_LIMIT);
	sprintf(s, "%s%lf", s, _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator += (const unsigned char& _rhs)
{
	ensureCapacity(UCHAR_STRING_LIMIT);
	sprintf(s, "%s%c", s, _rhs);
	length = strlen(s);
	return(*this);
}

String& String::operator += (const unsigned short& _rhs)
{
	ensureCapacity(USHORT_STRING_LIMIT);
	sprintf(s, "%s%hu", s, _rhs);
	length = strlen(