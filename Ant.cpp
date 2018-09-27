/*********************************************************************
 ** CS161 - Project 1
 ** Author: Benjamin Fridkis
 ** Date: 3/1/2017
 ** Description: 
 *********************************************************************/

#include "Ant.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*****************************************************
					 Constructor
  Instantiates object and sets Ant object's (starting)
  direction based on antStartDir parameter. (NORTH,
  SOUTH, EAST, and WEST are enumerated values. See
  ant.hpp). Sets antSpaceIsWhite flag true (as all
  board spaces begin white).
******************************************************/
Ant::Ant(int antStartDir)
{
    if 		(antStartDir == 1){setAntDirection(NORTH);}
	else if (antStartDir == 2){setAntDirection(SOUTH);}
	else if (antStartDir == 3){setAntDirection(EAST);}
	else if (antStartDir == 4){setAntDirection(WEST);}
	
	antSpaceIsWhite = true;
}
/****************************
        getAntXCoord
   Gets Ant's X coordinate.
 ****************************/
int Ant::getAntXCoord() const
{
    return antXCoord;
}
/****************************
        getAntYCoord
   Gets Ant's Y coordinate.
 ****************************/
int Ant::getAntYCoord() const
{
    return antYCoord;
}
/****************************
        getAntSteps
  Gets Ant's number of steps
     (antSteps) variable.
 ****************************/
int Ant::getAntSteps() const
{
    return antSteps;
}
/******************************************
			  getAntDirection
  Gets Ant's current heading (antDirection)
  variable. (Uses enumerated "Direction" 
  values. See Ant.hpp.)
 ******************************************/
Direction Ant::getAntDirection() const
{
    return antDirection;
}
/*********************************
        getAntSpaceIsWhite
  Gets Ant's current space color
      flag (antSpaceIsWhite).
 *********************************/
bool Ant::getAntSpaceIsWhite() const
{
    return antSpaceIsWhite;
}
/******************************************
			getLastMoveMarker
  Gets Ant's lastMoveMarker member
  variable. (Uses enumerated "LastMove" 
  values. See Ant.hpp.)
 ******************************************/
LastMove Ant::getLastMoveMarker() const
{
    return lastMoveMarker;
}
/****************************
        setAntXCoord
   Sets Ant's X coordinate.
 ****************************/
void Ant::setAntXCoord(int xCoord)
{
    antXCoord = xCoord;
}
/****************************
        setAntYCoord
   Sets Ant's Y coordinate.
 ****************************/
void Ant::setAntYCoord(int yCoord)
{
    antYCoord = yCoord;
}
/****************************
        setAntSteps
  Sets Ant's number of steps
     (antSteps) variable.
 ****************************/
void Ant::setAntSteps(int numSteps)
{
    antSteps = numSteps;
}
/******************************************
			  setAntDirection
  Sets Ant's current heading (antDirection)
  variable. (Uses enumerated "Direction" 
  values. See Ant.hpp.)
 ******************************************/
void Ant::setAntDirection(Direction antDirection)
{
    this->antDirection = antDirection;
}
/**********************************
        setAntSpaceIsWhite
  Sets Ant's current space color
  flag (antSpaceIsWhite). Toggles
  value based on isWhite parameter.
 **********************************/
void Ant::setAntSpaceIsWhite(bool isWhite)
{
	antSpaceIsWhite = true;
	
    if(!isWhite)
	{antSpaceIsWhite = false;}
}
/******************************************
			setLastMoveMarker
  Sets Ant's lastMoveMarker member
  variable. (Uses enumerated "LastMove" 
  values. See Ant.hpp.)
 ******************************************/
void Ant::setLastMoveMarker(LastMove 
	lastMoveMarker) 
{
    this->lastMoveMarker = lastMoveMarker;
}
/*************************************************************
					   void moveAnt
  Sets Ant's current space back to white or black, then moves
           Ant based on Ant's current direction.
 *************************************************************/
