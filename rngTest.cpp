#include "rng.cpp"
#include <iostream>

using namespace std;

rng numberGenerator(0,255);

int main()
{
	int randomNumber = numberGenerator.generateNumber();
	cout << randomNumber << endl;
	return 0;
}
