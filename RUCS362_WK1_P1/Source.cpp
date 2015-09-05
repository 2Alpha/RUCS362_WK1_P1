
//***************************************************************************
//  FILENAME:	 AllenAssn1.cpp
//  DESCRIPTION: This program will read, compute and display the results of 
//               a text file containing Medical Plan type and expenses
//  DATE:        9/1/15
//  CLASS/TERM:  CS362_X40_Data Structures - CU_CS362 - XIN_X40_15F8W1
//  DESIGNER:	 Andrae Allen
//  FUNCTIONS:	 main - reads values, performs calculations, & displays results
//               ProgramDescription - Displays a brief discription of the program
//               readDataFile1 - reads data from txt file MEDICAL.txt data includes plan
//				 type and expenses
//				 calcArrayAverage - Calculates the numerical average of an array 
//				 highestNumInArray - Calculates the highest number in an array
//				 howManyAboveAverage - Calculates how many numbers are above the average
//				 EmpOnlySummary- sumarizes the plan results for employees with employee 
//				 only coverage
//				 famPlanSummary - sumarizes the plan results for employees with family coverage
//               displaysectionBreak - Creates a section break (space) on the console  
//***************************************************************************

#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void ProgramDescription();
void readDataFile1(float[], float[], int&, int&);
float calcArrayAverage(float[], int sizeOfArray);
float highestNumInArray(float[], int sizeOfArray);
int howManyAboveAverage(float[], int sizeOfArray, float arrayAverage);

void EmpOnlySummary(float[], int sizeOfArray);
void famPlanSummary(float[], int sizeOfArray);
void displaySectionBreak();


const int MAX_ENTRIES = 500; // Max entries for either plan

const string FILE_1_NAME = "MEDICAL.txt"; // File name for input file

