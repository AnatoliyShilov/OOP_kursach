#ifndef BATTLECONTROLLER_H
#define BATTLECONTROLLER_H
#include "abstractcontroller.h"
#include "npc.h"
#include "allnpc.h"

class BattleController : public AbstractController
{
    AllNPC *npcs;
    void battle(NPC *enemy, int enemyCount);
public:
    BattleController();
    virtual int start();
    void setNPCs(AllNPC &npcs);
};

#endif // BATTLECONTROLLER_H
