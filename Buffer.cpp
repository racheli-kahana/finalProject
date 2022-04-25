#include "Buffer.h"
#include<stdio.h>
#include<stdlib.h>
void Buffer:: addToBuffer(char* message) {
	static int index = 0;
	this->buffer = (char**)realloc(buffer, sizeof(char*));
	this->buffer[index++] = message;
}
char** Buffer::getBuffer() {
	return this->buffer;
}
void Buffer::cleanBuffer() {
	
	if(this->buffer)
		for (int i = 0; i < sizeof(this->buffer)/sizeof(char*); i++)
		{
			free(buffer[i]);
		}
	free(buffer);
	buffer = nullptr;
}