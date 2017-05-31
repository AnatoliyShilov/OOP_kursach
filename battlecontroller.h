#ifndef BATTLECONTROLLER_H
#define BATTLECONTROLLER_H
#include "abstractcontroller.h"
#include "npc.h"
#include "allnpc.h"

class BattleController : public AbstractController//контроллер битвы
{
    AllNPC *npcs;//все НПС
    void battle(NPC *enemy, int enemyCount);//сражение
    //игрок сражается со случайными enemy в количестве enemyCount (от 1 до 5)
public:
    BattleController();
    virtual int start();//запуск контроллера
    void setNPCs(AllNPC &npcs);//установить НПС
};

#endif // BATTLECONTROLLER_H
