#include "Laest.h"

Laest::Laest()
{
    SetActionName(" at the battle ground of ");
    SetLookAtName(" BATTLE ");
    SetType(CREATURETYPE);
    SetStatus(false);
    SetSuccess(false);
    CorrectItem = "Paprika";
    SetName("The Laestrygonians");
    SetIslandName("Laestrygonia");
}

Laest::~Laest()
{
    //dtor
}

/*********************************************************************
** Function:  int Laest::Challenge(bool itemUsed)
** Description: a challenge in which math problems must be solved
** Parameters: bool itemUsed
** Pre-Conditions: none
** Post-Conditions: returns 10 if failed, 0 if passed
*********************************************************************/

int Laest::Challenge(bool itemUsed)
{
    time_t start;
    time_t finish;
    int timeTaken;
    int value;
    std::string blank;
    int mult;
    std::string answer;
    bool error = false;
    if (itemUsed)
    {
        mult = 2;
    }
    else
        mult = 1;

    std::cout << "The Laestrygonians are a race of cannibals. \nThey have captured your men and will eat them unless you" << std::endl
            << "answer the following math problems correctly" << std::endl;

    if (itemUsed)
        {std::cout << "The Laestrygonians are marinating your men with the paprika\n"
                    << "you gave them, so you will have 20 seconds to answer\n"
                    << "all of the questions" << std::endl;
        }
    else
        std::cout << "The Laestrygonians are coming to get you! \nYou have 10 seconds to answer all of the questions." << std::endl;
    std::cout << "To start the quiz, press any key and hit [enter]" << std::endl;
    std::cin >> blank;
    start = time(0);
    do{
    if(static_cast<int>(time(0)-start) > 10 * mult)
        break;
    error = false;
    std::cout << "What is 5 + 7? :" << std::endl;
    std::cin >> answer;
    value = atoi(answer.c_str());

    if (value != 12)
    {
        std::cout << "That is incorrect!" << std::endl;
        error = true;
    }}while(error);

    do{
    if(static_cast<int>(time(0)-start) > 10 * mult)
        break;
    error = false;
    std::cout << "What is 10 * 11? :" << std::endl;
    std::cin >> answer;
    value = atoi(answer.c_str());

    if (value != 110)
    {
        std::cout << "That is incorrect!" << std::endl;
        error = true;
    }}while(error);

    do{
    if(static_cast<int>(time(0)-start) > 10 * mult)
        break;
    error = false;
    std::cout << "What is 12 * 15? :" << std::endl;
    std::cin >> answer;
    value = atoi(answer.c_str());

    if (value != 180)
    {
        std::cout << "That is incorrect!" << std::endl;
        error = true;
    }}while(error);

    do{
    if(static_cast<int>(time(0)-start) > 10 * mult)
        break;
    error = false;
    std::cout << "What is 5 * 5? :" << std::endl;
    std::cin >> answer;
    value = atoi(answer.c_str());

    if (value != 25)
    {
        std::cout << "That is incorrect!" << std::endl;
        error = true;
    }}while(error);
    finish = time(0);

    finish -= start;
    timeTaken = static_cast<int>(finish);
    if (timeTaken > 10 * mult)
    {
        std::cout << "\n\n*****************************************************\n"
        << "You took went over time!\nYou have failed this challenge.\nTen of your men have been eaten"
        << " \nand you will spend ten years on this island mourning!"
        << "\nAfter that, you will set sail for Phaeciana." << std::endl;
        return 10;
    }
    else
        {
            std::cout << "\n\n*****************************************************\n"
            << "You took " << timeTaken << " seconds.  You were successful. \nYour men have been freed and you have escaped!"
            << "\nYou will now set sail for Phaeciana!" << std::endl;
            return 0;
        }
}
