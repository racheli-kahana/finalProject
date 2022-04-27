#ifndef CAMERA
#define CAMERA
#include"Buffer.h"

class camera
{
	char cameraId;
	baseMessage** messages=nullptr;
	Buffer buffer;
	bool isActive;
	int size = 0;
public:
	camera();
	camera(char id);
	void generate();
	void sendToBuffer();
	void run();
	void stop();
};
#endif



