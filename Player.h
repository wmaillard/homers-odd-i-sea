#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Room.h"
#include <iostream>
#include <ctime>



class Player
{
    public:
        Player();
        virtual ~Player();
        std::string GetName() { return m_Name; }
        void SetName(std::string val) { m_Name = val; }
        Room* GetLocation() { return m_Location; }
        void SetLocation(Room* val) { m_Location = val; }
        std::vector <Item*>* GetBag() { return &m_Bag; }
        void SetBag(std::vector <Item*> val) { m_Bag = val; }
        double GetGameTime() { return m_GameTime; }
        void SetGameTime(double val) { m_GameTime = val; }
        void SetComplete(bool val) {m_Complete = val;}
        bool GetComplete() { return m_Complete;}
        void addItem(Item);
        void removeItem(Item);
        Item* RemoveAnItem();
        std::string useItem(int i);
        bool checkFull();
        double GetElapsedTime();
        void addTime(double extraTime){m_GameTime-=extraTime*20;};



    protected:
    private:
        std::string m_Name;
        Room *m_Location;
        std::vector <Item*> m_Bag;


        double m_GameTime;
        bool m_Complete;
};

#endif // PLAYER_H
