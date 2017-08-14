// Create the generator.
#include "getValueFromList.cpp"
#include "rng.cpp"
#include <boost/tokenizer.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std;
using namespace boost;

string delimiter = ",";

int buildGenerator()
{
	// Generator name
	string genName;
	cout << "Generator name: ";
	cin >> genName;
	string genFileName = genName + ".gen";
	
	// Create file
	ifstream genFileIn;
	ofstream genFileOut;
	genFileIn.open(genFileName);
	if (!genFileIn)
	{
		cout << "Error: unable to open file " << genFileName << "." << endl;
	}
	
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
		if (cin.fail())
		{
			cout << "Error: input is not recognized." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			//continue;
			//break;
		}
		else
		{
			switch(buildGeneratorMenuSelection)
			{
				case 1:
				{
					cout << "1" << endl;
					genFileIn.close();
					genFileOut.open(genFileName, ios::app);		
					cout << "New Text Parameter" << endl;
					string label;
					cout << "Label: ";
					cin >> label;
					genFileOut << "Label" << delimiter << label << endl; // Write label to file
					cout << "File: ";
					string listFileName;
					cin >> listFileName;
					genFileOut << "Filename" << delimiter << listFileName << endl; // Write filename to file.
					genFileOut.seekp(0, genFileOut.beg);
					genFileOut.close();
					genFileIn.open(genFileName);
					break;
				}
				case 2:
				{
					cout << "2" << endl;
					genFileIn.close();
					genFileOut.open(genFileName, ios::app);		
					cout << "New Random Number Generator Parameter" << endl;
					string label;
					cout << "Label: ";
					cin >> label;
					genFileOut << "Label" << delimiter << label << endl; // Write label to file
				
					// Get min/max numbers.
					int rngMinInput = 1;
					int rngMaxInput = 0;
					while (rngMinInput >= rngMaxInput)
					{
						cout << "Minimum number: ";
						cin >> rngMinInput;
						cout << "Maximum number: ";
						cin >> rngMaxInput;
						if (rngMaxInput > rngMinInput)
						{
							break;
						}
					}
					genFileOut << "Min" << delimiter << rngMinInput << endl;
					genFileOut << "Max" << delimiter << rngMaxInput << endl;
					genFileOut.seekp(0, genFileOut.beg);
					genFileOut.close();
					genFileIn.open(genFileName);
					break;
				}
				case 3:
				{	
					if (!genFileIn.is_open())
					{
						//cout << "Error - file not accessible" << endl;
						//break;
						genFileIn.open(genFileName);					
					}
					else
					{
						genFileIn.clear();
					}
					genFileIn.seekg(0, genFileIn.beg);
					// Iterate through the file and run through each generator.
					string fdLine;
					//int pos = genFileIn.tellg();
					//cout << "pos: " << pos << endl;
					try
					{
						while(getline(genFileIn, fdLine))
						{
							cout << fdLine << endl;
						}
						genFileIn.clear();
					}
					catch (...)
					{
						cout << "Could not read file!" << endl;
					}
					genFileIn.close();
					break;
				}
				case 4:
				{
					cout << "4" << endl;
					string paramToDelete;
					//cout << "Are you sure?" << endl;
					cout << "Parameter to delete: ";
					cin >> paramToDelete;
				
					genFileOut.open(genFileName);
					// Delete line from file.
					ifstream tempFileIn;
					ofstream tempFileOut;
					tempFileOut.open("temp.txt");
					string fileLine;
					string fileLineToDelete = "Label," + paramToDelete;
					while(getline(genFileIn, fileLine))
					{
						cout << fileLine << endl;
						if (fileLine != fileLineToDelete)
						{
							tempFileOut << fileLine << endl;	
						}
					}
					string genFileLine;
					while(getline(genFileIn, genFileLine))
					{
						genFileLine.replace(genFileLine.find(paramToDelete),paramToDelete.length(),"");
						//cout << genFileLine << endl;
					}
					tempFileOut.close();
					genFileIn.open(genFileName);
					while(getline(genFileIn, genFileLine))
					{
						cout << genFileLine << endl;
					}
					
					break;
				}
				case 5:
				{
					cout << "5" << endl;
					cout << "Exit" << endl;
					return 0;
					break;
				}
				default:
				{
					cout << "Error: input not recognized." << endl;
					break;
				}
			}
		}
		//else
		//{
		//	cout << "Error: input not recognized." << endl;
		//}
	}
	return 0;
}

