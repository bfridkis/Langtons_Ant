/*************************************************************
 ** CS162 - Project 1
 ** Author: Benjamin Fridkis
 ** Date: 3/1/2017
 ** Description: Header file for Ant.cpp source file.
                 Declares Ant class.
**************************************************************/               

#ifndef ANT_HPP
#define ANT_HPP

enum Direction {NORTH, SOUTH, EAST, WEST};
enum LastMove {NORTH_WHITE, NORTH_BLACK, SOUTH_WHITE, SOUTH_BLACK,
               EAST_WHITE, EAST_BLACK, WEST_WHITE, WEST_BLACK};

class Ant
{
private:
    int antXCoord;
	int antYCoord;
    int antSteps;
	Direction antDirection;
	bool antSpaceIsWhite;
    LastMove lastMoveMarker;
	bool getAntSpaceIsWhite() const;
	Direction getAntDirection() const;
	LastMove getLastMoveMarker() const;
	void setAntDirection(Direction antDirection);
	void setAntSpaceIsWhite(bool isWhite);
	void setLastMoveMarker(LastMove lastMoveMarker);
	void moveAntNorth(char** array, int& currX, int& currY,
                      const int numRows, const int numCols);
	void moveAntSouth(char** array, int& currX, int& currY,
                      const int numRows, const int numCols);
	void moveAntEast(char** array, int& currX, int& currY,
                     const int numRows, int numCols);
	void moveAntWest(char** array, int& currX, int& currY,
                     const int numRows, int numCols);
	
public:
	Ant(int antStartDir);
    int getAntXCoord() const;
    int getAntYCoord() const;
    int getAntSteps() const;
	void setAntSteps(int numSteps);
	void setAntXCoord(int xCoord);
	void setAntYCoord(int yCoord);
	void moveAnt(char** array, int& currX, int& currY,
                 const int numRows, const int numCols);
	void lastMovePrintOut() const;
};

#endif /* ANT_HPP */
