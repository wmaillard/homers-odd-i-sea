#include "Player.h"

Player::Player()
{
    SetComplete(false);
    SetGameTime(static_cast<long int>(time(NULL)));
}

Player::~Player()
{
    //dtor
}

/*********************************************************************
** Function:  bool Player::checkFull()
** Description: checks if the player's bag is full
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: true if full, false if not
*********************************************************************/
bool Player::checkFull()
{
    if (GetBag()->size() == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*********************************************************************
** Function:  Item* Player::RemoveAnItem()
** Description: removes a user selected item from player's bag
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Item is removed and returned
*********************************************************************/
Item* Player::RemoveAnItem()
{
    bool error;
    Item *SavedItem;
    do
    {
    std::cout << "What item would you like to remove?" << std::endl;
    std::cout << "1. " << GetBag()->at(0)->GetName() << std::endl;
    std::cout << "2. " << GetBag()->at(1)->GetName() << std::endl;
    char choice = -1;
    error = false;
    std::cin >> choice;

    switch(choice){
    case '1':
    SavedItem = GetBag()->at(0);
    GetBag()->erase(GetBag()->begin());
    break;
    case '2':
    SavedItem = GetBag()->at(1);
    GetBag()->erase(GetBag()->begin()+1);
    break;
    default:
        std::cout << "Please enter a valid choice!" << std::endl;
        error = true;
    }
}while(error);
return SavedItem;
}

/*********************************************************************
** Function:  double Player::GetElapsedTime()
** Description: returns elapsed time in years
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

double Player::GetElapsedTime()
{
    return (static_cast<long int>(time(NULL)) - GetGameTime()) * 3 / 60 + 20;
}

