#include "simulator.h"
simulator::simulator()
{
		std::string myText;
	std::ifstream MyFile("config.txt");
	if (MyFile.is_open()) {
		std::string value;
		while (getline(MyFile, myText)) {
			auto delimiterPos = myText.find("=");
			std::string name = myText.substr(0, delimiterPos);
			value = myText.substr(delimiterPos + 1);
		}
		numOfCameras = std::stoi(value);
	}

	MyFile.close();
	
	cameras = (camera**)malloc(sizeof(camera*) * numOfCameras);
	for (int i = 0; i < numOfCameras; i++)
	{
		cameras[i] = new camera();
	}
		}

void simulator::runCamera()
{
	std::thread threadsRun[5];

	for (int i = 0; i < numOfCameras; i++)
	{
		threadsRun[i]=std::thread (&camera::run, *(cameras[i]));
	}
	std::thread threadsSend[5];
	for (int i = 0; i < numOfCameras; i++)
	{
		threadsSend[i] = std::thread(&camera::sendToServer, *(cameras[i]));
	}
	std::cout << "press 1 to exit";
	int bit;
	std::cin >> bit;
	
	if (bit == 1)
		for (int i = 0; i < numOfCameras; i++)
		{
			cameras[i]->stop();
			threadsRun[i].detach();
			threadsSend[i].detach();
		}
}

void simulator::print()
{
	for (int i = 0; i < numOfCameras; i++)
	for (int i = 0; i < numOfCameras; i++)
	{
		std::cout << "camera: "<<i;

		for (int j = 0; j < cameras[i]->messageCount; j++)
		{
			std::cout << cameras[i]->getCameraBuffer()[j];
		}
	}
}

int simulator::getNumOfCameras()
{
	return this->numOfCameras;
}
