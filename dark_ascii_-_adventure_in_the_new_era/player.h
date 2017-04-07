#ifndef PLAYER_H
#define PLAYER_H
#include <actor.h>
#include <bag.h>

class Player: public Actor
{
    Bag bag;
    int souls;
public:
    Player();
    Bag openBag();
    void changeCoords(int dx, int dy);
    void changeArmor(Armor armorNew, int index);
    Armor selectArmor(int id);
    void changeChars();
    void changeWeapon(Weapon weaponNew, int index);
    void changeAccessory(Accessory acessoryNew, int index);
};

#endif // PLAYER_H
