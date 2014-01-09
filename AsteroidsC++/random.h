#ifndef RANDOM
#define RANDOM

#include <random>

class Random
{
public:
	Random();
	Random(int,int);
	void setMin(int);
	void setMax(int);
	void setMinMax(int, int);
	int getRandomNumber();
	int getRandomNumber(int, int);
	int getMin();
	int getMax();

private:
	std::tr1::mt19937 random;
	std::tr1::uniform_int_distribution<int> uniformRandom;
};

#endif