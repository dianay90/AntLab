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
/* Menu Class displays menu, allows user to add menu options, and verifies the input entered by the user
* via the inputValidation function.
*/

#include <iostream>
#include "Menu.h"
#include "inputValidation.h"
using namespace std;
#include <string>

Menu::Menu(int param)
{
	vector<string>m;
	setNumberofOptions(param);


}

//The addMember function adds options to the menu vector when the options are passed as arguments to the function.

void Menu::addMember(string title)

{

	m.push_back(title);
}

//displayMenu function displays the vector's contents
void Menu::displayMenu()
{
	for (int i = 0; i < m.size(); i++)
		cout << m[i] << endl;

}


/*Sets the number of options you want the menu to have. This is done when you pass the number of options you want
as an argument. */
void Menu::setNumberofOptions(int param)
{

	number = param; 
}


/*Verify the user selection from the menu options and make sure the user selected something from the actual menu.
 If they did, the function returns the user input as an integer.*/
int Menu::verifyAndReturn()

{
	//string userInput;
	int userInput2;
	bool flag;

	while (flag == false)

	{
		cout << endl; 
		cout << "Please make a selection from the menu options above." << endl;
		userInput2 = inputValidation();

		if ((userInput2 > 0) && (userInput2 <= number))
		{
			return userInput2;
		}

		else
		{
			flag = false;
		}

	}
}

