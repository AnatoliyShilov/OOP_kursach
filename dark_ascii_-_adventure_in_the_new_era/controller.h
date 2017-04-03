#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <allnpc.h>
#include <allitems.h>
#include <level.h>
#include <player.h>

class Controller
{
    Player player;
    AllNPC allNPC;
    AllItems allItems;
public:
    Controller();
    void End();
    void GameTick();
    void menuInventory();
    void menuBattle();
    void menuSmith();
    void menuPause();
    void menuLvlUp();
    void menuTrade();
    int dice();
    void changeCoords();
    void checkCell();
    void drawRoom();
};

#endif // CONTROLLER_H
