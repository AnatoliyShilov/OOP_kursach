#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <allnpc.h>
#include <allitems.h>
#include <level.h>
#include <player.h>
#include "additionfunction.h"
#include "inventorycontroller.h"
#include "traidecontroller.h"
#include "lvlupcontroller.h"

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
    LvlUPController lvlUpMenu;
    InventoryController inventoryMenu;
    TraideController traideMenu;
public:
    Controller();
    void Run();
private:
    void newGame();
    void continueGame();
    void exitGame();
    void setCurrentLvl();
    void gameTick();
    int menuMain();//
    int menuPause();//

    /////////////////
    int menuBattle();
    //////////////////

    void changeCoords();
    void checkCell();
    void drawRoom();
};

#endif // CONTROLLER_H
