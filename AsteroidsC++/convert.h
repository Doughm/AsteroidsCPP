//converts between different data types

#ifndef CONVERT
#define CONVERT

#include <string>

class Convert
{
public:
	static int stringToInt(std::string const&);
	static float stringToFloat(std::string const&);
	static double stringToDouble(std::string const&);
	static bool stringToBool(std::string const&);
	static std::string intToString(int);
	static std::string doubleToString(double const&);
	static std::string floatToString(float);
	static std::string boolToString(bool);
};

#endif