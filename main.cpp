/*********************************************************************
** Program Filename: main.cpp (final.exe)
** Author: William Maillard
** Date: 6/8/15
**
** Description: A game that is based on Homer's Odyssey.  In it
** the user travels around and island collecting items.  The user
** then battles the creature on that island and sets sail for another
** island.  Eventually, the user reaches Ithaca and wins.  If the user
** runs out of time, they die.
**
** Input:  Prompt responses from user
**
** Output: The game is printed to the screen.
*********************************************************************/



#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#include "Room.h"
#include "Island.h"
#include "Creature.h"
#include "Player.h"
#include "Landscape.h"
#include "Item.h"
#include "Cyclops.h"
#include "Laest.h"
#include "Phaecians.h"
#include "Ithaca.h"

using namespace std;
bool directionMenu(Player *Player1);
int CyclopsFunction();
void AddLinks (Room* Middle, Room* N, Room* E, Room* S, Room* W);

int main()
{
    bool repeat = false;

    do
    {

    char choice;
    bool error = false;

    Island *CyclopsI = new Island();
    CyclopsI->SetName("The Center");
    CyclopsI->SetIslandName("Cyclops");

    Laest *LaestPtr = new Laest();
    Island *LaestI = new Island();
    LaestI->SetName ("The Center");
    LaestI->SetIslandName("Laestrygonia");

    Phaecians *PhaecPtr = new Phaecians;
    Island *PhaecI = new Island();
    PhaecI->SetName("The Center");
    PhaecI->SetIslandName("Phaeciana");


    Cyclops *CyclopsPtr = new Cyclops();
    CyclopsPtr->SetName("The Cyclops");
    CyclopsPtr->SetIslandName("Cyclops");


    Item *PepperSprayPtr = new Item("Pepper Spray");
    Item *PaprikaPtr = new Item("Paprika");
    Item *EtchASketch = new Item("Etch-A-Sketch");
    Item *Hedgehog = new Item("Hedgehog");
    Item *OneShoe   = new Item("One Shoe");
    Item *BananaPeal = new Item("Banana Peal");
    Item *DVD        = new Item("Scratched DVD of 'The Mummy Returns'");
    Item *RustyScrewdriver = new Item("Rusty Screwdriver");
    Item *HotRum = new Item ("Hot Spiced Rum");


    Landscape *RocksPtr = new Landscape;
    RocksPtr->SetName("The Rocks");
    RocksPtr->SetItem(PepperSprayPtr);
    RocksPtr->SetIslandName("Cyclops");


    Landscape *ForestPtr = new Landscape;
    ForestPtr->SetName("The Forest");
    ForestPtr->SetItem(PaprikaPtr);
    ForestPtr->SetIslandName("Cyclops");

    Landscape *MeadowPtr = new Landscape;
    MeadowPtr->SetName("The Meadow");
    MeadowPtr->SetItem(EtchASketch);
    MeadowPtr->SetIslandName("Cyclops");

    Landscape *MountainPtr = new Landscape;
    MountainPtr->SetName("The Mountain");
    MountainPtr->SetItem(Hedgehog);
    MountainPtr->SetIslandName("Cyclops");

    Landscape *ThicketPtr = new Landscape;
    ThicketPtr->SetName("The Thicket");
    ThicketPtr->SetItem(OneShoe);
    ThicketPtr->SetIslandName("Laestrygonia");

    Landscape *GlenPtr = new Landscape;
    GlenPtr->SetName("The Glen");
    GlenPtr->SetItem(BananaPeal);
    GlenPtr->SetIslandName("Laestrygonia");

    Landscape *DellPtr = new Landscape;
    DellPtr->SetName("The Dell");
    DellPtr->SetItem(DVD);
    DellPtr->SetIslandName("Phaeciana");

    Landscape *LakePtr = new Landscape;
    LakePtr->SetName("The Lake");
    LakePtr->SetItem(RustyScrewdriver);
    LakePtr->SetIslandName("Phaeciana");

    Landscape *GorgePtr = new Landscape;
    GorgePtr->SetName("The Gorge");
    GorgePtr->SetItem(HotRum);
    GorgePtr->SetIslandName("Phaeciana");

    Ithaca *IthacaI = new Ithaca;



    LaestPtr->SetWinLocation(PhaecI);
    LaestPtr->SetLoseLocation(PhaecI);
    PhaecPtr->SetWinLocation(IthacaI);
    PhaecPtr->SetLoseLocation(IthacaI);
    CyclopsPtr->SetWinLocation(LaestI);
    CyclopsPtr->SetLoseLocation(LaestI);


    AddLinks(CyclopsI, CyclopsPtr, RocksPtr, MeadowPtr, MountainPtr);
    AddLinks(RocksPtr, NULL, NULL, NULL, CyclopsI);
    AddLinks(CyclopsPtr, NULL, NULL, CyclopsI, NULL);
    AddLinks(MeadowPtr, CyclopsI, NULL, NULL, MountainPtr);
    AddLinks(MountainPtr, NULL, CyclopsI, MeadowPtr, NULL);

    AddLinks(LaestPtr, NULL, NULL, LaestI, NULL);
    AddLinks(LaestI, LaestPtr, GlenPtr, ThicketPtr, ForestPtr);
    AddLinks(ForestPtr, NULL, LaestI, ThicketPtr, NULL);
    AddLinks(ThicketPtr, LaestI, GlenPtr, NULL, ForestPtr);
    AddLinks(GlenPtr, NULL, NULL, ThicketPtr, LaestI);

    AddLinks(PhaecPtr, NULL, NULL, NULL, NULL);
    AddLinks(PhaecI, PhaecPtr, DellPtr, LakePtr, GorgePtr);
    AddLinks(DellPtr, LakePtr, NULL, NULL, PhaecI);
    AddLinks(LakePtr, PhaecI, GorgePtr, DellPtr, NULL);
    AddLinks(GorgePtr, LakePtr, PhaecI, NULL, NULL);

    string blank;
    cout << "\n******************************************\n"
        <<  "* Welcome to the Game of Homer's Odyssey *\n"
        << "******************************************\n" << endl;
    cout<< "In this game you will explore islands and battle creatures.\n"
        << "Your goal is to get through all of the islands and reach your\n"
        << "home in Ithaca before you die of old age.\n"
        << "You are now 20 years old and will die at 100 years old\n"
        << "Each minute that you play, you will age a third of a decade.\n"
        << "If you lose a battle to a creature, \n"
        << "you will waste more time on their island!\n"
        << "\n\n**Hint: Spice related items are very useful\n\n"
        << "BEWARE: If you choose to go into a battle, you cannot go back\n"
        << "and you will be transported to a different island after\n"
        << "the battle\n\n" << endl;
    cout << "Type any key and hit [enter] to start. \n(Or enter the Konami Code (Up = U, etc.) in ALL CAPS and see what happens)" << endl;
    cin >> blank;

    Player *Player1 = new Player;
    if(blank == "UUDDLRLRBA")
    {
        cout << "\n**********************************************************" << endl;
        cout <<   "* Nice! You will now be transported to the final island! *" << endl;
        cout << "**********************************************************" << endl;
        Player1->SetLocation(PhaecI);

    }
    else
        Player1->SetLocation(CyclopsI);

    while(!Player1->GetComplete()  && Player1->GetElapsedTime() <= 100)
    {
    cout << "\nYou are" << Player1->GetLocation()->GetActionName() << Player1->GetLocation()->GetName() << " on the Island of "
        << Player1->GetLocation()->GetIslandName() << endl;

    if(Player1->GetLocation()->GetType() == Room::LANDSCAPETYPE)
    {
        if (Player1->GetLocation()->GetItem())
        {
            cout << "You found: " << Player1->GetLocation()->GetItem()->GetName() << "!" << endl;
            cout << "Would you like to take this item? (Y/N)" << endl;
            char choice;
            char choice2;
            bool error1;
            Item *droppedItem = NULL;
            do
            {
            error1 = false;
            cin >> choice;

                switch (choice)
                {
                    case 'Y':
                    case 'y':
                        if(Player1->checkFull())
                        {
                            cout << "Your bag is full!" << endl;
                            cout << "Would you like to delete an item? (Y/N)" << endl;

                            bool error2 = false;
                            cin >> choice2;
                            do
                            {
                                switch (choice2)
                                {
                                case 'Y':
                                case 'y':
                                    droppedItem = Player1->RemoveAnItem();
                                    break;
                                case 'N':
                                case 'n':
                                    break;
                                default:
                                    cout << "Please enter a valid choice: " << endl;
                                    error2 = true;

                                }

                            }while(error2);
                        }
                        break;
                        case 'N':
                        case 'n':
                        break;
                        default:
                            error1 = true;
                        }}while(error1);
                        if (!(Player1->checkFull()))
                        {
                            cout << "You have taken: " << Player1->GetLocation()->GetItem()->GetName() << endl;

                            Player1->GetBag()->push_back(Player1->GetLocation()->GetItem());

                            cout << "These are your items: " << endl;
                            cout << "1. " << Player1->GetBag()->at(0)->GetName() << endl;
                            if (Player1->GetBag()->size() == 2)
                                cout << "2. " << Player1->GetBag()->at(1)->GetName() << endl;
                            Player1->GetLocation()->RemoveItem();
                            if(droppedItem)
                            {
                                Player1->GetLocation()->SetItem(droppedItem);
                            }

                        }
            }
            else
                cout << "There is nothing useful here!" << endl;
        if (directionMenu(Player1))
            goto endIt;
        }

     else if(Player1->GetLocation()->GetType() == Room::FINISH)
    {
        Player1->SetComplete(true);
    }

    else if(Player1->GetLocation()->GetType() == Room::ISLANDTYPE)
    {
        if (directionMenu(Player1))
            goto endIt;
    }

    else if(Player1->GetLocation()->GetType() == Room::CREATURETYPE)
    {
        if (!Player1->GetLocation()->GetStatus())
        {
            cout << "Would you like to use an item during this challenge? (Y/N)?" << endl;
            char choice;
            char choice2;
            bool error1;
            bool goodItem = false;
            do
            {
            error1 = false;
            bool error2;
            int numChoice;

            cin >> choice;

                switch (choice)
                {
                    case 'Y':
                    case 'y':
                        if(Player1->GetBag()->size())
                        {
                            do
                            {
                            error2 = false;
                            cout << "Which item would you like to use?" << endl;
                            cout << "These are your items: " << endl;
                            cout << "1. " << Player1->GetBag()->at(0)->GetName() << endl;
                            if (Player1->GetBag()->size() == 2)
                                cout << "2. " << Player1->GetBag()->at(1)->GetName() << endl;
                            cin >> choice2;
                            numChoice = choice2 - 49;
                            if (numChoice >= 2 && numChoice < 0 )
                            {
                                cout << "Please enter a valid choice!" << endl;
                                error2 = true;
                            }
                            }while(error2);

                            if (Player1->GetBag()->at(numChoice)->GetName() == Player1->GetLocation()->GetCorrectItem())
                            {
                                cout << Player1->GetBag()->at(numChoice)->GetName() << " was super effective!" << endl;
                                cout << "Your challenge will be much easier now!" << endl;
                                goodItem = true;

                            }
                            else
                            {
                                 cout << Player1->GetBag()->at(numChoice)->GetName() << " did nothing!" << endl;
                                 cout << "What a waste, your challenge will not be any easier!" << endl;
                            }
                        }
                        else
                        {
                            cout << "You do not have any items in your bag!" << endl;
                        }
                        break;
                        case 'N':
                        case 'n':
                        break;
                        default:
                            error1 = true;
                        }}while(error1);
                        int TimeLoss = Player1->GetLocation()->Challenge(goodItem);
                        Player1->addTime(TimeLoss);
                        if (TimeLoss)
                        {
                            Player1->SetLocation(Player1->GetLocation()->GetLoseLocation());
                        }
                        else
                            Player1->SetLocation(Player1->GetLocation()->GetWinLocation());


        }

        else
        {
            cout << "You have completed this challenge against " << Player1->GetLocation()->GetName() << " and you ";
            if(Player1->GetLocation()->GetSuccess())
                cout << "succeeded!" << endl;

            else
                cout << "failed!" << endl;
            if (directionMenu(Player1))
                goto endIt;
        }

    }}
        cout << "\n************************************************************\n" << endl;
    if(Player1->GetComplete())
        cout << "You have finally returned to Ithaca! You have been at sea for: \n"
            << Player1->GetElapsedTime() - 20 << " years.\n"
            << "You have been reunited with your family at the age of: "
            << Player1->GetElapsedTime()
            << "\n\n************* Congratulations! ***********************\n" << endl;
    else
    {
        cout << "You have reached the age of 100 and have died a sad and lonely death." << endl;
        cout << "\n\n********************* Failure! ***********************\n" << endl;
    }


    cout << "\nWould you like to play again? (Y/N)" << endl;
    cin >> choice;

    do
    {
        switch(choice)
        {
        case 'Y':
        case 'y':
            repeat = true;
            break;
        case 'N':
        case 'n':
            repeat = false;
            break;
        default:
            cout << "\nPlease enter a valid choice!" << endl;
            error = true;
        }
    }while(error);

    endIt:
    delete Player1;
    delete CyclopsI;
    delete LaestPtr;
    delete LaestI;
    delete PhaecPtr;
    delete PhaecI;
    delete CyclopsPtr;
    delete PepperSprayPtr;
    delete PaprikaPtr;
    delete EtchASketch;
    delete Hedgehog;
    delete OneShoe;
    delete BananaPeal;
    delete DVD;
    delete RustyScrewdriver;
    delete HotRum;
    delete RocksPtr;
    delete ForestPtr;
    delete MeadowPtr;
    delete MountainPtr;
    delete ThicketPtr;
    delete GlenPtr;
    delete DellPtr;
    delete LakePtr;
    delete GorgePtr;
    delete IthacaI;



}while(repeat);


    return 0;
}

