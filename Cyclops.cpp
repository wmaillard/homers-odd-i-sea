#include "Cyclops.h"

Cyclops::Cyclops()
{
    SetActionName(" at the battle ground of ");
    SetLookAtName(" BATTLE ");
    SetType(CREATURETYPE);
    SetStatus(false);
    SetSuccess(false);
    CorrectItem = "Pepper Spray";
}

Cyclops::~Cyclops()
{
    //dtor
}

/*********************************************************************
** Function:  int Cyclops::Challenge(bool itemUsed)
** Description: a challenge in which a random number must be guessed
** Parameters: bool itemUsed
** Pre-Conditions: none
** Post-Conditions: returns 10 if failed, 0 if passed
*********************************************************************/
int Cyclops::Challenge(bool itemUsed)
{
    int upperRange;
    if (itemUsed)
    {
        upperRange = 5;
    }
    else
        upperRange = 10;

 std::cout << "\nCyclops: Guess the number I am thinking of within and including \nthe range [1, " << upperRange << "] and I will let you pass!" <<  std::endl;
    srand(time(0));
    int thinkNum = rand() % upperRange + 1;
    int guessNum;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Guess " << i + 1 << ":" << std::endl;
        std::cin >> guessNum;
        if (thinkNum == guessNum)
        {
            std::cout << "\n************************************************************************" << std::endl;
            std::cout << "That is correct, you may now pass!" << std::endl;
            std::cout << "You will now swiftly set sail for the Island of Laestrygonians.\n " << std::endl;
            SetSuccess(true);
            SetStatus(true);
            return 0;
        }
        else
        {
            std::cout << "That is incorrect" << std::endl;
        }
    }
    std::cout << "\n************************************************************************" << std::endl;
    std::cout << "You failed! \n\nThe Cyclops has killed 10 of your men and broken your leg.  \nYou will waste an additional 10 years on this island.  " << std::endl;
    std::cout << "After that you will set sail for the Island of Laestrygonians.\n" << std::endl;

    SetStatus(true);
    SetSuccess(false);
    return 10;
}
