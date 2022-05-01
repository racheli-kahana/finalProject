#ifndef BUFFER
#define BUFFER
#include"baseMessage.h"
#include<mutex>
#include"discoverM.h"
#include"statusMessage.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
class Buffer
{
	char** buffer = nullptr;
	std::mutex m;
public:
	int index = 0;
	void addToBuffer(char*);
	char** getBuffer();
	void cleanBuffer();
};

#endif // !BUFFER


