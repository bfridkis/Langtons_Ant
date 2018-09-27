/**********************************************************************
** Program name: mainProject1.cpp
** Author: Ben Fridkis
** Date: 4/5/2017
** Description: Main file that runs Langton's Ant simulation. Menu and
				InputValidation classes (along with derivative classes)
				establish starting values. These values are processed
				by the Ant class object to run the simulation. The 
				printBoard function (defined in a seperate file) prints
				the board after each step completes along with step
				details as provided by the Ant member function 
				lastMovePrintOut.
***********************************************************************/

#include "Ant.hpp"
#include "InputValidation.hpp"
#include "Menu.hpp"
#include "printBoard.hpp"
#include<iostream>
#include<memory>
#include<chrono>
#include<thread>
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::make_shared;

int main ()
{
	
	cout << "\nLangton's Ant Simulation\n" << endl;
    
	//Pointers and dynamic allocation are used when 
	//instantiating derivative classes, per pg. 785 of 
	//"C++ Early Objects (9th Ed.)". This smart pointer 
	//will automatically deallocate the memory used for
	//its managed object if it is reassigned at any point
	//(and as long as no other shared_ptr is assigned its
	//contents) or it goes out of scope. The managed object
	//is of LangtonsAntMenu type, which provides a menu
	//specific for running this simulation.
    shared_ptr<LangtonsAntMenu> thisLangtonsAntMenu =
    make_shared<LangtonsAntMenu>();
	
	//Establishes user's menu selection via
	//menu function of LangtonsAntMenu class object.
    int menuChoice = thisLangtonsAntMenu->menu(5);
    
	//See note on lines 34-40 on shared_ptr.
	//Establishes class object that will be used for
	//input validation throughout the remainder of the
	//program.
	shared_ptr<AntInputValidation> thisAntInputValidation = 
	make_shared<AntInputValidation>();
	
	//A menu selection of 5 denotes the user's selection to
	//end the program. While selection is not 5, run the simulation
	//according the user's choice of starting direction (see
	//InputValidation.cpp:LangtonsAntMenu()).
    while(menuChoice != 5)
    {
		//Instantiate an Ant object based on user's menu choice .
        Ant thisAnt(menuChoice);
		
		//Get number of rows, number of columns, number of steps,
		//starting row number, and starting column number. Input
		//validation is used for each of these prompts via the
		//AntInputValidation class object instatiated above.
        cout << "Enter number of rows for ant matrix. (Max 50)" << endl;
        int numRows = thisAntInputValidation->posIntInputValidation(50);

        cout << "Enter number of columns for ant matrix. (Max 30)" << endl;
        int numCols = thisAntInputValidation->posIntInputValidation(30);

        cout << "Enter number of ant steps. (Max 100)" << endl;
        thisAnt.setAntSteps(thisAntInputValidation->posIntInputValidation(100));
		
        cout << "Enter ant starting row number,\n"
             << "or enter 0 for a randomly assigned "
             << "starting row number." << endl;
		thisAntInputValidation->validateAndSetStartingRow(numRows);
        thisAnt.setAntXCoord(thisAntInputValidation->getStartingRowValidated());
        
		cout << "Enter ant starting column number,\n"
             << "or enter 0 for a randomly assigned "
             << "starting column number." << endl;
		thisAntInputValidation->validateAndSetStartingCol(numCols);
        thisAnt.setAntYCoord(thisAntInputValidation->getStartingColValidated());
        
        //Promts user to add a pause between step printout if
		//desired. This allows the user to view the simulation
		//as it runs.
        cout << "\nAdd 0.5 second pause between step printouts?\n"
             << "(Enter 1 for yes, 0 for no.)" << endl;
        bool addPause = InputValidation::boolInputValidation();
        
		//Create the matrix based on the number
		//of rows and columns input by the user above.
        char** ary = new char*[numRows];

        for (int i = 0; i < numRows; i++)
        {
            ary[i] = new char[numCols];
        }
        
        //Initialize each board element with
		//a white-space character (to denote
		//a white board space).
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                ary[i][j] = ' ';
            }
		}
		
		//These two assignments are to simplify
		//code that follows and which uses the Ant 
		//objects antXCoord and antYCoord member
		//variables.
		int currentX = thisAnt.getAntXCoord();
		int currentY = thisAnt.getAntYCoord();
		
		//Assigns the '@' to the Ant's starting
		//location.
		ary[currentX][currentY] = '@';
		
        cout << "\nPress enter to begin." << endl;
        cin.get();
        
		//Prints the initial board after Ant placement
		//with starting direction statement.
        if (thisLangtonsAntMenu->getUserSelection()
            == 1)
        {cout << "\nStep 0:\nStarting facing North.\n"
			  << endl;}
        else if (thisLangtonsAntMenu->getUserSelection()
            == 2)
        {cout << "\nStep 0:\nStarting facing South.\n"
			  << endl;}
        else if (thisLangtonsAntMenu->getUserSelection()
            == 3)
        {cout << "\nStep 0:\nStarting facing East.\n"
			  << endl;}
        else if (thisLangtonsAntMenu->getUserSelection()
            == 4)
        {cout << "\nStep 0:\nStarting facing West.\n"
			  << endl;}
		printBoard(ary, numRows, numCols);
		
		//For each step, move the ant and print the board.
		//If the pause option was selected above (lines 94-96),
		//add the pause between each printout.
		for (int i = 1; i <= thisAnt.getAntSteps(); i++)
		{
            thisAnt.moveAnt(ary, currentX, currentY, numRows, numCols);
            printBoard(ary, i, numRows, numCols, thisAnt);
            
            if (addPause)
            {std::this_thread::sleep_for(std::chrono::milliseconds(500));}
		}
        
		//Print a newline, deallocate the memory used to
		//to store the 2D array, and display the menu options
		//again.
		cout << endl << endl;
        delete [] ary;
        ary = nullptr;
        menuChoice = thisLangtonsAntMenu->menu(5);
	}
    
    return 0;
}