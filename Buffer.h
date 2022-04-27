#ifndef BUFFER
#define BUFFER
#include"baseMessage.h"
//#include"discoverMessage.h"
#include"discoverM.h"
#include"statusMessage.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
class Buffer
{
	char** buffer=nullptr;
	int index = 0;

public:
	void addToBuffer(char*);
	char** getBuffer();
	void cleanBuffer();
};

#endif // !BUFFER