int editGenerator()
{
	// Generator name
	string genName;
	cout << "Generator name: ";
	cin >> genName;
	string genFileName = genName + ".gen";
	
	// Create file
	ifstream genFileIn;
	ofstream genFileOut;
	genFileIn.open(genFileName);
	if (!genFileIn)
	{
		cout << "Error: unable to open file " << genFileName << "." << endl;
	}
	
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
		cin >> editGeneratorMenuSelection;
		if (cin.fail())
		{
			cout << "Error: input is not recognized." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			//continue;
			//break;
		}
		else
		{
			switch(editGeneratorMenuSelection)
			{
				case 1:
				{
					genFileIn.close();
					genFileOut.open(genFileName, ios::app);
					cout << "Add Text Parameter" << endl;
					string label;
					cout << "Label: ";
					cin >> label;
					genFileOut << "Label" << delimiter << label << endl; // Write label to file
					cout << "File: ";
					string listFileName;
					cin >> listFileName;
					genFileOut << "Filename" << delimiter << listFileName << endl; // Write filename to file.
					genFileOut.seekp(0, genFileOut.beg);					
					genFileOut.close();	
					genFileIn.open(genFileName);				
					break;
				}
				case 2:
				{
					genFileIn.close();
					genFileOut.open(genFileName, ios::app);					
					cout << "Add Random Number Generator Parameter" << endl;
					string label;
					cout << "Label: ";
					cin >> label;
					genFileOut << "Label" << delimiter << label << endl; // Write label to file
				
					// Get min/max numbers.
					int rngMinInput = 1;
					int rngMaxInput = 0;
					while (rngMinInput >= rngMaxInput)
					{
						cout << "Minimum number: ";
						cin >> rngMinInput;
						cout << "Maximum number: ";
						cin >> rngMaxInput;
						if (rngMaxInput > rngMinInput)
						{
							break;
						}
					}
					genFileOut << "Min" << delimiter << rngMinInput << endl;
					genFileOut << "Max" << delimiter << rngMaxInput << endl;
					genFileOut.seekp(0, genFileOut.beg);
					genFileOut.close();
					genFileIn.open(genFileName);
					break;
				}
				case 3:
				{	
					if (!genFileIn.is_open())
					{
						//cout << "Error - file not accessible" << endl;
						//break;
						genFileIn.open(genFileName);					
					}
					else
					{
						genFileIn.clear();
					}
					genFileIn.seekg(0, genFileIn.beg);
					// Iterate through the file and run through each generator.
					string fdLine;
					//int pos = genFileIn.tellg();
					//cout << "pos: " << pos << endl;
					try
					{
						while(getline(genFileIn, fdLine))
						{
							cout << fdLine << endl;
						}
						genFileIn.clear();
					}
					catch (...)
					{
						cout << "Could not read file!" << endl;
					}
					genFileIn.close();
					break;
				}
				case 4:
				{
					string paramToDelete;
					//cout << "Are you sure?" << endl;
					cout << "Parameter to delete: ";
					cin >> paramToDelete;
				
					genFileOut.open(genFileName);
					// Delete line from file.
					ifstream tempFileIn;
					ofstream tempFileOut;
					tempFileOut.open("temp.txt");
					string fileLine;
					string fileLineToDelete = "Label," + paramToDelete;
					while(getline(genFileIn, fileLine))
					{
						cout << fileLine << endl;
						if (fileLine != fileLineToDelete)
						{
							tempFileOut << fileLine << endl;	
						}
					}
					string genFileLine;
					while(getline(genFileIn, genFileLine))
					{
						genFileLine.replace(genFileLine.find(paramToDelete),paramToDelete.length(),"");
						//cout << genFileLine << endl;
					}
					tempFileOut.close();
					genFileIn.open(genFileName);
					while(getline(genFileIn, genFileLine))
					{
						cout << genFileLine << endl;
					}
					
					break;
				}
				case 5:
				{
					cout << "Exit" << endl;
					return 0;
					break;
				}
				default:
				{
					cout << "Error: input not recognized." << endl;
					break;
				}
			}
		}
	}
	return 0;
}

