#include "camera.h"
#include"discoverMessage.h"
#include"statusMessage.h"
#include<random>
static int messageIndex = 0;
statusMessage* createStatusMessage()
{
	static int id = 1;
	id++;
	statusMessage* sm = new statusMessage(id, 1, rand() % 3 + 1);
	return sm;
}

discoverMessage* createDiscoverMessage()
{
	static int id = 100;
	id++;
	discoverMessage* dm = new discoverMessage(id, 2, rand() % 9500 + 500, rand() % 361, rand() % 1001);
	return dm;
}
camera::camera()
{
	isActive = true;
}
camera::camera(char id)
{
	isActive = true;
	this->cameraId = id;
}
void camera::generate() {
	int messageType;
	
	for (int i = 0; i < 5; i++)
	{
		baseMessage* message=nullptr;
		messageType = rand() % 2 + 1;
		if (messageType == 1)
		discoverMessage*(message)=createDiscoverMessage();
		else
		statusMessage* (message)=createStatusMessage();
		this->messages = (baseMessage**)realloc(this->messages, sizeof(message));
		this->messages[messageIndex++] = message;
	}
}
void camera::sendToBuffer() {
	for (int i = 0; i < messageIndex; i++)
	{
		messages[i]->parseBack();
		this->buffer->addToBuffer( (char*)messages[i]->getMessageBuffer());
		free(this->messages[i]);
	}
	free(messages);
}
void camera::run() {
	int j = 0;
	while (isActive == true) {
		j++;
		generate();
		if (j % 5 == 0)
		sendToBuffer();
	}
}
void camera::stop() {
	isActive = false;
}
