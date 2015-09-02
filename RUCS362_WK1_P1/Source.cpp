// RUCS362_WK1_P1.cpp : Defines the entry point for the console application.
//

#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void ProgramDescription();
void readDataFile1(float[], float[], int&, int&);
float calcArrayAverage(float[], int sizeOfArray);
float highestNumInArray(float[], int sizeOfArray);
int howManyAboveAverage(float[], int sizeOfArray, int arrayAverage);

void EmpOnlySummary(float[], int sizeOfArray);
void famPlanSummary(float[], int sizeOfArray);
void displaySectionBreak();


const int MAX_ENTRIES = 4;

const string FILE_1_NAME = "MEDICAL.txt"; 

int main()
{

	bool arrayFull = false;

	float employeeOnlyList[MAX_ENTRIES];
	float familyPlanList[MAX_ENTRIES];
	int EmpOnlyCounter;
	int famPlanCounter;

	ProgramDescription();


	readDataFile1(employeeOnlyList, familyPlanList, EmpOnlyCounter, famPlanCounter);
	EmpOnlySummary(employeeOnlyList, EmpOnlyCounter);
	displaySectionBreak();
	famPlanSummary(familyPlanList, famPlanCounter);
	
	




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
				cout << "Alert! Maximum number of Entries (" << MAX_ENTRIES << ") for Employee Only Plan has been reached" << endl << endl;;
			}


		}

		else if (planType == 'F' && famPlanCounter < MAX_ENTRIES)
		{

			
			inputFile1 >> famPlan[famPlanCounter];
			famPlanCounter++;
			inputFile1.ignore(100, '\n');

			if (famPlanCounter >= MAX_ENTRIES)
			{
				fArrayFull = true;
				cout << "Alert! Maximum number of Entries (" << MAX_ENTRIES << ") for Family Plan has been reached" << endl << endl;
			}

		}


	}

	inputFile1.close();


}

void EmpOnlySummary(float empOnlyPlan[], int EmpOnlyCounter)
{
	float empOnlyPlanAverage,
		empOnlyplanHgh;
	
	int empAboveAverage = 0;

	if (EmpOnlyCounter > 0){
		cout << "For " << EmpOnlyCounter << " employees with employee only coverage:" << endl;

		empOnlyPlanAverage = calcArrayAverage(empOnlyPlan, EmpOnlyCounter);
		empOnlyplanHgh = highestNumInArray(empOnlyPlan, EmpOnlyCounter);
		empAboveAverage = howManyAboveAverage(empOnlyPlan, EmpOnlyCounter, empOnlyPlanAverage);
		
		cout << fixed << showpoint << setprecision(2);
		cout << "      Average expenses were $" << setw(9) << empOnlyPlanAverage << endl;
		cout << "      Highest expenses were $" << setw(9) << empOnlyplanHgh << endl;
		cout << "      " << empAboveAverage << " Employee(s) expenses were above the average" << endl;
	}

	else cout << "There were NO employees with employee Only coverage." << endl;
}



void famPlanSummary(float famPlan[], int famPlanCounter)
{
	float famPlanAverage,
		  famPlanHgh;

	int famAboveAverage = 0;

	if (famPlanCounter > 0){
		cout << "For " << famPlanCounter << " employees with family coverage:" << endl;

		famPlanAverage = calcArrayAverage(famPlan, famPlanCounter);
		famPlanHgh = highestNumInArray(famPlan, famPlanCounter);
		famAboveAverage = howManyAboveAverage(famPlan, famPlanCounter, famPlanAverage);

		cout << fixed << showpoint << setprecision(2);
		cout << "      Average expenses were $" << setw(9) << famPlanAverage << endl;
		cout << "      Highest expenses were $" << setw(9) << famPlanHgh << endl;
		cout << "      " << famAboveAverage << " Employee(s) expenses were above the average" << endl;
	}

	else cout << "There were NO employees with family Coverage." << endl;


}

float calcArrayAverage(float ArrayName[], int sizeOfArray)
{
	float sumOfArray = 0,
	      averageOfArray = 0; 
	

	for (int index = 0; index < sizeOfArray; index++)
	{
		sumOfArray = sumOfArray + ArrayName[index];
	}

	averageOfArray = sumOfArray / sizeOfArray;
	
	return averageOfArray;
}

float highestNumInArray(float ArrayName[], int sizeOfArray)
{
	float highestValue = 0;

	for (int index = 0; index < sizeOfArray; index++)
	{
		if (ArrayName[index] >  highestValue)
			highestValue = ArrayName[index];
	}
	return highestValue;

}

int howManyAboveAverage(float ArrayName[], int sizeOfArray, int arrayAverage)
{
	int numAboveAverage = 0; 

	for (int index = 0; index < sizeOfArray; index++)
	{
		if (ArrayName[index] >  arrayAverage)
		{
			numAboveAverage++;
		}

	}

	return numAboveAverage;
}

void displaySectionBreak()
{
	cout << endl; 
}