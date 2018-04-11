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

#include "Ant.h"
#include <iostream>
#include "AntBoard.h"
 
Ant::Ant(int x, int y) {
	this->x = x;
	this->y = y;
}

/*antMovement is the function that tracks where the ant should go to next based on its orientation
and controls the movement of the ant in general.The function call receives
totalSteps, which is specified by the user, and a reference to a board object to utilize the AntBoard
functions.
*/
void Ant::antMovement(int totalSteps, AntBoard &board)
{

	int direction = 1;
	/* The direction the ant starts at by default is north. N=1  E =2  S= 3  W=4 */

	// Color starts as w since board design is white by default 
	char color = 'w';
	bool flag = true;

	// first step takes place in antMain() so userStep starts at 2

	int userStep = 2;
	int dummyX, dummyY;

	//this should happen after the board is first displayed with the ant

	while (userStep <= totalSteps)

	{
		dummyX = x;
		dummyY = y;

		//if color is white, make the cell white

		board.designateColor(dummyX, dummyY, color);

		//Update direction Variable  
		if (color == 'w')
		{
			direction++;
			
			// turn 90 degrees to the right if the color is white 
		
		}

		if (color == 'b')
		{
			direction--;

			// turn 90 degrees to the left is the color is black
		}
		
		// since direction can increment continuously, when it's greater than 4, set it back to 1
		// as it's moving clockwise 

		if (direction >4)
		{
			direction = 1;
		}

		// since direction can increment continuously, when it's less than 1, set it back to 4
		// as it's moving counter-clockwise 

		if (direction <1)
		{
			direction = 4;
		}



		//Increment 
		//If direction is 1 or NORTH, you're moving up so the rows are getting smaller
		if (direction == 1)
		{
			x--;
		}

		//If direction is 2 or EAST, you're moving right so the columns are getting larger
		if (direction == 2)
		{
			y++;
		}

		//If direction is 3 or SOUTH, you're moving down so the rows are getting larger
		if (direction == 3)
		{
			x++;
		}

		//If direction is 4 or WEST, you're moving left so the columns are getting smaller
		if (direction == 4)
		{
			y--;
		}

		//Checkbounds 

		// since you're incrementing and decrementing x and y above, if it goes outside the matrix bounds then check the
		//bounds

		// x y are not out of bounds: 

		if ((x < board.getRows() && x >= 0) && (y < board.getColumns() && y >= 0))
		{
			flag = true;	
		}

		else
		{
			//When the x y are out of bounds 

			flag = false;
			
			//make the ant rotate 180 degrees if it's at the board edge or board corner

			if (direction == 1)
			{
				direction = 3;
			}


			if (direction == 2)
			{
				direction = 4;
			}

			if (direction == 3)
			{
				direction = 1;
			}


			if (direction == 4)
			{
				direction = 2;
			}

			//Reverse the previous move so that if the ant is a step away from being out of bounds
			//it stays in its current cell, but just reorients 180 degrees 

			// if the current rows in greater than the max 
			if (x >= board.getRows())
			{
				x--;
			}

			// if the current row is less than 0 
			if (x < 0)
			{
				x++;
			}

			// if the current column is less than 0
			if (y < 0)
			{
				y++;
			}
			// if the current column is greater than the max 
			if (y >= board.getColumns())
			{
				y--;
			}


		}

		//get color of the cell that the ant is about to move to (the change x,y coordinates)

		color = board.getColorAt(x, y);

		//swap cell color that the ant is going to move away from 

		board.designateColor(dummyX, dummyY, '*');
			
		// set ant position
		board.setAntPosition(x, y);
	

		//increment steps taken 

		userStep++;

		//print board 

		board.print();
	}

}
