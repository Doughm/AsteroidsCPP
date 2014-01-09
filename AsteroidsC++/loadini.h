//includes all functionality needed to save and load from an ini file

#ifndef LOADINI
#define LOADINI

#include<string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class LoadINI
{
public:
	LoadINI();
	LoadINI(std::string const&);
	std::string getFile();
	std::string getFileName();
	bool fileExists(std::string const&);
	void setFile(std::string const&);
	bool inFile(std::string const&);
	std::string getValue(std::string const&);
	void updateFile(std::string const&, std::string const&);
private:
	unsigned int count;
	float tempFloat;
	std::vector<std::string> fileContent;
	std::string tempString;
	std::string fileName;
	std::ifstream openFile;
	std::ofstream writeFile;
	std::stringstream buffer;
};

#endif