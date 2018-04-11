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
/* Menu Class displays menu, allows user to add menu options, and assesses the input entered by the user 
 * with assistance from the inputValidation function. 
*/

#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include "inputValidation.h"

using namespace std;

class Menu
{

private:

	vector<string>m;
	int number; 

public:

	Menu(int param);
	void addMember(string title);
	void displayMenu();
	void setNumberofOptions(int param);
	int verifyAndReturn();
};


#endif