int useGenerator()
{
	// Open the generator file.
	string generatorName;
	string genFileName;
	cout << "Generator name: ";
	cin >> generatorName;
	genFileName = generatorName + ".gen";
	ifstream genFile(genFileName);

	
	int iterations = 0;
	//cout << "Number of values to generate: ";
	//cin >> iterations;


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
	int iter; // Iteration counter. (How many times to run the Generator.)
	//for (iter = 0; iter < iterations; iter++)
	//{
		//genFile.open(genFileName);
		// Initialize all variables.
		i = 0; // Loop counter.
		pos = 0; // Position of string delimiter.
		fileName = "";
		minNum = 0;
	       	maxNum = 1; // In case we have a random number generator.
		randNum = 0;
		fileDataLine[0] = "";
		fileDataLine[1] = "";
		while(!genFile.eof())
		{
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
				//cout << fileDataLine[1] << endl;
				minNum = stoi(fileDataLine[1]);
			}
			else if (fileDataLine[0] == "Max")
			{
				//cout << fileDataLine[1] << endl;
				maxNum = stoi(fileDataLine[1]);
				rng randNumGen(minNum, maxNum);
				randNum = randNumGen.generateNumber(); 
				cout << randNum << endl;
			}
		}
		//genFile.close();
	//}
	return 0;
}


int getGeneratorFileInfo()
{
	// Open the generator file.
	string generatorName;
	string genFileName;
	cout << "Generator name: ";
	cin >> generatorName;
	genFileName = generatorName + ".gen";
	ifstream genFile(genFileName);
	string fileDataLine[2];
	int i = 0;
	string fileName, line;

	// Scroll through it looking for file names that it's dependent on.
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
		if (fileDataLine[0] == "Filename")
		{
			fileName = fileDataLine[1] + ".txt";
			cout << fileName << endl;
		}
		
	}

	return 0;
}


int main()
{
	cout << "Brainstorm 1.0" << endl
	     << "Created by Joshua C. Blow" << endl;
	string choiceStr;
	int choice;
	while (true)
	{
		cin.clear();		
		choice = 0; // Initialize the "choice" variable.
		// Print menu
		cout << "Options" << endl
		     << "1) Launch Generator" << endl
		     << "2) Create New Generator" << endl
		     << "3) Edit Generator" << endl
		     << "4) Get Generator File Info" << endl
		     /*<< "5) Settings" << endl
		     << "6) Exit" << endl*/
		     << "5) Exit" << endl
		     << "> ";
		/*cin >> choiceStr;
		choice = stoi(choiceStr);
		cout << isdigit(choice) << endl;*/
		cin >> choice;
		/*if (isdigit(choice) == true)
		{
			cout << "isdigit(choice) == true" << endl;
			cout << "Input not recognized 1." << endl;
			cin.clear();
		}*/
		if (cin.fail())
		{
			cout << "Error: input is not recognized." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			//continue;
			//break;
		}
		else
		{
			switch (choice)
			{
				case 1:		// Launch generator.
					useGenerator();	
					break;
				case 2:		// Create new generator.
					buildGenerator();
					break;
				case 3:		// Edit generator.
					editGenerator();
					break;
				case 4:		// Get generator file info.
					getGeneratorFileInfo();
					break;
				/*case 5:		// Settings.
					//settings();
					break; */
				case 5:		// Exit.
					exit(0);
				default:
					cout << "Error: input is not recognized." << endl;
					cin.clear();
					break;
			}
		}
	}
	return 0;	
}
