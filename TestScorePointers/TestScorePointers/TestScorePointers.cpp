/*
	Author: William A. Clark, Crestworld Studios
	File Name: TestScorePointers.cpp
	Description: This program is demonstrating the use of dynamic arrays using pointers.  This program will ask the user
				 how many test scores they want to enter (no limit, so be careful) and they enter each test score.  This
				 program will then load the scores into a dynamic array, sort the array in ascending order, calculate the
				 average score, remove the lowest score, and display the results.	
*/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include<iomanip>
using namespace std;

// Function Prototype
void sort(double*, int);
double average(double*, int);
int removeLowest(double*, int);

int main()
{
	//	Declaring Variables
	int numTestScores = 0;				// the number of test scores
	double testAverage = 0;				// the test score average
	double* testScoreptr = nullptr;		// to point to an array of doubles, 

	// display program description
	cout << "Test Scores Program\tWilliam A. Clark\tCrestworld Studios";
	cout << "\n\nThis is demonstration of dynamic arrays via pointers.";
	cout << "\n\nThis program will ask the user how many test scores they want to enter";
	cout << "\n(no limit, so be careful).  The user then enters each test score.";
	cout << "\nThe scores will be loaded a dynamic array and then perform the following tasks:";
	cout << "\n\n1. Display the scores ascending order.";
	cout << "\n2. Calculate and display the average of the scores.";
	cout << "\n3. Remove the lowest score and redisplay the sorted scores with their new average.";

	// Pause for next step
	cout << "\n\nPress any key to start the program...";
	cin.get();
	
	// get the number of test scores 
	cout << "\nHow many test scores are you entering? ";
	cin >> numTestScores;

	//validate that input
	while (numTestScores < 0)
	{
		cout << "\nInvaid Value!  You must enter a whole number greater than 0.";
		cout << "\nHow many test scores will you enter? ";
		cin >> numTestScores;
		cout << "\n";
	}

	// allocate an array to hold the test scores
	testScoreptr = new double[numTestScores];

	// fill the array with test scores 
	cout << "\n";
	for (int i = 0; i < numTestScores; i++)
	{
		// get a test score 
		cout << "Enter test score #" << (i + 1) << ": ";
		// cin >> testScoreptr[i];         // array notation
		cin >> *(testScoreptr + i);       // pointer notation

		// validate the input
		while (*(testScoreptr + i) < 0)  // pointer notation
		{
			cout << "\nNegative scores are not allowed.";
			cout << "\nEnter anther scores for this test: ";
			cin >> *(testScoreptr + i);  // pointer notation
			cout << "\n";
		}
	}
		
	// sort the test scores
	sort(testScoreptr, numTestScores);

	// get the average of the test scores
	testAverage = average(testScoreptr, numTestScores);

	// Pause for next step
	cout << "\nPress any key to display your scores in ascending order and their average...";
	cin.get();
	
	// display the resulting data 
	cout << "\n\nScores";
	cout << "\n------";

	for (int j = 0; j < numTestScores; j++)
		cout << fixed << setprecision(2) << setw(6) << "\n" << *(testScoreptr + j);

	cout << "\n\nAverage Score: " << setprecision(2) << fixed << testAverage;

	// Pause for next step
	cout << "\n\nPress any key to remove the lowest score and redisplay the scores and the new average...";
	cin.get();
	
	// remove lowest test score
	numTestScores = removeLowest(testScoreptr, numTestScores);

	// get the average of the testscores
	testAverage = average(testScoreptr, numTestScores);

	// display the new resulting data 
	cout << "\n\nScores";
	cout << "\n------";

	for (int j = 0; j < numTestScores; j++)
		cout << fixed << setprecision(2) << setw(6) << "\n" << *(testScoreptr + j);

	cout << "\n\nAverage Score: " << setprecision(2) << fixed << testAverage;

	//free the dynamically allocated memory
	delete[]testScoreptr;
	testScoreptr = nullptr;

	//	Make sure we place the end message on a new line
	cout << endl;

	/*cout << "\n\nPress any key to continue to end program...";
	cin.get();*/

	return 0;
}

// the sort function performs a selection sort on  an array pointed to by the 
// score parameter into ascending order. the size param holds the number of elements 
void sort(double* score, int size)
{
	int startScan, minIndex;
	double minValue;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = *(score + startScan);						// pointer notation

		for (int index = startScan + 1; index < size; index++)
		{
			if (*(score + index) < minValue)
			{
				minValue = *(score + index);                    // pointer notation
				minIndex = index;								// pointer notation
			}
		}
		*(score + minIndex) = *(score + startScan);             // pointer notation
		*(score + startScan) = minValue;						// pointer notation
	}



}


// The average function calculates and returns the average of the values stored in 
// the array passed into the scores param. The param numScorees holds the number of 
// elements in the array
double average(double* score, int numScores)
{
	double total = 0;					// initialize accumulator

	for (int k = 0; k < numScores; k++)
		total += *(score + k);			// pointer notation
	return (total / numScores);

}

// This function will remove the lowest score from the sorted array retrning the array
// with ot the lowest score and decrementing the numScores count by 1.
int removeLowest(double* score, int numScores)
{
	for (int index = 0; index < numScores; index++)
	{
		*(score + index) = *(score + (index + 1));  // Shifting the array to the left removing lowest score
	}

	return --numScores;
}