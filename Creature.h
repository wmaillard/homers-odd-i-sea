#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <istream>
#include "Room.h"
#include <cstdlib>
#include <ctime>


class Creature : public Room
{
    public:
        Creature();
        virtual ~Creature();
        Room* GetLoseLocation() { return LoseLocation; }
        void SetLoseLocation(Room* val) { LoseLocation = val; }
        Room* GetWinLocation() { return WinLocation; }
        void SetWinLocation(Room* val) { WinLocation = val; }

    protected:
        Room *WinLocation;
        Room *LoseLocation;


};

#endif // CREATURE_H
