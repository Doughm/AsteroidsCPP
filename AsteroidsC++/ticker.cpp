#include "ticker.h"

int counter;

Ticker::Ticker()
{
	counter = 0;
}

//adds one too the total amount
void Ticker::increment()
{
	counter++;
}

//returns the current amount in the counter
int Ticker::currentAmount()
{
	return counter;
}

//returns if a value is at or greater than the counter
bool Ticker::atAmount(int amount)
{
	if (amount <= counter)
    {
        return true;
    }
    return false;
}

//resets the counter
void Ticker::resetCounter()
{
	counter = 0;
}