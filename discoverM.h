//#pragma once
#ifndef DISCOVERM
#define DISCOVERM
#include"baseMessage.h"
#include<iostream>

class discoverM:public baseMessage
{
	float distance;
	float angle;
	float speed;
public:
	void parseMessage();
	void parseBack();
	void print();
	discoverM(int messageId, int messageType, float distance, float angle, float speed);
	discoverM();
	~discoverM();
};
#endif // !DISCOVERM


