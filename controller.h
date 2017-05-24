#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <allnpc.h>
#include <allitems.h>
#include <level.h>
#include <player.h>
#include "additionfunction.h"

class Controller
{
    Player player;
    Coordinates playerPos;
    Coordinates traiderPos;
    Coordinates firePos;
    AllNPC allNPC;
    AllItems allItems;
    void (Controller::*fMain[2])();
    int currentlvl;
    Level lvl;
    Sprites sprites;
public:
    Controller();
    void Run();
private:
    void newGame();
    void continueGame();
    void exitGame();

    void gameTick();

    int menuMain();//
    int menuPause();//

    /////////////////
    int menuInventory();
    int menuSmith();
    int menuLvlUp();
    int menuTrade();
    int menuBattle();
    //////////////////

    void changeCoords();
    void checkCell();
    void drawRoom();
};

#endif // CONTROLLER_H
