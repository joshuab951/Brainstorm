// Create the generator.
#include "getValueFromList.cpp"
#include "rng.cpp"
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace boost;

string delimiter = ",";

int buildGenerator()
{

	// Generator name
	string genName;
	cout << "Generator name: ";
	cin >> genName;
	
	// Create file
	ofstream genFile;
	string genFileName = genName + ".gen";
	genFile.open(genFileName);
	
	// Build generator
	int buildGeneratorMenuSelection;
	while (true)
	{
		buildGeneratorMenuSelection = 0;
		cout << "1) Add Text Parameter" << endl
		     <<	"2) Add Number Parameter" << endl
		     << "3) List Parameters" << endl
	       	     << "4) Delete Parameter" << endl
		     << "5) Exit" << endl
		     << "> ";
		cin >> buildGeneratorMenuSelection;

		switch(buildGeneratorMenuSelection)
		{
			case 1:
			{
				cout << "New Text Parameter" << endl;
				string label;
				cout << "Label: ";
				cin >> label;
				genFile << "Label" << delimiter << label << endl; // Write label to file
				cout << "File: ";
				string listFileName;
				cin >> listFileName;
				genFile << "Filename" << delimiter << listFileName << endl; // Write filename to file.
				break;
			}
			case 2:
			{
				cout << "New Random Number Generator Parameter" << endl;
				string label;
				cout << "Label: ";
				cin >> label;
				genFile << "Label" << delimiter << label << endl; // Write label to file
				
				// Get min/max numbers.
				int rngMin = 0;
				int rngMax = 1;
				while (rngMin >= rngMax)
				{
					cout << "Minimum number: ";
					cin >> rngMin;
					cout << "Maximum number: ";
					cin >> rngMax;
					if (rngMax > rngMin)
					{
						break;
					}
				}
				genFile << "Min" << delimiter << rngMin << endl;
				genFile << "Max" << delimiter << rngMax << endl;
				break;
			}
			case 3:
			{	
				// Scroll through the file and list the parameters.
				ifstream genFileIn(genFileName);
				string genFileLine;
				while(getline(genFileIn, genFileLine))
				{
					cout << genFileLine << endl;
				}
				break;
			}
			case 4:
			{
				string paramToDelete;
				//cout << "Are you sure?" << endl;
				cout << "Parameter to delete: " << endl;
			        cin >> paramToDelete;
				
				ifstream genFileIn(genFileName);
				string genFileLine;
				while(getline(genFileIn, genFileLine))
				{
					genFileLine.replace(genFileLine.find(paramToDelete),deleteline.length(),"");
					cout << genFileLine << endl;
				}

				break;
			}
			case 5:
			{
				cout << "Exit" << endl;
				//exit(0);
				return 0;
				break;
			}
			default:
			{
				cout << "Error: input not recognized." << endl;
			}
		}
	}
	return 0;
}

