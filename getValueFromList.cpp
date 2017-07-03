#include "getValueFromList.h"
#include "time.h"
#include <fstream>
#include <iostream>
#include <string>
//#include <unistd.h> // For using the POSIX delay function - change this for the Windows port.

using namespace std;

// Constructors
// Default constructor
getValueFromList::getValueFromList()
{
	fileName = "";
}

// Constructor
getValueFromList::getValueFromList(string fileToUse)
{
	fileName = fileToUse;
}

// Get the random value from the list.
string getValueFromList::getValue() 
{
	//usleep(100); // POSIX delay feature - used because the "random" number generator wasn't random enough. Change this for the Windows port.
	srand(time(NULL)); // Seed the random number generator.
	string line; // Store the line as it is read from the file.
	ifstream myFile(fileName); // Open the file.
	int numberOfLines = 0; // Number of lines in the file.
	
	// Check if the file is open.
	if(myFile.is_open())
	{
		// Count the number of lines in the file.
		while(getline(myFile, line))
		{
			numberOfLines++;
		}
		myFile.clear(); // Reset the line reader.
		int randomLineNumber = rand() % numberOfLines; // Get a random line number.
		myFile.seekg(0,ios::beg); // Send it to the beginning.
		string lineToReturn = ""; // Stores the line to be returned.
		// Get the line determined by the random line number.
		for (int lineNumber = 0; getline(myFile, line) && lineNumber <= randomLineNumber; lineNumber++)
		{
			if (lineNumber == randomLineNumber)
			{
				lineToReturn = line;
			}
		}
		myFile.close(); // Close the list file.
		return lineToReturn;
	}
	else // If the file is not open.
	{
		cout << "Unable to open the list file." << endl;
		return "";
	}
}
