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
#include "battlecontroller.h"

class Controller//главный контроллер
{
    Player player;//игрок
    Coordinates playerPos;//относительная позиция игрока
    Coordinates traiderPos;//относительная позиция торговца
    Coordinates firePos;//относительная позиция костра
    Coordinates chestPos;//относительная позиция сундука
    AllNPC allNPC;//все НПС
    AllItems allItems;//все предметы
    void (Controller::*fMain[2])();//функции главного меню
    int currentlvl;//номер текущего уровня
    Level lvl;//уровень
    Sprites sprites;//страйты
    LvlUPController lvlUpMenu;//контроллер меню повышения уровня и быстрого перемещения
    InventoryController inventoryMenu;//контроллер инвентаря
    TraideController traideMenu;//контроллер торговли
    BattleController battleMenu;//контроллер битвы
public:
    Controller();
    ~Controller();
    void Run();//запуск главного контроллера
private:
    void newGame();//начать новую игру
    void continueGame();//продолжить игру с последнего сохранения
    void exitGame();//выйти из игры
    void setCurrentLvl();//проверить и усановить текущий уровень//применяется в обратной связи при быстром перемещении
    void gameTick();//игровой такт//премещение персонажа//проверка ячеек//инициализации меню взаимодействий//запуск сражений
    int menuMain();//главное меню
    int menuPause();//меню паузы
};

#endif // CONTROLLER_H
