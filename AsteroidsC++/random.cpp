//returns a random number between two set numbers

#include "random.h"
#include <ctime>

Random::Random()
{
	random.seed((unsigned)time(0));
}

Random::Random(int min,int max)
{
	random.seed((unsigned)time(0));
	std::tr1::uniform_int_distribution<int> uniformRandom(min, max);
}

//sets the minimum value of the random number
void Random::setMin(int min)
{
	std::tr1::uniform_int_distribution<int> uniformRandom(min, uniformRandom.b());
}

//sets the maximum value of the random number
void Random::setMax(int max)
{
	std::tr1::uniform_int_distribution<int> uniformRandom(uniformRandom.a(), max);
}

//sets both the minimum and maximum values of the random number
void Random::setMinMax(int min, int max)
{
	std::tr1::uniform_int_distribution<int> uniformRandom(min, max);
}

//returns a random value between the minimum and maximum values
int Random::getRandomNumber()
{
	return uniformRandom(random);
}

//returns a random value between the minimum and maximum values
int Random::getRandomNumber(int min, int max)
{
	std::tr1::uniform_int_distribution<int> uniformRandom(min, max);
	return uniformRandom(random);
}

//returns the minimum value
int Random::getMin()
{
	return uniformRandom.a();
}

//returns the maximum value
int Random::getMax()
{
	return uniformRandom.b();
}