#include "Buffer.h"
void Buffer::addToBuffer(char* message) {
		m.lock();
		this->buffer = (char**)realloc(this->buffer, sizeof(char*) * (index + 1));
	if (buffer == NULL) {
		exit(-1);
		m.unlock();
	}
	buffer[index] = (char*)malloc(sizeof(discoverM) > sizeof(statusMessage) ? sizeof(discoverM) : sizeof(statusMessage));
	if (this->buffer != NULL)
		strcpy(buffer[index++], message);
	m.unlock();
}
char** Buffer::getBuffer() {
	return this->buffer;
}
void Buffer::cleanBuffer() {
	m.lock();
	if (this->buffer){
		free(buffer);
		buffer = NULL;
		index = 0;
	}
	m.unlock();
}