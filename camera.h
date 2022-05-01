#ifndef CAMERA
#define CAMERA
#include"Buffer.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>
class camera
{
	char cameraId;
	baseMessage** messages=nullptr;
	Buffer* cameraBuffer;
	bool isActive;
public:
	int size = 0;
	int messageCount = 0;
		camera();
	camera(char id);
	~camera();
	char** getCameraBuffer(); 
	void generate();
	void sendToBuffer();
	void run();
	void sendToServer();
	void stop();
};
#endif



