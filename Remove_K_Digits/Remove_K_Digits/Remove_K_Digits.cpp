#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// function prototype
string removeKdigits(string, int);

int main()
{
	string number, newNumber;
	int k;
	bool valid = false;

	do
	{
		cout << "Enter a number: ";
		getline(cin, number);
		cout << "Enter number of digits to remove: ";
		cin >> k;
		if (atoi(number.c_str()) > 0)
			if (number.length < 10002)
				if (atoi(number.c_str()) >= k)
					valid = true;
				else
					cout << "Invalid.  Number must be >= " << k << ". Please reenter number: ";
			else
				cout << "Invalid.  Number is too long.  Please reenter number: ";
		else
			cout << "Invalid.  Number must be postive.  Please reenter number: ";

	} while (!valid);

	newNumber = removeKdigits(number, k);
	
	return 0;
}

string removeKdigits(string num, int k)
{
	int numsRemoved = 0;
	int count = 1;
	bool allRemoved = false;
	char numOne = num[0];
	char numTwo = num[1];
	string newNum;
	
	/*for (int count = 0; count < num.length || !allRemoved; count++)
	{
		numOne = num[count];

	}*/



	do
	{
		if ((k == 1))
			return (newNum = num[1]);
		else if (count == k)
			return newNum;
		else
		{
			numTwo = num[count];
			if (numTwo == numOne)			{
				
				for (int index = 0; index < num.length; index++)
				{
					num[index] = num[index + 1];
					numsRemoved++;
				}
			}
			else if (numTwo > numOne)
			{
				numsRemoved++;
				num[count] = num[count + 1];
			}
		}
			
		
	} while (numsRemoved < k);



}
