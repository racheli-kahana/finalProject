#define _CRT_SECURE_NO_WARNINGS
#include"simulator.h"

int main()
{
	simulator* sim = new simulator();
	sim->runCamera();
	std::cout << "AAA";
}
