#include"baseMessage.h"
#include"Buffer.h"
#ifndef CAMERA
#define CAMERA
class camera
{
	char cameraId;
	baseMessage** messages;
	Buffer* buffer;
	bool isActive;
public:
	camera();
	camera(char id);
	void generate();
	void sendToBuffer();
	void run();
	void stop();
};
#endif



