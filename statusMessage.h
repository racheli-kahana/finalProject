#pragma once
#ifndef STATUSMESSAGE
#define STATUSMESSAGE
#include "baseMessage.h"
class statusMessage :public baseMessage
{
protected:
	short status;//(1 - 3)
public:
	void parseMessage();
	void parseBack();
	void print();
	statusMessage(int messageId, int messageType, short status);
	statusMessage();
	~statusMessage();
};

#endif // !STATUSMESSAGE


