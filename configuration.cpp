#include "configuration.h"

configuration::configuration()
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
	std::cout << numOfCameras;
}

int configuration::getNumOfCameras()
{
	return numOfCameras;
}
