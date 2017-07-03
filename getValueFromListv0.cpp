//#include "rng.h"
#include "time.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string fileName = "Animals.txt"; // Define the file name here.

int main() {
	string line;
	ifstream myFile(fileName);

int numberOfLines = 0; // Number of lines in the file.
string lineInFile;
//myFile.open();
while(getline(myFile, lineInFile)) {
	numberOfLines++;
}
myFile.close();

string outFromFile(string fileName) {
	srand(time(NULL)); // Seed the random number generator.
	//myFile.open();
	int randomLineNumber = rand() % numberOfLines; // Get a random line number.
	string outputValue = getline(myFile, randomLineNumber);
	myFile.close();
	return outputValue;
}

int main(string fileName, int numberOfOutputs) {
	srand(time(NULL)); // Seed the random number generator.
	for(int i = 0; i <= numberOfOutputs; i++)
		cout << outFromFile(fileName);
	return 0;
}
