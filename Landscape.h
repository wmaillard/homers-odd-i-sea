#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include "Room.h"




class Landscape : public Room
{
    public:
        Landscape();
        virtual ~Landscape();
        Item *GetItem() { return m_Item; }
        void SetItem(Item *val) { m_Item = val; }
        void RemoveItem(){m_Item = NULL;}

    protected:
    private:
        Item *m_Item;

};

#endif // LANDSCAPE_H
