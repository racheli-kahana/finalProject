#include"camera.h"
#include<thread>
#include<fstream>
#include<iostream>
#include<string>
class simulator
{
	camera** cameras;
	int numOfCameras;

public:
	simulator();
	void runCamera();
	void print();
	int getNumOfCameras();
};

