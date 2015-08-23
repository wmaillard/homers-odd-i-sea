#ifndef PHAECIANS_H
#define PHAECIANS_H

#include "Creature.h"


class Phaecians : public Creature
{
    public:
        Phaecians();
        virtual ~Phaecians();
        std::string GetCorrectItem(){return CorrectItem;}
    protected:
    private:
        int Challenge(bool itemUsed);
        std::string CorrectItem;
};

#endif // PHAECIANS_H
