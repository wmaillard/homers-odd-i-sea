#ifndef LAEST_H
#define LAEST_H

#include "Creature.h"
#include <ctime>


class Laest : public Creature
{
    public:
        Laest();
        virtual ~Laest();
        std::string GetCorrectItem(){return CorrectItem;}
    protected:
    private:
        int Challenge(bool itemUsed);
        std::string CorrectItem;
};

#endif // Laest_H
