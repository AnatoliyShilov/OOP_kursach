#ifndef INVENTORYCONTROLLER_H
#define INVENTORYCONTROLLER_H
#include "abstractcontroller.h"


class InventoryController: public AbstractController//контроллер инвентаря
{
    int (InventoryController::*options[5])(int);//функции меню инвентаря
    int playerInfo(int key);//инвормация об игроке
    int equipments(int key);//экипировка
    int weapons(int key);//список оружия в сумке
    int armors(int key);//список брони в сумке
    int accessories(int key);//список аксессуаров в сумке
    Armor selectArmor(ArmorType type);//выбрать доспех определенного типа
    Accessory selectAccessory();//выбрать аксессуар
    Weapon selectWeapon();//выбрать оружие
public:
    InventoryController();
    virtual int start();//запуск контроллера
};

#endif // INVENTORYCONTROLLER_H
