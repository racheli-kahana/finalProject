#include "camera.h"
#include<random>
statusMessage* createStatusMessage()
{
	static int id = 1;
	id++;
	statusMessage* sm = new statusMessage(id, 1, rand() % 3 + 1);
	return sm;
}

discoverM* createDiscoverMessage()
{
	static int id = 100;
	id++;
	discoverM* dm = new discoverM(id, 2, rand() % 9500 + 500, rand() % 361, rand() % 1001);
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

	this->messages = (baseMessage**)realloc(this->messages, sizeof(baseMessage*) * (size+5));
	if (messages == NULL)
		exit(1);
	for (int i = 0; i < 5; i++)
	{
		
			messageType = rand() % 2 + 1;
		if (messageType == 1)
			this->messages[size++]=createDiscoverMessage();
		else
			this->messages[size++]=createStatusMessage();
		
	}
}
void camera::sendToBuffer() {
	for (int i = 0; i < this->size; i++)
	{
		messages[i]->parseBack();
		 messages[i]->print();
		buffer.addToBuffer( (char*)messages[i]->getMessageBuffer());
		free(this->messages[i]->getMessageBuffer());
		delete(this->messages[i]);
	}
	free(this->messages);
	messages = nullptr;
	size = 0;
	}
void camera::run() {
	int j = 0;
	while (isActive == true) {
		j++;
		generate();
		sendToBuffer();
	}
}
void camera::stop() {
	isActive = false;
}
