#ifndef NPC_H
#define NPC_H
#include <actor.h>
#include "bag.h"

class NPC: public Actor//добавить имя
{
    int id;//сохранить
    char name[50];//сохранить
    bool isEnemy;//сохранить
    Bag bag;//сохранить
public:
    Bag getBag();
    NPC();
};

#endif // NPC_H
