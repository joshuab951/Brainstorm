#include "rng.h"
#include "time.h"
#include <stdlib.h>

using namespace std;

// Constructors
rng::rng()
{
	lowLimit = 0;
	highLimit = 1;
}
// Default Constructor
rng::rng(int lowLimitSet, int highLimitSet)
{
	lowLimit = lowLimitSet;
	highLimit = highLimitSet;
}

// Generate the random number.
int rng::generateNumber()
{
	srand(time(NULL)); // Seed the random number generator.
	randomNumber = rand() % highLimit + lowLimit; // Generate the random number.
	return randomNumber;
}