void Ant::moveAnt(char** array, int& currX, int& currY, 
	int numRows, int numCols)
{
	//Immediately before the Ant moves, the space that it 
	//currently occupies is set back to it's status 
	//("white or black") as of the end of its previous
	//move. 
	if (antSpaceIsWhite){array[currX][currY] = ' ';}

	else if (!antSpaceIsWhite){array[currX][currY] = '#';}	
    
	//Direction specific move functions are called depending
	//on the direction the Ant faces at the end of its 
	//previous move.
	if (antDirection == NORTH)
	{moveAntNorth(array, currX, currY, numRows, numCols);}
    
    else if (antDirection == SOUTH)
    {moveAntSouth(array, currX, currY, numRows, numCols);}
    
    else if (antDirection == EAST)
    {moveAntEast(array, currX, currY, numRows, numCols);}
    
    else if (antDirection == WEST)
    {moveAntWest(array, currX, currY, numRows, numCols);}
	
	array[currX][currY] = '@';
}
/****************************************************
				  void moveAntNorth
	    Function to move Ant "North" or Up.
 ****************************************************/
void Ant::moveAntNorth(char** array, int& currX, int& 
	currY,const int numRows, const int numCols)
{
	//If Ant is at the top of the board (i.e. row 0),
	//Ant "wraps" the board and ends at bottom of 
	//board (i.e. last row).
    if (currX == 0)
    {
		//numRows is offset by 1 because
		//array values begin at 0.
        antXCoord = numRows - 1;
        currX = numRows - 1;
    }
	//Otherwise, decrement Ant's row number
	//(x position) by one, to move the Ant "North"
	//or up.
    else 
	{
		antXCoord -= 1;
		currX -= 1;
	}
	
    //If the new Ant space is black, the Ant turns
	//left to face "West". Update antDirection 
	//accordingly, set the antSpaceIsWhite marker
	//true (to toggle the black space to white), and
	//set the lastMoveMarker to NORTH_BLACK (enumerated
	//value, see Ant.hpp).
    if (array[currX][currY] == '#')
    {
        setAntDirection(WEST);
        setAntSpaceIsWhite(true);
        setLastMoveMarker(NORTH_BLACK);
    }
	//Else if the new Ant space is white, the Ant turns
	//right to face "east". Update antDirection 
	//accordingly, set the antSpaceIsWhite marker
	//true (to toggle the white space to black), and
	//set the lastMoveMarker to NORTH_WHITE (enumerated
	//value, see Ant.hpp).
    else if (array[currX][currY] == ' ')
    {
        setAntDirection(EAST);
        setAntSpaceIsWhite(false);
        setLastMoveMarker(NORTH_WHITE);
    }
}
/****************************************************
				  void moveAntSouth
	    Function to move Ant "South" or down.
 ****************************************************/
void Ant::moveAntSouth(char** array, int& currX, int&
	currY, const int numRows, const int numCols)
{
	//If Ant is at the bottom of the board (i.e. row 
	//numRows - 1), Ant "wraps" the board and ends at top 
	//of board (i.e. first row).
    if (currX == numRows - 1)
    {
        antXCoord = 0;
        currX = 0;
    }
	//Otherwise, increment Ant's row number
	//(x position) by one, to move the Ant "South"
	//or down.
    else 
	{
		antXCoord += 1;
		currX += 1;
	}
	
	//If the new Ant space is black, the Ant turns
	//left to face "East". Update antDirection 
	//accordingly, set the antSpaceIsWhite marker
	//true (to toggle the black space to white), and
	//set the lastMoveMarker to SOUTH_BLACK (enumerated
	//value, see Ant.hpp).
    if (array[currX][currY] == '#')
    {
        setAntDirection(EAST);
        setAntSpaceIsWhite(true);
        setLastMoveMarker(SOUTH_BLACK);
    }
	//Else if the new Ant space is white, the Ant turns
	//right to face "West". Update antDirection 
	//accordingly, set the antSpaceIsWhite marker
	//true (to toggle the black space to white), and
	//set the lastMoveMarker to SOUTH_WHITE (enumerated
	//value, see Ant.hpp).
    else if (array[currX][currY] == ' ')
    {
        setAntDirection(WEST);
        setAntSpaceIsWhite(false);
        setLastMoveMarker(SOUTH_WHITE);
    }
}
/****************************************************
				  void moveAntEast
	    Function to move Ant "East" or right.
 ****************************************************/
