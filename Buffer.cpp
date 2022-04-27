#include "Buffer.h"
void Buffer::addToBuffer(char* message) {
	this->buffer = (char**)realloc(this->buffer, sizeof(char*) * (index + 1));
	buffer[index] = (char*)malloc(sizeof(discoverM) > sizeof(statusMessage) ? sizeof(discoverM) : sizeof(statusMessage));
	if (this->buffer != NULL)
		strcpy(buffer[index++], message);

}
char** Buffer::getBuffer() {
	return this->buffer;
}
void Buffer::cleanBuffer() {

	if (this->buffer)
		for (int i = 0; i < sizeof(this->buffer) / sizeof(char*); i++)
		{
			free(buffer[i]);
		}
	free(buffer);
	buffer = NULL;
}