int editGenerator()
{

	// Generator name
	string genName;
	cout << "Generator name: ";
	cin >> genName;
	
	// Load file
	ifstream genFile;
	string genFileName = genName + ".gen";
	genFile.open(genFileName);
	
	// Edit generator
	int editGeneratorMenuSelection;
	while (true)
	{
		editGeneratorMenuSelection = 0;
		cout << "1) Add Text Parameter" << endl
		     <<	"2) Add Number Parameter" << endl
		     << "3) List Parameters" << endl
	       	     << "4) Delete Parameter" << endl
		     << "5) Exit" << endl
		     << "> ";
		cin >> buildGeneratorMenuSelection;

		switch(buildGeneratorMenuSelection)
		{
			case 1:
			{
				cout << "Add Text Parameter" << endl;
				string label;
				cout << "Label: ";
				cin >> label;
				genFile << "Label" << delimiter << label << endl; // Write label to file
				cout << "File: ";
				string listFileName;
				cin >> listFileName;
				genFile << "Filename" << delimiter << listFileName << endl; // Write filename to file.
				break;
			}
			case 2:
			{
				cout << "Add Number Parameter" << endl;
				string label;
				cout << "Label: ";
				cin >> label;
				genFile << "Label" << delimiter << label << endl; // Write label to file
				
				// Get min/max numbers.
				int rngMin = 0;
				int rngMax = 1;
				while (rngMin >= rngMax)
				{
					cout << "Minimum number: ";
					cin >> rngMin;
					cout << "Maximum number: ";
					cin >> rngMax;
					if (rngMax > rngMin)
					{
						break;
					}
				}
				genFile << "Min" << delimiter << rngMin << endl;
				genFile << "Max" << delimiter << rngMax << endl;
				break;
			}
			case 3:
			{	
				// Scroll through the file and list the parameters.
				ifstream genFileIn(genFileName);
				string genFileLine;
				while(getline(genFileIn, genFileLine))
				{
					cout << genFileLine << endl;
				}
				break;
			}
			case 4:
			{
				string paramToDelete;
				//cout << "Are you sure?" << endl;
				cout << "Parameter to delete: " << endl;
			        cin >> paramToDelete;
				
				ifstream genFileIn(genFileName);
				string genFileLine;
				while(getline(genFileIn, genFileLine))
				{
					genFileLine.replace(genFileLine.find(paramToDelete),deleteline.length(),"");
					cout << genFileLine << endl;
				}
			}
			case 5:
			{
				cout << "Exit" << endl;
				//exit(0);
				return 0;

				break;
			}
			default:
			{
				cout << "Error: input not recognized." << endl;
			}
		}
	}
	return 0;
}

int useGenerator()
{
	// Open the generator file.
	string genFileName;
	cout << "Generator file name: ";
	cin >> genFileName;
	ifstream genFile(genFileName);

	// Iterate through the file and run through each generator.
	string fileDataLine[2];
	string line;
	//int lineDelimeterLocation;
	int i = 0; // Loop counter.
	int pos = 0; // Position of string delimiter.
	string fileName = "";
	int minNum = 0;
       	int maxNum = 1; // In case we have a random number generator.
	int randNum = 0;

	while(!genFile.eof())
	{
		fileDataLine[0] = "";
		fileDataLine[1] = "";
		getline(genFile, line);

		tokenizer<> tok(line);
		for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();beg++)
		{
			//cout << *beg << endl;
			fileDataLine[i] = *beg;
			i++;
		}
		i = 0;
		//cout << fileDataLine[0] << fileDataLine[1] << endl;
		if (fileDataLine[0] == "Label")
		{
			cout << fileDataLine[1] << ": ";
		}
		else if (fileDataLine[0] == "Filename")
		{
			fileName = fileDataLine[1] + ".txt";
			getValueFromList list(fileName);
			string listResult = "";
			listResult = list.getValue();
			cout << listResult << endl;
		}
		else if (fileDataLine[0] == "Min")
		{
			minNum = 0;//stoi(fileDataLine[1]);
		}
		else if (fileDataLine[0] == "Max")
		{
			maxNum = 255;//stoi(fileDataLine[1]);
			rng randNumGen(minNum, maxNum);
			randNum = randNumGen.generateNumber(); 
			cout << randNum << endl;
		}
	}
	return 0;
}

int main()
{
	cout << "Brainstorm 1.0" << endl
	     << "Created by Joshua C. Blow" << endl;
	int choice;
	while (true)
	{
		choice = 0; // Initialize the "choice" variable.
		// Print menu
		cout << "Options" << endl
		     << "1) Launch Generator" << endl
		     << "2) Create New Generator" << endl
		     << "3) Edit Generator" << endl
		     /*<< "4) Get Generator File Info" << endl
		     << "5) Settings" << endl
		     << "6) Exit" << endl*/
		     << "4) Exit" << endl
		     << "> ";
		cin >> choice;
		switch (choice)
		{
			case 1:		// Launch generator.
				useGenerator();	
				break;
			case 2:		// Create new generator.
				buildGenerator();
				break;
			case 3:		// Edit generator.
				//editGenerator();
				break;
			/*case 4:		// Get generator file info.
				//getGeneratorFileInfo();
				break;
			case 5:		// Settings.
				//settings();
				break;
			case 6:		// Exit.
				exit(0);*/
			case 4:		// Exit.
				exit(0);
			default:
				cout << "Input not recognized." << endl;
		}
	}
	return 0;	
}
