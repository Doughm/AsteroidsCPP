//Keeps track of game time

#ifndef GAMETIMER
#define GAMETIMER

#include <SFML/System.hpp>

class GameTimer
{
public:
	GameTimer();
	void toggleStopwatch();
	double restartClock();
	double getElapsedTimeMicroseconds();
	double getElapsedTimeMilliseconds();
	double getElapsedTimeSeconds();
	double getDeltaTime(double const&);
private:
	sf::Clock timer;
};

#endif