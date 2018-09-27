/****************************************************************
** Program name: printBoard.cpp
** Author: Ben Fridkis
** Date: 4/10/2017
** Description: printBoard function definitions. Prints the
				contents of a 2D array. If additional parameters 
				are passed, also calls the lastMovePrintOut 
				function of the Ant class to provide step details 
				for Langton's Ant simulation.
******************************************************************/

#include "Ant.hpp"
#include<iostream>
using std::cout;
using std::endl;

/*************************************
			   printBoard
*************************************/
void printBoard(char** array, int numRows, 
	int numCols)
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			cout << array[i][j];
		}
        cout << endl;
	}
}
/*************************************
  printBoard - w/last move details
*************************************/
void printBoard(char** array, int stepNumber, 
	int numRows, int numCols, const Ant& thisAnt)
{
	cout << "\nStep " << stepNumber << ":" << endl;
    thisAnt.lastMovePrintOut();
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			cout << array[i][j];
		}
        cout << endl;
	}
}