#include "Creature.h"

Creature::Creature()
{
    SetActionName(" at the battle ground of ");
    SetLookAtName(" battle ");
    SetType(CREATURETYPE);
    SetStatus(false);
    SetSuccess(false);

}

Creature::~Creature()
{
    //dtor
}
