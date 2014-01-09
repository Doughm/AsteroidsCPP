//keeps track of how many loops have gone by, and when a specific amount has passed

#ifndef TICKER
#define TICKER

class Ticker
{
public:
	Ticker();
	void increment();
	int currentAmount();
	bool atAmount(int);
	void resetCounter();
};

#endif