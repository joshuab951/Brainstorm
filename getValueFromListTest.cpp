#include "getValueFromList.cpp"
#include "time.h"
#include <fstream>
#include <iostream>
#include <string>
//#include <unistd.h>

using namespace std;

getValueFromList animalList("Animals.txt");

int main()
{
	// Generate a random animal.
	string randomAnimal = "";
	//for (int i = 0; i < 3; i++)
	//{
		randomAnimal = animalList.getValue();
		cout << randomAnimal << endl;
		//sleep(100);
	//}
}
