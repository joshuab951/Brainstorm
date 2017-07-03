//#include "time.h"
//#include <fstream>
//#include <iostream>
#include <string>

using namespace std;

class getValueFromList
{
	public:
		// Constructors
		getValueFromList();
		// Default constructor
		getValueFromList(string fileToUse);

		// Get the random value from the list.
		string getValue();
	private:
		string fileName; // The list file to read.
};
