/**********************************************************
** Program name: InputValidation.cpp
** Author: Ben Fridkis
** Date: 4/8/2017
** Description: InputValidation class and class derivatives
				member function definitions.
***********************************************************/

#include "InputValidation.hpp"
#include<iostream>
#include<limits>
#include<memory>
#include<cstdlib>
#include<ctime>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

/**************************************************
              posIntInputValidation
  Function to check input stream for a positive
  interger value. Reprompts the user to enter
  a value if an interger greater than 0 is not
  detected.
 **************************************************/
int InputValidation::posIntInputValidation()
{
    int input;
    cin >> input;
	//If cin fails (i.e. the variable in the input stream
	//is not of type int) or input is less than one,
	//notify and reprompt user, reset cin error flag,
	//ignore any remaining input in the input stream up
	//to the next newline character, and try again using 
	//the user's next entry.
    while (!cin || input < 1)
    {
        cout << "Invalid input. Please enter a positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
        
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
               
    return input;
}
/**************************************************
      posIntInputValidation - w/max parameter
  Function to check input stream for a positive
  interger value up to a value of max. Reprompts 
  the user to enter a value if an interger less 
  than 1 or in excess of maximum is not detected.
 **************************************************/
int InputValidation::posIntInputValidation(int max)
{
    int input;
    cin >> input;
	//If cin fails (i.e. the variable in the input stream
	//is not of type int) or input is less than one or
	//greater than max, notify and reprompt user, reset 
	//cin error flag ignore any remaining input in the input stream up
	//to the next newline character, and try again using 
	//the user's next entry.
    while (!cin || input < 1 || input > max)
    {
        cout << "Invalid input. Please enter a positive integer "
             << "no greater than " << max << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
        
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
               
    return input;
}
/**************************************************
			  negIntInputValidation
  Function to check input stream for a negative
  interger value. Reprompts the user to enter
  a value if an interger less than 0 is not
  detected.
 **************************************************/
int InputValidation::negIntInputValidation()
{
    int input;
    cin >> input;
	//If cin fails (i.e. the variable in the input stream
	//is not of type int) or input is greater than 
	//negative one, notify and reprompt user, reset cin 
	//error flag, ignore any remaining input in the input 
	//stream up to the next newline character, and try again 
	//using the user's next entry.
    while (!cin || input > -1)
    {
        cout << "Invalid input. Please enter a negative interger."
             << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
            
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                       
    return input;
}
/****************************************************
      negIntInputValidation - w/min parameter
  Function to check input stream for a negative
  interger value no less than the value of min. 
  Reprompts the user to enter a value if an interger 
  less than min or in excess of -1 is detected.
 ****************************************************/              
int InputValidation::negIntInputValidation(int min)
{
    int input;
    cin >> input;
	//If cin fails (i.e. the variable in the input stream
	//is not of type int) or input is greater than 
	//negative one or less than min, notify and reprompt 
	//user, reset cin error flag, ignore any remaining input 
	//in the input stream up to the next newline character, 
	//and try again using the user's next entry.
    while (!cin || input > -1 || input < min)
    {
        cout << "Invalid input. Please enter a negative integer "
             << "no less than " << min << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
            
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                       
    return input;
}
/****************************************************
			  nonNegIntInputValidation
  Same as posIntInputValidation but allows input of
  0.
 ****************************************************/  
int InputValidation::nonNegIntInputValidation()
{
    int input;
    cin >> input;
    while (!cin || input < 0)
    {
        cout << "Invalid input. Please enter a non-negative "
        << "integer. (Note 0 is a non-negative interger)." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
        
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   
    return input;
}
/****************************************************
     nonNegIntInputValidation - w/max parameter
  Same as posIntInputValidation -w/max parameter but 
  allows input of 0.
 ****************************************************/ 
int InputValidation::nonNegIntInputValidation(int max)
{
    int input;
    cin >> input;
    while (!cin || input < 0 || input > max)
    {
        cout << "Invalid input. Please enter a non-negative "
             << "integer no greater than " << max << endl
             << "(Note 0 is a non-negative interger)." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
        
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   
    return input;
}
/****************************************************
			   nonPosIntInputValidation
  Same as negIntInputValidation but allows input of
  0.
 ****************************************************/
int InputValidation::nonPosIntInputValidation()
{
    int input;
    cin >> input;
    while (!cin || input > 0)
    {
        cout << "Invalid input. Please enter a non-negative "
        << "integer. (Note 0 is a non-positive interger)." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
        
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   
    return input;
}
/****************************************************
     nonPosIntInputValidation - w/min parameter
  Same as negIntInputValidation-w/min parameter but 
  allows input of 0.
 ****************************************************/ 
int InputValidation::nonPosIntInputValidation(int min)
{
    int input;
    cin >> input;
    while (!cin || input > 0 || input < min)
    {
        cout << "Invalid input. Please enter a non-negative "
             << "integer no less than " << min << endl
             << "(Note 0 is a non-positive interger)." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
        
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   
    return input;
}
/****************************************************
			    boolInputValidation
  Function to check input stream for a boolean
  (0 or 1) entry. Used in conjunction with a prompt
  for "Yes" or "No", where 1 corresponds to yes and
  0 corresponds to no. Reprompts the user to enter a 
  1 or 0 if 1 or 0 is not entered.
 ****************************************************/ 
bool InputValidation::boolInputValidation()
{
    bool isYes;
    cin >> isYes;
	//If cin fails (i.e. the variable in the input stream
	//is not of type bool), notify and reprompt 
	//user, reset cin error flag, ignore any remaining input 
	//in the input stream up to the next newline character, 
	//and try again using the user's next entry.
    while (!cin)
    {
        cout << "Invalid input. Enter 1 for yes, 0 for no."
             << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> isYes;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return isYes;
}

/*##################################################
####################################################
		Derivative Class Member Functions:
			  MenuInputValidation
####################################################
####################################################*/

/****************************************************
	 MenuInputValidation::menuInputValidation
  Function to check input stream for a valid menu
  selection entry. Assumes menu entry options begin
  at 1. Function is passed an int parameter to 
  establish the greatest entry value. Assumes all
  entries between 1 and numberOfSelections parameter
  are integers and valid.
 ****************************************************/ 
int MenuInputValidation::menuInputValidation
    (int numberOfSelections)
{
    int userChoice;
    cin >> userChoice;
    
    //If user input generates an error because
    //a non-int type is received by the input
    //stream, or a value is entered that is out 
	//of the established range of selections, loop 
	//as follows:
    while (!cin || userChoice < 1 || userChoice > numberOfSelections)
	   {
           cout << "\nPlease enter an integer between 1"
           << " and " << numberOfSelections
           << " to make your selection.\n" << endl;
           //Clear the cin error flag.
           cin.clear();
           //Ignore the rest of the input stream, in
           //case space seperated values were provided.
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
           //Try again.
           cin >> userChoice;
       }
    
    //Ignore any remaining values in the input
    //stream, and print a new line.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    
    userSelection = userChoice;
    return userSelection;
}
/****************************************
  MenuInputValidation::getUserSelection
  Returns userSelection member variable.
 ****************************************/
int MenuInputValidation::getUserSelection() const
{
	return userSelection;
}
/***************************************
  MenuInputValidation::setUserSelection
  Sets userSelection member variable.
 ***************************************/
void MenuInputValidation::setUserSelection
	(int userSelection)
{
	this->userSelection = userSelection;
}

/*#################################################
###################################################
		Derivative Class Member Functions:
			   AntInputValidation
###################################################			   
###################################################*/

/************************************************
   AntInputValidation::getStartingRowValidated
    Gets member variable startingRowValidated.
 ************************************************/ 
int AntInputValidation::getStartingRowValidated() const
{
	return startingRowValidated;
}
/************************************************
   AntInputValidation::getStartingColValidated
    Gets member variable startingColValidated.
 ************************************************/ 
int AntInputValidation::getStartingColValidated() const
{
	return startingColValidated;
}
/********************************************************
	  AntInputValidation::validateAndSetStartingRow
  Function to check input stream for a valid starting
  row number and set startingRowValidated accordingly.
  Maximum starting row is determined from max parameter.
  Sets a random row number between 1 and max if user
  inputs 0.
 *********************************************************/
void AntInputValidation::validateAndSetStartingRow(int max)
{
	int startingRowValidatedOffset1;
    cin >> startingRowValidatedOffset1;
    
	//If user inputs zero, generate a random row number
	//between 1 and 0, and display to user randomly
	//assigned row number.
    if (startingRowValidatedOffset1 == 0)
    {
        unsigned seed = time(0);
        srand(seed);
		//Because the array values which hold the row
		//and column data start at zero, an offset of 1 
		//is used to set the startingRowValidated. The
		//value displayed to the user is the value withoutow
		//offset (e.g. row 0 is diplayed as row 1, etc.)
        startingRowValidated = (rand() % max + 1) - 1;
        cout << "\nYour randomly assigned starting row is "
             << startingRowValidated + 1 << ".\n" << endl;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //Otherwise...
    else
    {
		//If user input generates an error because
		//a non-int type is received by the input
		//stream, or a value is entered that is less
		//than 0 or greater than max (number of rows),
		//loop as follows:
        while (!cin || startingRowValidatedOffset1 < 0 ||
               startingRowValidatedOffset1 > max)
        {
            cout << "Invalid input. Please enter a row number "
                 << "between 1 and " << max << " to\n"
                 << "assign a starting row, or enter 0 "
                 << "for a randomly assigned starting row."
                 <<  endl;
            //Clear the cin error flag.
			cin.clear();
            //Ignore the rest of the input stream, in
            //case space seperated values were provided.
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //Try again.
			cin >> startingRowValidatedOffset1;
        }
        //If user inputs zero, generate a random row number
		//between 1 and 0, and display to user randomly
		//assigned row number.
        if (startingRowValidatedOffset1 == 0)
        {
            unsigned seed = time(0);
            srand(seed);
			//Because the array values which hold the row
			//and column data start at zero, an offset of 1 
			//is used to set the startingRowValidated. The
			//value displayed to the user is the value withoutow
			//offset (e.g. row 0 is diplayed as row 1, etc.)
            startingRowValidated = (rand() % max + 1) - 1;
            cout << "\nYour randomly assigned starting row is "
                 << startingRowValidated + 1 << ".\n" << endl;
        }
        else
        {
			//Starting row is offset 1 because array values
			//begin at 0.
            startingRowValidated = startingRowValidatedOffset1 - 1;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }       
}
/********************************************************
	  AntInputValidation::validateAndSetStartingCol
  Function to check input stream for a valid starting
  column number and set startingColValidated accordingly.
  Maximum starting row is determined from max parameter.
  Sets a random column number between 1 and max if user
  inputs 0.
 *********************************************************/
void AntInputValidation::validateAndSetStartingCol(int max)
{
    int startingColValidatedOffset1;
	cin >> startingColValidatedOffset1;
	
	//If user inputs zero, generate a random column number
	//between 1 and 0, and display to user randomly
	//assigned column number.
    if (startingColValidatedOffset1 == 0)
    {
        unsigned seed = time(0);
        srand(seed);
		//Because the array values which hold the row
		//and column data start at zero, an offset of 1 
		//is used to set the startingColValidated. The
		//value displayed to the user is the value without
		//the offset (e.g. column 0 is diplayed as column 
		//1, etc.)
        startingColValidated = (rand() % max + 1) - 1;
        cout << "\nYour randomly assigned starting column is "
             << startingColValidated + 1 << "." << endl;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //Otherwise...
    else
    {
		//If user input generates an error because
		//a non-int type is received by the input
		//stream, or a value is entered that is less
		//than 0 or greater than max (number of columns),
		//loop as follows:
        while (!cin || startingColValidatedOffset1 < 0 ||
               startingColValidatedOffset1 > max)
        {
                cout << "Invalid input. Please enter a column number "
                     << "between 1 and " << max << " to\n"
                     << "assign a starting column, or enter 0 "
                     << "for a randomly assigned starting column."
                     <<  endl;
            //Clear the cin error flag.
			cin.clear();
            //Ignore the rest of the input stream, in
            //case space seperated values were provided.
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //Try again.
			cin >> startingColValidatedOffset1;
        }
    
		//If user inputs zero, generate a random column number
		//between 1 and 0, and display to user randomly
		//assigned column number.
        if (startingColValidatedOffset1 == 0)
        {
            unsigned seed = time(0);
            srand(seed);
			//Because the array values which hold the row
			//and column data start at zero, an offset of 1 
			//is used to set the startingColValidated. The
			//value displayed to the user is the value without
			//the offset (e.g. column 0 is diplayed as column 
			//1, etc.)
            startingColValidated = (rand() % max + 1) - 1;
            cout << "\nYour randomly assigned starting column is "
                     << startingColValidated + 1 << "." << endl;
        }
        else
        {
			//Starting column is offset 1 because array values
			//begin at 0.
            startingColValidated = startingColValidatedOffset1 - 1;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}