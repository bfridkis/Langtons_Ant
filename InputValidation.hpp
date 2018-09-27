/**********************************************************
** Program name: InputValidation.hpp
** Author: Ben Fridkis
** Date: 4/8/2017
** Description: Header file for InputValidation.cpp source 
				file. Declares InputValidation class and
				derivatives.
***********************************************************/

#ifndef InputValidation_hpp
#define InputValidation_hpp

class InputValidation
{
public:
    int posIntInputValidation();
    int posIntInputValidation(int max);
    
    int negIntInputValidation();
    int negIntInputValidation(int min);
    
    int nonNegIntInputValidation();
    int nonNegIntInputValidation(int max);
    
    int nonPosIntInputValidation();
    int nonPosIntInputValidation(int min);
    
    static bool boolInputValidation();
};

class MenuInputValidation: public InputValidation
{
private:
    int userSelection;
public:
    int menuInputValidation(int numberOfSelections);
	int getUserSelection() const;
	void setUserSelection(int userSelection);
};

class AntInputValidation: public InputValidation
{
	private:
		int startingRowValidated;
		int startingColValidated;
	public:
		int getStartingRowValidated() const;
		int getStartingColValidated() const;
		void validateAndSetStartingRow(int max);
		void validateAndSetStartingCol(int max);
	
};

#endif /* InputValidation_hpp */
