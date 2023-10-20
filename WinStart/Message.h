#ifndef MESSAGE_H
#define MESSAGE_H

#include "String.h"

#define MSG_ONPRC_REMOVE			0x00000001
#define MSG_ONPRC_REPLYREQ			0x00000002

// for x86
typedef unsigned int		XPARAM;
typedef long				YPARAM;

// for x164
//typedef unsigned long int	XPARAM;
//typedef long long			YPARAM;

typedef struct _THREEFLOAT
{
	float r;
	float g;
	float b;
} THREEFLOAT, * LPTHREEFLOAT;

typedef struct _NEWMAP
{
	String name;
	int sourceWidth;
	int sourceHeight;
	int destWidth;
	int destHeight;
	int mapWidth;
	int mapHeight;
	String tilemap;
} NEWMAP, * LPNEWMAP;

class Message
{
public:
	Message();
	Message(unsigned int _opcode, XPARAM _wParam, YPARAM _lParam, const String& _target);
	Message(const Message& _cpy);

	unsigned int getCode();
	int getWParam();
	long getLParam();
	int getProcOption();

	void setCode(unsigned int _opcode);
	void setWParam(XPARAM _wParam);
	void setLParam(YPARAM _lParam);
	void setProcOption(int _onProc);

	String getTarget();
	void clipTarget();

	String getSource();
	void appendSource(String& _id);

	Message& operator = (const Message& _cpy);

	~Message();

protected:
	unsigned int opcode;
	unsigned int wParam;
	long lParam;
	String target;
	String source;
	int onProc;
};


#endif