/*********************************************************************
** Function: bool directionMenu(Player *Player1)
** Description: a function that displays the options for the player
** depending on the links connected to his/her location
** Parameters: Player *Player
** Pre-Conditions: Linked room of Player's location must be set
** Post-Conditions: Location is changed to selection
*********************************************************************/

bool directionMenu(Player *Player1)
{
    char choice;
    cout << "\nPlease enter the selection of what you would like to do:" << endl;
    for (int i = 0; i < 4; ++i)
    {

        if (Player1->GetLocation()->GetLinkedRooms().at(i))
        {

            if (i == 0)
                cout << i + 1 << ". Travel North to";
            else if (i == 1)
                cout << i + 1 << ". Travel East to";
            else if (i == 2)
                cout << i + 1 << ". Travel South to";
            else if (i == 3)
                cout << i + 1 << ". Travel West to";
            cout << Player1->GetLocation()->GetLinkedRooms().at(i)->GetLookAtName()  << Player1->GetLocation()->GetLinkedRooms().at(i)->GetName() << endl;


        }
    }
    cout << "A. Check your age." << endl;
    cout << "B. View your items." << endl;
    cout << "Q. Quit the game." << endl;
    bool error = false;
    do
    {
    cin >> choice;
    if(!(choice <= '4' && choice >= '1' && Player1->GetLocation()->GetLinkedRooms().at(choice - 49))
       && choice != 65 && choice != 97 && choice != 66 && choice != 98 && choice != 'Q' && choice != 'q')
    {
        cout << "\nError: Please enter a valid choice!" << endl;
        error = true;
        return false;
    }
    else if (choice == 65 || choice == 97)
    {
        if(Player1->GetElapsedTime() > 100)
            return false;
        cout << setprecision(2);
        cout << fixed;
        cout << "Your age is: " << Player1->GetElapsedTime() << " Years." << endl;
        cout << "You have " << 80 - Player1->GetElapsedTime() << " Years to live ("<< (80 - Player1->GetElapsedTime()) / 3 << " minutes)!" << endl;
        directionMenu(Player1);
        return false;
    }
    else if (choice == 66 || choice == 98)
    {
        if (Player1->GetBag()->size())
        {
        cout << "These are your items: " << endl;
        cout << "1. " << Player1->GetBag()->at(0)->GetName() << endl;
        if (Player1->GetBag()->size() == 2)
            cout << "2. " << Player1->GetBag()->at(1)->GetName() << endl;
        }
        else
            cout << "Your bag is empty!" << endl;
        directionMenu(Player1);
        return false;

    }
    else if (choice == 'Q' || choice == 'q')
    {
        bool error;
        do{
        error = false;
        cout << "Do you really want to quit?(Y/N)" << endl;
        char choice;
        cin >> choice;
        switch(choice)
        {
        case 'Y':
        case 'y':
            return true;
            break;
        case 'N':
        case 'n':
            return false;
            break;
        default:
            cout << "\nPlease enter a valid selection!" << endl;
            error = true;
        }
        }while(error);

    }
    else
    {
        Player1->SetLocation(Player1->GetLocation()->GetLinkedRooms().at(choice - 49));
        error = false;
        return false;
    }
    }
    while(error);
}

/*********************************************************************
** Function:  void AddLinks (Room* Middle, Room* N, Room* E, Room* S, Room* W)
** Description: a function that adds links to a Room
** Parameters: (Room* Middle, Room* N, Room* E, Room* S, Room* W) - the first
** one is the one that links are added to
** Pre-Conditions: none
** Post-Conditions: Links are added to Room* Middle
*********************************************************************/

 void AddLinks (Room* Middle, Room* N, Room* E, Room* S, Room* W)
    {
        vector <Room*> Links;
        Links.push_back(N);
        Links.push_back(E);
        Links.push_back(S);
        Links.push_back(W);
        Middle->SetLinkedRooms(Links);
    }

