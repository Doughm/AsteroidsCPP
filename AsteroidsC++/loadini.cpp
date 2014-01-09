#include "loadini.h"

LoadINI::LoadINI()
{
	fileName = "no file selected";
}

LoadINI::LoadINI(std::string const& file)
{
	setFile(file);
}

//sets a new file to access
void LoadINI::setFile(std::string const& file)
{
	fileName = file;
	count = 0;
	fileContent.clear();
	fileContent.push_back("");
	openFile.open(file);
	if(openFile.good() == true)
	{
		buffer<<openFile.rdbuf();
		tempString = buffer.str();
		for(unsigned int i = 0 ; i < tempString.length(); ++i)
		{
			if(tempString[i] != '\n')
			{
				fileContent[count] += tempString[i];
			}
			else
			{
				count++;
				fileContent.push_back("");
			}
		}
	}
	openFile.close();
}

//returns the name of the file set
std::string LoadINI::getFileName()
{
	return fileName;
}

//returns if the given file exists
bool LoadINI::fileExists(std::string const& file)
{
	if(openFile.good() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns the whole file
std::string LoadINI::getFile()
{
	tempString = "";
	for(unsigned int i =0 ; i < fileContent.size(); ++i)
	{
		tempString += fileContent[i];
		if(i < fileContent.size()-1)
		{
			tempString += "\n";
		}
	}
	return tempString;
}

//tests if given key is in the file
bool LoadINI::inFile(std::string const& key)
{
	for(unsigned int i =0 ; i < fileContent.size(); ++i)
	{
		if(fileContent[i].find(key) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}

//returns value of given key from file in a string format
std::string LoadINI::getValue(std::string const& key)
{
	count = 0;
	for(unsigned int i =0 ; i < fileContent.size(); ++i)
	{
		if(fileContent[i].find(key) != std::string::npos)
		{
			tempString = fileContent[i];
			for(unsigned int ii =0 ; ii < tempString.size(); ++ii)
			{
				if(tempString[ii] == '=' && count == 0)
				{
					count = 1;
				}
				if(tempString[ii+1] != ' ' && count == 1)
				{
					tempString = tempString.substr(ii+1);
					return tempString;
				}
			}
		}
	}
	return "key not found";
}

//updates a key in the file to a given value
void LoadINI::updateFile(std::string const& key, std::string const& newValue)
{
	for(unsigned int i =0 ; i < fileContent.size(); ++i)
	{
		if(fileContent[i].find(key) != std::string::npos)
		{
			fileContent[i] = key + " " + "=" + " " + newValue;
		}
	}
	writeFile.open(fileName);
	writeFile<<getFile();
	writeFile.close();
}