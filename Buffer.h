#pragma once
#include"baseMessage.h"
class Buffer
{
	char** buffer;
public:
	void addToBuffer(char*);
	char** getBuffer();
	void cleanBuffer();
};

