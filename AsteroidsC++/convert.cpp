#include "convert.h"
#include <sstream>

//converts a string to an int
int Convert::stringToInt(std::string const& stringIn)
{
	int tempInt;
	std::stringstream(stringIn) >> tempInt;
	return tempInt;
}
//converts a string to a float
float Convert::stringToFloat(std::string const& stringIn)
{
	float tempFloat;
	std::stringstream(stringIn) >> tempFloat;
	return tempFloat;
}
//converts a string to a double
double Convert::stringToDouble(std::string const& stringIn)
{
	double tempdouble;
	std::stringstream(stringIn) >> tempdouble;
	return tempdouble;
}
//converts a string to a bool
bool Convert::stringToBool(std::string const& stringIn)
{
	if(stringIn=="true" || stringIn=="True")
	{
		return true;
	}
	return false;
}

//coverts an int to a string
std::string Convert::intToString(int intIn)
{
	std::stringstream stream;
	stream << intIn;
	return stream.str();
}

std::string Convert::floatToString(float floatIn)
{
	std::stringstream stream;
	stream << floatIn;
	return stream.str();
}

//coverts an int to a string
std::string Convert::doubleToString(double const& doubleIn)
{
	std::stringstream stream;
	stream << doubleIn;
	return stream.str();
}

//coverts a bool to a string
std::string Convert::boolToString(bool boolIn)
{
	if(boolIn == true)
	{
		return "true";
	}
	else
	{
		return "false";
	}
}