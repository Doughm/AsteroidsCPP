//Keeps track of game time
#include "gametimer.h"

GameTimer::GameTimer()
{
	timer.restart();
}

//restarts the clock
double GameTimer::restartClock()
{
	return timer.restart().asMicroseconds();
}

//returns the time value in microseconds
double GameTimer::getElapsedTimeMicroseconds()
{
	return timer.getElapsedTime().asMicroseconds();
}

//returns the time value in milliseconds
double GameTimer::getElapsedTimeMilliseconds()
{
	return timer.getElapsedTime().asMilliseconds();
}

//returns the time value in seconds
double GameTimer::getElapsedTimeSeconds()
{
	return timer.getElapsedTime().asSeconds();
}

//returns the amount of time the last cycle was off by
double GameTimer::getDeltaTime(double const& speed)
{
	return speed/(double)timer.getElapsedTime().asMicroseconds();
}