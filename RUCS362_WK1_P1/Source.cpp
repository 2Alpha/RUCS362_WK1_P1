// RUCS362_WK1_P1.cpp : Defines the entry point for the console application.
//

#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void ProgramDescription();
void ValidateDataFile1(); 
char SortDataByPlan(); 

const int MAX_ENTRIES = 1000;

const string FILE_1_NAME = "MEDICAL.txt"; 

int main()
{

	bool arrayFull = false;

	ProgramDescription();
	ValidateDataFile1();


	system("PAUSE");
	return 0;
}

void ProgramDescription()
{
	cout << "Program to calculate and Display the following:" << endl; 
	cout << " 1. The number of Employees with Employee Only Health Coverage" << endl;  
	cout << " 2. The average expenses for Employees with Employee Only Health Coverage" << endl;
	cout << " 3. The highest expenses for Employees with Employee Only Health Coverage" << endl;
	cout << " 4. The number of Employees with Familiy Health Coverage" << endl;
	cout << " 5. The average expenses for Employees with Family Health Coverage" << endl;
	cout << " 6. The highest expenses for Employees with Family Health Coverage" << endl;
}

void ValidateDataFile1()
{
	ifstream inputFile1;
	char planType;

	inputFile1.open(FILE_1_NAME);

	bool oArrayFull = false;
	bool fArrayFull = false;

	int oCounter = 0;
	int fCounter = 0;

	float employeeOnly[MAX_ENTRIES];
	float familyplan[MAX_ENTRIES];

	//check for error  
	if (inputFile1.fail())
	{
		cout << endl;
		cout << "Uh Oh!!" << endl; // As my 2 year old son likes to say when something isn't right 
		cerr << "Error Opening File named \"" << FILE_1_NAME << "\"" << endl;
		system("PAUSE");
		exit(5);
	}

	else
	{
		cout << endl;
		cout << "Success opening file named \"" << FILE_1_NAME << "\"" << endl;
		cout << endl;
	}



	while (inputFile1)       // successful read (data on line)
	{                                       // and array not full on last pass


		inputFile1 >> planType;  // read age into array

		if (planType == 'O' && oCounter < MAX_ENTRIES)
		{

			cout << "Single" << endl;
			inputFile1 >> employeeOnly[oCounter];
			oCounter++;
			inputFile1.ignore(100, '\n');

			if (oCounter >= MAX_ENTRIES)
			{
				oArrayFull = true;
			}


		}

		else
		{

			cout << "Family" << endl;
			inputFile1 >> familyplan[fCounter];
			fCounter++;
			inputFile1.ignore(100, '\n');

			if (fCounter >= MAX_ENTRIES)
			{
				fArrayFull = true;
			}

			//ount++;                            // increment patient count
			//patientFile.ignore(100, '\n');     // skips remaining data on line

			//patientFile >> patientId >> sex;    // try to read data on next line
		}


	}

	inputFile1.close();

	int patient;
	for (patient = 0; patient < oCounter; patient++)

		{
			cout << endl; 
			cout << employeeOnly[patient] << endl;
			patient++;
		}

}