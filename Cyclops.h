#ifndef Cyclops_H
#define Cyclops_H

#include "Creature.h"



class Cyclops : public Creature
{
    public:
        //using Creature::Creature;
        Cyclops();
        virtual ~Cyclops();
        std::string GetCorrectItem(){return CorrectItem;}

    protected:
    private:
        int Challenge(bool itemUsed);
        std::string CorrectItem;

};

#endif // Cyclops_H
