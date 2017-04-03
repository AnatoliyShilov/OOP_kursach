#ifndef NPC_H
#define NPC_H
#include <actor.h>

class NPC: public Actor
{
    int id;
    bool isEnemy;
public:
    NPC();
};

#endif // NPC_H
