#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <allnpc.h>
#include <allitems.h>
#include <level.h>
#include <player.h>

#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_TAB 9
#define KEY_E 69
#define KEY_BACKSPACE 8
#define KEY_UP 38
#define KEY_LEFT 37
#define KEY_DOWN 40
#define KEY_RIGHT 39
#define KEY_W 87
#define KEY_A 65
#define KEY_S 83
#define KEY_D 68

class Controller
{
    Player player;
    AllNPC allNPC;
    AllItems allItems;
    Level level;        //текущий уровень
public:
    Controller();
    void FinishLevel();     //TODO
    void StopGame();        //TODO
    void GameTick();        //almost done - метод получается самым большим
    void menuInventory();   //TODO
    void menuBattle();      //TODO
    void menuInteract();    //TODO
    void menuSmith();       //TODO
    void menuPause();       //TODO
    void menuLvlUp();       //TODO
    void menuTrade();       //TODO
    bool dice(int lowBorder, int highBorder);
    bool npcNear(Coords coords);
    void changeCoords(int newX, int newY);
    void effectByCell(Cell cell);
    void drawRoom();        //TODO
};

#endif // CONTROLLER_H
