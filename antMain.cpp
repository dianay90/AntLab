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

//This is antMain which displays the menu to the user and allows the user to start or exit the ant game. 

#include "AntBoard.h"
#include "Ant.h"
#include "inputValidation.h"
#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

int main()

{
	
	Menu m(2); 

	cout << endl;
	cout << endl;
	cout << endl;

	//start Menu

	m.addMember("Welcome to Langton's Ant Simulation.");
	m.addMember("1.Start");
	m.addMember("2. Quit");

	m.displayMenu();
	int choice= m.verifyAndReturn();

		if (choice == 1)
		{

			int x, y, totalSteps = 0;
			int rows, columns;
			//string userString; 



			cout << "Enter the number of rows you would like. The maximum number of rows you can enter is 80." << endl;
			//cin >> rows; 

			rows = inputValidation();



			cout << "Enter the number of columns you would like. The maximum number of columns you can enter is 80." << endl;
			//cin >> columns; 


			columns = inputValidation();


			AntBoard board(rows, columns);

			//cout << "Please enter your first matrix coordinate like so it looks like this matrix[x][y]" << endl; 
			cout << "Please provide row and column coordinates for your ant." << endl;
			cout << endl; 
				cout << "Enter the row you would like your ant to be in. The maximum row value is 80." << endl;
			
			//cin >> x; 


			x = inputValidation();
			x = x - 1; //Whatever user enter, subtract one since in a 2D array rows and columns start at 0

			cout << "Enter the column you would like your ant to be in. The maximum column value is 80." << endl;
		
			//cin >> y; 

			y = inputValidation();
			y = y - 1;

			cout << "How many steps do you want the ant to move?" << endl;
			//cin >> totalSteps; 


			totalSteps = inputValidation();
		 

			//Ant ant(x, y, board);
			Ant ant(x, y);

			//sets the ant at the first user entered coordinate

			board.setAntPosition(x, y);

			//print the current state of the board
			board.print();

			//cellular automation begins 

			ant.antMovement(totalSteps, board);


		}


	if (choice ==2)
	{
		cout << "You have exited." << endl; 

	
	}


	return 0;
}