int main()
{
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

//*************************************************************************
//  FUNCTION:	  ProgramDescription
//  DESCRIPTION:  Displays a brief discription of the program
//  INPUT:        Parameters:  None
//  OUTPUT: 	  Return value: None
//*************************************************************************

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

//*************************************************************************
//  FUNCTION:	  readDataFile1
//  DESCRIPTION:  reads data from txt file MEDICAL.txt data includes plan
//				  type and expenses
//  INPUT:        Parameters:  empOnlyPlan - Array for holding emploee only plan expenses 
//                             famPlan - Array for holding family plan expenses 
//							   EmpOnlyCounter - counts number of employees with employee only plan
//							   famPlanCounter - counts number of employees with family plan
//  OUTPUT: 	  Return value: None
//*************************************************************************

void readDataFile1(float empOnlyPlan[], float famPlan[], int& EmpOnlyCounter, int& famPlanCounter)
{
	ifstream inputFile1;       //file stream variable
	char planType;             // plan type 

	EmpOnlyCounter = 0;        // employee only plan counter
	famPlanCounter = 0;        // family plan counter

	inputFile1.open(FILE_1_NAME);

	// try to read specified data file 
	if (inputFile1.fail())
	{
		cout << endl;
		cout << "Uh Oh!!" << endl; // As my 2 year old son likes to say when something isn't right 
		cerr << "Error Opening File named \"" << FILE_1_NAME << "\"" << endl;
		system("PAUSE");
		exit(5);
	}

	// If success opening specified file show success message and continue 
	else
	{
		cout << endl;
		cout << "Success opening file named \"" << FILE_1_NAME << "\"" << endl;
		cout << endl;
	}

	// read until end of file
	while (inputFile1)       
	{
		inputFile1 >> planType; 

		//If Employee Only Plan Type  
		if (planType == 'O' && EmpOnlyCounter < MAX_ENTRIES)
		{		
			inputFile1 >> empOnlyPlan[EmpOnlyCounter];
			EmpOnlyCounter++;
			inputFile1.ignore(100, '\n');

			if (EmpOnlyCounter >= MAX_ENTRIES)
			{;
				cout << "Alert! Maximum number of Entries (" << MAX_ENTRIES << ") for Employee Only Plan has been reached" << endl << endl;;
			}
		}

		//If Family Plan type
		else if (planType == 'F' && famPlanCounter < MAX_ENTRIES)
		{			
			inputFile1 >> famPlan[famPlanCounter];
			famPlanCounter++;
			inputFile1.ignore(100, '\n');

			if (famPlanCounter >= MAX_ENTRIES)
			{
				cout << "Alert! Maximum number of Entries (" << MAX_ENTRIES << ") for Family Plan has been reached" << endl << endl;
			}
		}
	}

	inputFile1.close();


}

//*************************************************************************
//  FUNCTION:	  EmpOnlySummary
//  DESCRIPTION:  sumarizes the plan results for employees with employee 
//				  only coverage
//  INPUT:        Parameters:  empOnlyPlan - employee only plan array
//                             EmpOnlyCounter - counts number of employees with employee only plan
//  CALLS TO:	  calcArrayAverage, highestNumInArray, howManyAboveAverage
//  OUTPUT: 	  Return value: None
//*************************************************************************

void EmpOnlySummary(float empOnlyPlan[], int EmpOnlyCounter)
{
	float empOnlyPlanAverage,    // Employee only plan average
		  empOnlyplanHgh;		 // Highest number in employee only plan array
	
	int empAboveAverage = 0;     // How many employee are above the average expense

	// If number of employees with employee only plan is greater than zero 
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

	// If number of employee with employee only plan is zero
	else cout << "There were NO employees with employee Only coverage." << endl;
}


//*************************************************************************
//  FUNCTION:	  famPlanSummar
//  DESCRIPTION:  Sumarizes the plan results for employees with family coverage
//  INPUT:        Parameters:  famPlan - famaily plan array
//                             famPlanCounter - counts number of employees with family plan
//  CALLS TO:	  calcArrayAverage, highestNumInArray, howManyAboveAverage
//  OUTPUT: 	  Return value: None
//*************************************************************************

void famPlanSummary(float famPlan[], int famPlanCounter)
{
	float famPlanAverage,     // family plan average
		  famPlanHgh;         // family plan high 

	int famAboveAverage = 0;  // How many employees are above the average expense

	// If number of employees with family plan is greater than zero
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

	// If number of employee with family plan is zero
	else cout << "There were NO employees with family Coverage." << endl;


}

//*************************************************************************
//  FUNCTION:	  calcArrayAverage
//  DESCRIPTION:  Calculates the numerical average of an array
//  INPUT:        Parameters:  ArrayName - the name of the array being averaged
//                             sizeOfArray - size of the array being averaged 
//  OUTPUT: 	  Return value: averageOfArray - average of the array 
//*************************************************************************

float calcArrayAverage(float ArrayName[], int sizeOfArray)
{
	float sumOfArray = 0,       // sum of the array
	      averageOfArray = 0;	// average of the array 
	

	for (int index = 0; index < sizeOfArray; index++)
	{
		sumOfArray = sumOfArray + ArrayName[index];
	}

	averageOfArray = sumOfArray / sizeOfArray;
	
	return averageOfArray;
}

//*************************************************************************
//  FUNCTION:	  highestNumInArray
//  DESCRIPTION:  Calculates the highest number in an array
//  INPUT:        Parameters:  ArrayName - the name of the array being averaged
//                             sizeOfArray - size of the array being averaged 
//  OUTPUT: 	  Return value: highestValue- the highest value in the array
//*************************************************************************

float highestNumInArray(float ArrayName[], int sizeOfArray)
{
	float highestValue = 0; // the highest value in the array

	for (int index = 0; index < sizeOfArray; index++)
	{
		if (ArrayName[index] >  highestValue)
			highestValue = ArrayName[index];
	}
	return highestValue;

}

//*************************************************************************
//  FUNCTION:	  Calculates how many numbers are above the average
//  DESCRIPTION:  Computes value of a base number raised to an exponent
//  INPUT:        Parameters:  ArrayName - the name of host array 
//                             sizeOfArray - size of the host 
//							   average - average of specified array
//  OUTPUT: 	  Return value: numAboveAverage - how many numbers are above the average
//*************************************************************************

int howManyAboveAverage(float ArrayName[], int sizeOfArray, float arrayAverage)
{
	int numAboveAverage = 0; // how many numbers are above the average

	for (int index = 0; index < sizeOfArray; index++)
	{
		if (ArrayName[index] >  arrayAverage)
		{
			numAboveAverage++;
		}

	}

	return numAboveAverage;
}

//*************************************************************************
//  FUNCTION:	  displaySectionBreak
//  DESCRIPTION:  Creates a section break (space) on the console
//  INPUT:        Parameters:  None
//  OUTPUT: 	  Return value: None
//*************************************************************************

void displaySectionBreak()
{
	cout << endl; 
}