// RUCS362_WK1_P1.cpp : Defines the entry point for the console application.
//

#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void ProgramDescription();
void readDataFile1(float[], float[], int&, int&);
float calcArrayAverage(float[], )

void EmpOnlySummary(int numOfEntries);


const int MAX_ENTRIES = 1000;

const string FILE_1_NAME = "MEDICAL.txt"; 

int main()
{

	bool arrayFull = false;

	float employeeOnlyList[MAX_ENTRIES];
	float familyPlanList[MAX_ENTRIES];
	int EmpOnlyCounter;
	int famPlanCounter;

	ProgramDescription();
	//ValidateDataFile1();

	readDataFile1(employeeOnlyList, familyPlanList, EmpOnlyCounter, famPlanCounter);
	EmpOnlySummary(EmpOnlyCounter);


	//for (int patient = 0; patient < EmpOnlyCounter; patient++){
	//	cout << employeeOnlyList[patient] << endl;
	//}

	//for (int patient = 0; patient < famPlanCounter; patient++){
	//	cout << familyPlanList[patient] << endl;
	//}


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


void readDataFile1(float empOnlyPlan[], float famPlan[], int& EmpOnlyCounter, int& famPlanCounter)
{
	ifstream inputFile1;
	char planType;

	bool oArrayFull = false;
	bool fArrayFull = false;

	EmpOnlyCounter = 0;
	famPlanCounter = 0;

	inputFile1.open(FILE_1_NAME);

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

		if (planType == 'O' && EmpOnlyCounter < MAX_ENTRIES)
		{

			//cout << "Single" << endl;
			inputFile1 >> empOnlyPlan[EmpOnlyCounter];
			EmpOnlyCounter++;
			inputFile1.ignore(100, '\n');

			if (EmpOnlyCounter >= MAX_ENTRIES)
			{
				oArrayFull = true;
			}


		}

		else
		{

			//cout << "Family" << endl;
			inputFile1 >> famPlan[famPlanCounter];
			famPlanCounter++;
			inputFile1.ignore(100, '\n');

			if (famPlanCounter >= MAX_ENTRIES)
			{
				fArrayFull = true;
			}

		}


	}

	inputFile1.close();


}

void EmpOnlySummary(int numOfEntries)
{
	if (numOfEntries > 0){
		cout << "For " << numOfEntries << " employees with employee only coverage:" << endl;

	}

	else cout << "There were NO employees with family coverage." << endl;
}