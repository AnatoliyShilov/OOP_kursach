#ifndef NPC_H
#define NPC_H
#include <actor.h>
#include "bag.h"

class NPC: public Actor
{
    int id;
    bool isEnemy;
    Bag bag;
public:
    Bag getBag();
    NPC();
};

#endif // NPC_H
