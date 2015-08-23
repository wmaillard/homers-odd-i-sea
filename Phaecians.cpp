#include "Phaecians.h"

Phaecians::Phaecians()
{
    SetActionName(" at the battle ground of ");
    SetLookAtName(" BATTLE ");
    SetType(CREATURETYPE);
    SetStatus(false);
    SetSuccess(false);
    CorrectItem = "Hot Spiced Rum";
    SetName("The Phaecians");
    SetIslandName("Phaeciana");
}

Phaecians::~Phaecians()
{
    //dtor
}

/*********************************************************************
** Function:  int Phaecians::Challenge(bool itemUsed)
** Description: a challenge in which strings must be copied correctly
** Parameters: bool itemUsed
** Pre-Conditions: none
** Post-Conditions: returns 10 if failed, 0 if passed
*********************************************************************/
int Phaecians::Challenge(bool itemUsed)
{
    time_t start;
    time_t finish;
    int timeTaken;
    std::string blank;
    int mult;
    std::string answer;
    bool error = false;

    if (itemUsed)
        mult = 2;
    else
        mult = 1;


    std::cout << "\n*******************************************************"
            << "\nThe Phaecians are a rowdy drunken people and you must\n"
            << "sing songs with them before they will take you on their\n"
            << "magic ship which will return you home to Ithaca!\n" << std::endl;

    if (itemUsed)
    {
        std::cout << "The Phaecians are extra drunk due to the rum that\n"
                    << "you gave them, so you will have 60 seconds to sing\n"
                    << "their song." << std::endl;
    }
    else
    {
        std::cout << "The Phaecians are sobering up because you didn't use the correct item.\n"
                  << "You will only have 30 seconds to sing their song!" << std::endl;
    }
    std::cout << "To sing their song you must type each line EXACTLY as you see it." << std::endl;
    std::cout << "To start singing, press any key and hit [enter]" << std::endl;
    std::cin >> blank;
    std::cout << "\n**************************************************************\n" << std::endl;
    start = time(0);
    do{
    if(static_cast<int>(time(0)-start) > 30 * mult)
        break;
    error = false;
    std::cout << "We're the Phaecians and we're here to say" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, answer);
    if (answer != "We're the Phaecians and we're here to say")
    {
        std::cout << "That is incorrect!" << std::endl;
        error = true;
    }}while(error);

    do{
    if(static_cast<int>(time(0)-start) > 30 * mult)
        break;
    error = false;
    std::cout << "We work all night and we drink all day" << std::endl;
    std::getline(std::cin, answer);

    if (answer != "We work all night and we drink all day")
    {
        std::cout << "That is incorrect!" << std::endl;
        error = true;
    }}while(error);

       do{
    if(static_cast<int>(time(0)-start) > 30 * mult)
        break;
    error = false;
    std::cout << "We try on women's clothing" << std::endl;
    std::getline(std::cin, answer);

    if (answer != "We try on women's clothing")
    {
        std::cout << "That is incorrect!" << std::endl;
        error = true;
    }}while(error);

    do{
    if(static_cast<int>(time(0)-start) > 30 * mult)
        break;
    error = false;
    std::cout << "And hang around in bars!" << std::endl;
    std::getline(std::cin, answer);

    if (answer != "And hang around in bars!")
    {
        std::cout << "That is incorrect!" << std::endl;
        error = true;
    }}while(error);
    finish = time(0);

    finish -= start;
    timeTaken = static_cast<int>(finish);
    std::cout << "\n***********************************************" << std::endl;
    if (timeTaken > 30 * mult)
    {
        std::cout << "You went over time!\nYou have failed this challenge.\nTen of your men have died in a drunken brawl"
        << " \nand you will spend ten years on this island mourning!\n"
        << "After that, The Phaecians will take you home to Ithaca!" << std::endl;
        std::cout << "\n********************************************************\n" << std::endl;
        return 10;
    }
    else
        {
            std::cout << "You took " << timeTaken << " seconds.  You were successful. \nThe Phaecians will now take you home to Ithaca!" << std::endl;
            std::cout << "\n********************************************************\n" << std::endl;
            return 0;
        }

}
