
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

#include "AntBoard.h"
#include <iostream> 



AntBoard::AntBoard(int rows, int columns)
{

	this->rows = rows;
	this->columns = columns;

	// allocating memory to 2d array
	matrix = new char*[rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = new char[columns];


	// initialize all cells as blanks
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = '.';

		}
	}
}

//This function prints the current state of the board

void AntBoard::print()
{
	 

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << matrix[i][j];

		}
		std::cout << std::endl;


	}
	// space out the board 

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

/* This function manages the color of the cells. The color argument remembers the color of the current cell the ant is on, 
 * while the x and y arguments are used to swap the color of the cell the ant moves away from. 
 */
void AntBoard::designateColor(int x, int y, char color) {
	if (matrix[x][y] == '.') {
		matrix[x][y] = '#';
	}
	else {
		matrix[x][y] = '.';
	}

	if (color == 'w')
	{
		matrix[x][y] == '.';
	}

	if (color == 'b')
	{
		matrix[x][y] == '#';
	}
}

/* Retrieve the color of the cell before the ant moves to it. X and y coordinates of the cell  the ant is about to move to are 
 * passed as an argument to the function. The function returns 'w' or 'b' to the color 
variable in the antMovement function. 
*/

char AntBoard::getColorAt(int x, int y) {
	char white = 'w';
	char black = 'b';

	if (matrix[x][y] == '.') {
		return white;
	}
	else {
		return black;
	}
}

/* This function sets the ant position based on the x, y arguments given. The ant position is set based on the 
/x, y coordinates passed as arguments in the function.*/

void AntBoard::setAntPosition(int x, int y) {
	matrix[x][y] = '@';
}

// The is a getter function that returns rows. 
int AntBoard::getRows() {
	return rows;
}

// The is a getter function that returns columns.
int AntBoard::getColumns() {
	return columns;
}


//This is the destructor that deletes the dynamically allocated 2D array. 
AntBoard::~AntBoard()
{

	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}