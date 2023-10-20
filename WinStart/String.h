#ifndef STRING_H
#define STRING_H

/**
* A simple String class
*
* @
* @author Chris Turner
* @version 0.1.5.5.2020
* @since 0.1.5.5.2020
* @see String.cpp
*/

#include <stdio.h>

class String
{
public:

	String();														/** Std. Constructor */
	String(char* _s);												/** Initializing Ctor. */
	String(const String& _cpy);									/** Copy Ctor */

	String& operator = (const String& _rhs);						/** Assignment Operator for other String objects */
	String& operator = (const char* _rhs);							/** Assignment Operator for strings */
	String& operator = (const char& _rhs);							/** Assignment Operator for chars */
	String& operator = (const short& _rhs);						/** Assignment Operator for shorts*/
	String& operator = (const int& _rhs);							/** Assignment Operator for integers*/
	String& operator = (const long& _rhs);							/** Assignment Operator for longs */
	String& operator = (const float& _rhs);						/** Assignment Operator for floats */
	String& operator = (const double& _rhs);						/** Assignment Operator for doubles */
	String& operator = (const unsigned char& _rhs);				/** Assignment Operator for unsigned chars*/
	String& operator = (const unsigned short& _rhs);				/** Assignment Operator for unsigned shorts */
	String& operator = (const unsigned int& _rhs);					/** Assignment Operator for unsigned integers*/
	String& operator = (const unsigned long& _rhs);				/** Assignment Operator for unsigned longs */
	String& operator = (const unsigned long long& _rhs);			/** Assignment Operator for unsingned long longs */
	String& operator = (const long long& _rhs);					/** Assignment Operator for long longs */
	String& operator = (const long double& _rhs);					/** Assignment Operator for long doubles */
	String& operator = (const bool& _rhs);							/** Assignment Operator for booleans */

	String& operator += (const String& _rhs);						/** Plus-Equals Op. for appending another String Object */
	String& operator += (const char* _rhs);							/** Plus-Equals Op. for appending a character array */
	String& operator += (const char& _rhs);						/** Plus-Equals Op. for appending a single character */
	String& operator += (const short& _rhs);						/** Plus-Equals Op. for appending a 2 byte "short" integer */
	String& operator += (const int& _rhs);							/** Plus-Equals Op. for appending a 4 byte integer */
	String& operator += (const long& _rhs);						/** Plus-Equals Op. for appending a 4 byte "long" */
	String& operator += (const float& _rhs);						/** Plus-Equals Op. for appending a 4 byte float */
	String& operator += (const double& _rhs);						/** Plus-Equals Op. for appending an 8 byte double */
	String& operator += (const unsigned char& _rhs);				/** Plus-Equals Op. for appending an unsigned single character */
	String& operator += (const unsigned short& _rhs);				/** Plus-Equals Op. for appending an unsigned 2 byte short */
	String& operator += (const unsigned int& _rhs);				/** Plus-Equals Op. for appending an unsigned 4 byte integer */
	String& operator += (const unsigned long& _rhs);				/** Plus-Equals Op. for appending an unsigned 4 byte long */
	String& operator += (const unsigned long long& _rhs);			/** Plus-Equals Op. for appending an unsigned 8 byte long long */
	String& operator += (const long long& _rhs);					/** Plus-Equals Op. for appending a 8 byte long long */
	String& operator += (const long double& _rhs);					/** Plus-Equals Op. for appending a 8 byte long double */
	String& operator += (const bool& _rhs);						/** Plus-Equals Op. for appending a boolean */

	String operator + (const String& _rhs);
	String operator + (const char* _rhs);
	String operator + (const char& _rhs);
	String operator + (const short& _rhs);
	String operator + (const int& _rhs);
	String operator + (const long& _rhs);
	String operator + (const float& _rhs);
	String operator + (const double& _rhs);
	String operator + (const unsigned char& _rhs);
	String operator + (const unsigned short& _rhs);
	String operator + (const unsigned int& _rhs);
	String operator + (const unsigned long& _rhs);
	String operator + (const unsigned long long& _rhs);
	String operator + (const long long& _rhs);
	String operator + (const long double& _rhs);
	String operator + (const bool& _rhs);

	bool operator == (const String& _rhs);
	bool operator == (const char* _rhs);

	int get(char* _s);												/** get string using declared buffer */
	int get(char** _s);												/** get string using uninitialized pointer */
	int getLength();												/** get length of the string not including the null teminator */

	int set(char* _s);												/** set the string in this object, same as *this = _s */
	int set(const String& _s);										/** set the string in this object, same as *this = _s */
	int concatenate(char* _s);										/** appends _s to this string, same as *this += _s */
	int concatenate(const String& _s);								/** appends _s to this string, same as *this += _s */
	int first(char _letter);										/** returns the index of the first occurence of the _letter, if the string is null the returned value is -1, if _letter does not occure in the string the return value is -2 */
	int last(char _letter);											/** returns the index of the last occurence of the _letter, if the string is null the returned value is -1, if _letter does not occure in the string the return value is -2 */
	int compare(char* _s);											/** compares _s to this string, returns 1 if equal, otherwise 0 */
	int compare(const String& _s);									/** compares _s to this string, returns 1 if equal, otherwise 0 */
	int startsWith(const String& _s);
	int endsWith(const String& _s);

	void reverse();													/** reverses the characters in this string */
	String slice(int _start, int _end);								/** returns the characters from _start to _end */
	String splice(int _start, int _remove, const String& _s);		/** removes _remove characters beginning at _start; replaces them with _s, and returns the removed String */
	String splice(int _start, int _remove, char* _s);				/** removes _remove characters beginning at _start; replaces them with _s, and returns the removed String */
	String splice(int _start, int _remove);							/** removes _remove characters beginning at _start, and returns the removed String */
	String snip(char _delimiter);
	char at(int _index);

	int parseInt();													/** Parses the first integer value in the string */
	float parseFloat();												/** Parses the first float in the string */

	int readFromTextFile(FILE* _f, int _size);
	int writeToTextFile(FILE* _f);

	~String();
protected:
	char* s;														/** pointer to the buffer */
	int size;														/** size of the buffer */
	int length;														/** the amount of characters before, but not including, the terminal null */

	int ensureCapacity(int flen);									/** makes sure the buffer can hold the current string plus one _flen in length */
	int trim();														/** trims the size of the buffer to the length + the terminal null */
};
#endif