void Ant::moveAntEast(char** array, int& currX, int& 
	currY, const int numRows, int numCols)
{
	//If Ant is at the far-right of the board (i.e. column 
	//numCols - 1), Ant "wraps" the board and ends at 
	//far-left of board (i.e. first column).
    if (currY == numCols - 1)
    {
        antYCoord = 0;
        currY = 0;
    }
	//Otherwise, increment Ant's column number
	//(y position) by one, to move the Ant "East"
	//or right.
    else 
	{
		antYCoord += 1;
		currY += 1;
	}
    
	//If the new Ant space is black, the Ant turns
	//left to face "North". Update antDirection 
	//accordingly, set the antSpaceIsWhite marker
	//true (to toggle the black space to white), and
	//set the lastMoveMarker to EAST_BLACK (enumerated
	//value, see Ant.hpp).
    if (array[currX][currY] == '#')
    {
        setAntDirection(NORTH);
        setAntSpaceIsWhite(true);
        setLastMoveMarker(EAST_BLACK);
    }
	//Else if the new Ant space is white, the Ant turns
	//right to face "South". Update antDirection 
	//accordingly, set the antSpaceIsWhite marker
	//true (to toggle the black space to white), and
	//set the lastMoveMarker to EAST_WHITE (enumerated
	//value, see Ant.hpp).
    else if (array[currX][currY] == ' ')
    {
        setAntDirection(SOUTH);
        setAntSpaceIsWhite(false);
        setLastMoveMarker(EAST_WHITE);
    }
}
/****************************************************
				  void moveAntEast
	    Function to move Ant "West" or "Left".
 ****************************************************/
void Ant::moveAntWest(char** array, int& currX, int& 
	currY, const int numRows, int numCols)
{
	//If Ant is at the far-left of the board (i.e. column 
	//0), Ant "wraps" the board and ends at 
	//far-right of board (i.e. numCols - 1).
    if (currY == 0)
    {
        antYCoord = numCols - 1;
        currY = numCols - 1;
    }
	//Otherwise, decrements Ant's column number
	//(y position) by one, to move the Ant "West"
	//or left.
    else 
	{
		antYCoord -= 1;
		currY -= 1;
	}
    
	//If the new Ant space is black, the Ant turns
	//left to face "South". Update antDirection 
	//accordingly, set the antSpaceIsWhite marker
	//true (to toggle the black space to white), and
	//set the lastMoveMarker to WEST_BLACK (enumerated
	//value, see Ant.hpp).
    if (array[currX][currY] == '#')
    {
        setAntDirection(SOUTH);
        setAntSpaceIsWhite(true);
        setLastMoveMarker(WEST_BLACK);
    }
	//Else if the new Ant space is white, the Ant turns
	//right to face "North". Update antDirection 
	//accordingly, set the antSpaceIsWhite marker
	//true (to toggle the black space to white), and
	//set the lastMoveMarker to WEST_WHITE (enumerated
	//value, see Ant.hpp).
    else if (array[currX][currY] == ' ')
    {
        setAntDirection(NORTH);
        setAntSpaceIsWhite(false);
        setLastMoveMarker(WEST_WHITE);
    }
}
/****************************
    void lastMovePrintOut
  Prints last move details.
 ****************************/
void Ant::lastMovePrintOut() const
{
    if (lastMoveMarker == NORTH_WHITE)
    {
        cout << "Moved North. Encountered white square.\n";
        cout << "Turned right, now facing East.\n" << endl;
    }
    if (lastMoveMarker == NORTH_BLACK)
    {
        cout << "Moved North. Encountered black square.\n";
        cout << "Turned left, now facing West.\n" << endl;
    }
    if (lastMoveMarker == SOUTH_WHITE)
    {
        cout << "Moved South. Encountered white square.\n";
        cout << "Turned right, now facing West.\n" << endl;
    }
    if (lastMoveMarker == SOUTH_BLACK)
    {
        cout << "Moved South. Encountered black square.\n";
        cout << "Turned left, now facing East.\n" << endl;
    }
    if (lastMoveMarker == EAST_WHITE)
    {
        cout << "Moved East. Encountered white square.\n";
        cout << "Turned right, now facing South.\n" << endl;
    }
    if (lastMoveMarker == EAST_BLACK)
    {
        cout << "Moved East. Encountered black square.\n";
        cout << "Turned left, now facing North.\n" << endl;
    }
    if (lastMoveMarker == WEST_WHITE)
    {
        cout << "Moved West. Encountered white square.\n";
        cout << "Turned right, now facing North.\n" << endl;
    }
    if (lastMoveMarker == WEST_BLACK)
    {
        cout << "Moved West. Encountered black square.\n";
        cout << "Turned left, now facing South.\n" << endl;
    }
}