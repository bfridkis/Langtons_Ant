/*************************************************************
** Program name: Menu.cpp
** Author: Ben Fridkis
** Date: 4/5/2017
** Description: Member function definitions for menu class.
                A generic menu is provided that accepts a
                number of selections as parameter and then
                returns a user's choice. Get and set methods
                are provided for both the number of selections
                and the user's choice. A derivative class is
                provided with Project 1 ("Langton's Ant") 
				specific prompts included.
**************************************************************/

#include "Menu.hpp"
#include "InputValidation.hpp"
#include<iostream>
#include<limits>
#include<memory>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::shared_ptr;
using std::make_shared;

/**************************************************
                       menu
  Prompts user to enter menu selection and returns
  user selection.  
 **************************************************/
int Menu::menu(int numberOfSelections)
{
    int userChoice;
    this->numberOfSelections = numberOfSelections;
	
    //This smart pointer assignment statement will dynamically
	//create a local MenuInputValidation object whose member
	//function will return validated input (line 49). The shared 
	//pointer's reference count will decrease to 0 when the object 
	//goes out of scope, and the managed object's memory will be 
	//automatically deallocated.
	shared_ptr<MenuInputValidation> thisMenuInputValidation =
		make_shared<MenuInputValidation>();
    
	cout << "Enter Menu Selection:" << endl;
    
    userChoice = thisMenuInputValidation->menuInputValidation
        (numberOfSelections);
	
	userSelection = userChoice;
    
    return userSelection;
}
/**********************************************
              getNumberOfSelections
     Gets numberOfSelections member variable.
 **********************************************/
int Menu::getNumberOfSelections() const
{
    return numberOfSelections;
}

/*******************************************
              setNumberOfSelections
  Sets numberOfSelections member variable.
 *******************************************/
void Menu::setNumberOfSelections(int numberOfSelections)
{
    this->numberOfSelections = numberOfSelections;
}
/******************************************
               getuserSelection
      Gets userSelection member variable.
 ******************************************/
int Menu::getUserSelection() const
{
    return userSelection;
}
/**************************************
              setUserSelection
  Sets userSelection member variable.
 **************************************/
void Menu::setUserSelection(int userSelection)
{
    this->userSelection = userSelection;
}

/*#################################################
###################################################
		Derivative Class Member Functions:
			   LangtonsAntMenu
###################################################			   
###################################################*/

/****************************************************
              LangtonsAntmenu::menu
  Prompts user to enter menu selection and returns
  user selection. Same as menu function in base
  class but adds menu item specific cout statements
  for Project 1/Langtons Ant Simulation. User chooses
  the ant's starting direction from the program menu,
  or quits via selection 5. See notes above for 
  base class menu function for remaining details.
 ****************************************************/
int LangtonsAntMenu::menu(int numberOfSelections)
{
	int userChoice;
    this->numberOfSelections = numberOfSelections;
    shared_ptr<MenuInputValidation> thisMenuInputValidation =
		make_shared<MenuInputValidation>();
	
	cout << "Enter Menu Selection:" << endl;
    
    //Project 1 (Langton's Ant) specific prompts.
    cout << "1. Start Ant Facing North (Up)." << endl;
    cout << "2. Start Ant Facing South (Down)." << endl;
    cout << "3. Start Ant Facing East (Right)." << endl;
    cout << "4. Start Ant Facing West (Left)." << endl;
    cout << "5. End Program.\n" << endl;
	
    userChoice = thisMenuInputValidation->menuInputValidation
       (numberOfSelections);
    
	userSelection = userChoice;
    
    return userSelection;
}