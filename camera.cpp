#include "camera.h"
#include<random>
//#include<iostream>
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
	cameraBuffer = new Buffer();
}
camera::camera(char id)
{
	isActive = true;
	this->cameraId = id;
	cameraBuffer = new Buffer();

}
char** camera::getCameraBuffer() {
	return this->cameraBuffer->getBuffer();
}
void camera::generate() {
	int messageType;
	this->messages = (baseMessage**)realloc(this->messages, sizeof(baseMessage*) * (size + 5));
	if (messages == NULL)
		exit(1);
	for (int i = 0; i < 5; i++)
	{
		messageType = rand() % 2 + 1;
		if (messageType == 1)
			this->messages[size++] = createDiscoverMessage();
		else
			this->messages[size++] = createStatusMessage();

	}
}
void camera::sendToBuffer() {
	for (int i = 0; i < this->size; i++)
	{
		messages[i]->parseBack();
		 messages[i]->print();
		cameraBuffer->addToBuffer((char*)messages[i]->getMessageBuffer());
		free(this->messages[i]->getMessageBuffer());
		delete(this->messages[i]);
	}
	free(this->messages);
	messages = nullptr;
	messageCount += size;
	size = 0;
}
void camera::run() {
	while (isActive == true)
	{
		generate();
		sendToBuffer();
	}
}
void camera::stop() {
	isActive = false;
}

camera::~camera()
{
	/*if (this->cameraBuffer->getBuffer() != NULL)
		free(this->cameraBuffer->getBuffer());
	delete(cameraBuffer);
	cameraBuffer = nullptr;*/
	//this->cameraBuffer->cleanBuffer();
}

void camera::sendToServer()
{
	while (isActive)
	{
		Sleep(3000);
		WSAData wsaData;
		WORD DllVersion = MAKEWORD(2, 1);
		if (WSAStartup(DllVersion, &wsaData) != 0) {
			std::cout << "Winsock Connection Failed!" << std::endl;
			exit(1);
		}
		std::string getInput = "";
		SOCKADDR_IN addr;
		int addrLen = sizeof(addr);
		IN_ADDR ipvalue;
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		addr.sin_port = htons(8080);
		addr.sin_family = AF_INET;

		SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);
		if (connect(connection, (SOCKADDR*)&addr, addrLen) == 0) {
			std::cout << "Connected!" << std::endl;
			for (int i = 0; i < cameraBuffer->index; i++)
			{
				getInput = this->cameraBuffer->getBuffer()[i];
				if(cameraBuffer->getBuffer()[i][0]==1)
				send(connection, getInput.c_str(),6, 0);
				else
				send(connection, getInput.c_str(), 14, 0);

			}
			closesocket(connection);
			WSACleanup();
						return;
		}
		else {
			std::cout << "Error Connecting to Host" << std::endl;
			this->cameraBuffer->cleanBuffer();

		}
	}
	
	
	
}


