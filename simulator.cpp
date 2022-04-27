#include "simulator.h"
//using namespace std;
simulator::simulator()
{
	cameras = (camera**)malloc(sizeof(camera) * 5);
	for (int i = 0; i < 5; i++)
	{
		cameras[i] = new camera();
	}
	runCamera();
	
}

void simulator::runCamera()
{
	std::thread threads[5]; 
	for (int i = 0; i < 5; i++)
	{
		threads[i]=std::thread (&camera::run, *(cameras[i]));
		std::cout << i;

	}
	std::cout << "press 1 to exit";
	int bit;
	std::cin >> bit;
	if (bit == 1)
		for (int i = 0; i < 5; i++)
		{
			cameras[i]->stop();
			threads[i].detach();
		}
}
