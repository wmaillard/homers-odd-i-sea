#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
#include "Item.h"


class Room
{
    public:
        enum TYPE
            {
                ISLANDTYPE,
                CREATURETYPE,
                LANDSCAPETYPE,
                FINISH
            };
        Room();
        virtual ~Room();
        virtual std::string GetName() { return m_Name; }
        virtual void SetName(std::string val) { m_Name = val; }
        virtual TYPE GetType() { return m_Type; }
        virtual void SetType(TYPE val) { m_Type = val; }
        virtual std::string GetActionName() { return m_ActionName; }
        virtual void SetActionName(std::string val) { m_ActionName = val; }
        virtual std::string GetLookAtName() { return m_LookAtName; }
        virtual void SetLookAtName(std::string val) { m_LookAtName = val; }
        virtual std::vector <Room*> GetLinkedRooms() { return LinkedRooms; }
        virtual void SetLinkedRooms(std::vector <Room*> val) { LinkedRooms = val; }
        virtual bool GetStatus() { return Status; }
        virtual void SetStatus(bool val) { Status = val; }
        virtual bool GetSuccess() { return Success; }
        virtual void SetSuccess(bool val) { Success = val; }
        virtual void SetIslandName (std::string val){m_IslandName = val;}
        virtual std::string GetIslandName () {return m_IslandName;}
        virtual int Challenge(bool){}
        virtual Item *GetItem() {}
        virtual void SetItem(Item *val) {}
        virtual void RemoveItem(){}
        virtual std::string GetCorrectItem(){}
        virtual Room* GetWinLocation() {}
        virtual void SetWinLocation(Room* val) {}
        virtual Room* GetLoseLocation() {}
        virtual void SetLoseLocation(Room* val) {}

    protected:
    //private:
        std::string m_Name;
        TYPE m_Type;
        std::string m_ActionName;
        std::string m_IslandName;
        std::vector <Room*> LinkedRooms;
        std::string m_LookAtName;
        bool Status;
        bool Success;

};

#endif // ROOM_H
