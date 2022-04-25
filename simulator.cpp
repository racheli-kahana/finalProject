#include "simulator.h"
using namespace std;
simulator::simulator()
{
	int bit;
	cameras = (camera**)malloc(sizeof(camera) * 5);
	for (int i = 0; i < 5; i++)
	{
		cameras[i] = new camera();
	}
	runCamera();
	std::cout << "press 1 to exit";
	std::cin >> bit;
	if (bit == 1)
		for (int i = 0; i < 5; i++)
		{
			cameras[i]->stop();
		}
}

void simulator::runCamera()
{
	thread* threads = (thread*)malloc(sizeof(thread) * 3);
	for (int i = 0; i < 5; i++)
	{
		threads[i]=thread (&camera::run, cameras[i],i);
	}
}
