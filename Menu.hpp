/**********************************************************
** Program name: Menu.hpp
** Author: Ben Fridkis
** Date: 4/5/2017
** Description: Header file for Menu.cpp source file.
                Declares menu class and derivative.
***********************************************************/

#ifndef Menu_hpp
#define Menu_hpp

class Menu
{
protected:
    int numberOfSelections;
    int userSelection;
public:
    int menu(int numSelections);
    int getNumberOfSelections() const;
    void setNumberOfSelections(int numSelections);
    int getUserSelection() const;
    void setUserSelection(int userSelection);
};

class LangtonsAntMenu : public Menu
{
public:
    int menu(int numSelections);
};

#endif /* Menu_hpp */
