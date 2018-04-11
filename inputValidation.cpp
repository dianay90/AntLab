
/*********************************************************************
** Program name: Langton's Ant Algorithm
** Author: Diana Oh
** Date: 4/16/2017
** Description: This program simulates Langton's Ant Algorithm, which is a cellur automation algorithm that seeks
*to move an ant according to two principles: if an ant lands on a white square, it turns ninety degrees, flips the
*color of the square to black, and moves forward one unit. If an ant lands on a black square it turns ninety degrees,
*flips the color of the square to white, and moves forward one unit.
*
*This program can be run using a makefile.

*********************************************************************/
/* Input validation function validates user input and returns an int if the user input is valid. Otherwise, the function
 * prompts the user to enter a valid response.
*/

#include <iostream>
#include <string>
using namespace std;
#include "inputValidation.h"



int inputValidation()
{
	bool flag = false;
	string userString;
	int number;

	while (flag == false)
	{
		getline(cin, userString);

		for (int index = 0; index < userString.length(); index++)

		{
			// if the input is a digit 
			if (isdigit(userString[index]))
			{
				//convert that number to an integer data type
				number = stoi(userString);
				if ((number > 0) && (number < 81))
				{
					return number;
				}
				
				else
				{
					cout << "Input is invalid. Please enter a valid number." << endl; 
				}
			}

			else if (!(isdigit(userString[index])))
			{
				std::cout << "Input is invalid. Please enter a valid number." << std::endl;
				flag = false;

			}

		}
	}
}

