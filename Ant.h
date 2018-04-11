
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

//Ant Class has x and y coordinates as private members and contains the ant movement function. 

#ifndef ANT_H
#define ANT_H
#include "AntBoard.h"

class Ant
{
private:
	int x;	//store x coordinate of ant's position
	int y;	//store y coordinate of ant's position

public:

	
	Ant(int x, int y);

	void antMovement(int totalSteps, AntBoard &board);


};

#endif

