#ifndef INVENTORYCONTROLLER_H
#define INVENTORYCONTROLLER_H
#include "abstractcontroller.h"


class InventoryController: public AbstractController
{
    int (InventoryController::*options[5])(int);
    int playerInfo(int key);
    int equipments(int key);
    int weapons(int key);
    int armors(int key);
    int accessories(int key);
    Armor selectArmor(ArmorType type);
    Accessory selectAccessory();
    Weapon selectWeapon();
public:
    InventoryController();
    virtual int start();
};

#endif // INVENTORYCONTROLLER_H
