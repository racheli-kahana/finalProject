#include "simulator.h"
//using namespace std;
simulator::simulator()
{
	cameras = (camera**)malloc(sizeof(camera*) * 5);
	for (int i = 0; i < 5; i++)
	{
		cameras[i] = new camera();
	}
		}

void simulator::runCamera()
{
	std::thread threadsRun[5];

	for (int i = 0; i < 5; i++)
	{
		threadsRun[i]=std::thread (&camera::run, *(cameras[i]));
		std::cout << i;
	}
	std::thread threadsSend[5];
	for (int i = 0; i < 5; i++)
	{
		threadsSend[i] = std::thread(&camera::sendToServer, *(cameras[i]));
		std::cout << i;
	}
	std::cout << "press 1 to exit";
	int bit;
	std::cin >> bit;
	
	if (bit == 1)
		for (int i = 0; i < 5; i++)
		{
			cameras[i]->stop();
			threadsRun[i].detach();
		}
}

void simulator::print()
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << "camera: "<<i;

		for (int j = 0; j < cameras[i]->messageCount; j++)
		{
			std::cout << cameras[i]->getCameraBuffer()[j];
		}
	}
}
