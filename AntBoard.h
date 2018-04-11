
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
/* Ant Board Class creates the matrix, has rows and columns as its data members, and contains functions
that allow the ant movement function to designate color, retrieve color, and set ant position. This class is also responsible 
for printing the current state of the board.
*/

#ifndef ANTBOARD_H
#define ANTBOARD_H
#include <iostream>

class AntBoard
{

private:
	char **matrix; 
	int rows;
	int columns;

public:

	AntBoard(int rows, int columns);
	AntBoard();
	void designateColor(int x, int y, char color); 
	char getColorAt(int x, int y); 		// returns what color is cell x, y
	void setAntPosition(int x, int y);
	void print();
	int getRows();
	int getColumns();
	~AntBoard(); 
	
};
#endif

