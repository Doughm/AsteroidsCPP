#ifndef TEXTEDIT
#define TEXTEDIT

#include <string>
#include "gametimer.h"

class TextEdit
{
public:
	TextEdit();
	TextEdit(std::string const&);
	TextEdit(int, int, int);
	TextEdit(int, int, int, std::string const&);
	std::string takeInput(std::string const&);
	std::string getString();

private:
	std::string str;
	std::string tempStr;
	GameTimer timer;
	int speed;
	int repeat;
	int delay;
	std::string lastKey;
	bool held;
	bool paused;

	bool changeString(std::string const&);
	bool changeStringShift(std::string const&);
};

#endif