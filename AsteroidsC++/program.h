#ifndef PROGRAM
#define PROGRAM

#include "window.h"
#include "audio.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

Window window;
Audio audio;

class Program
{
private:
	void assetLoader(std::string const&);

public:
	void start();
};

#endif