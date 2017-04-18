#ifndef PLAYER_H
#define PLAYER_H
#include <actor.h>
#include <bag.h>

class Player: public Actor
{
    Bag bag;//сумка
    int nextLvlCost;//стоимоть следующего уровня
    int maxFastTravelId;//на сколько далеко можно переместиться

public:
    Player();
    void loot(Bag bag);
    Bag openBag();//просмотр сумки
    void changeCoords(int dx, int dy);//переместиться
    void changeArmor(Armor armorNew, int index);//сменить броню
    Armor selectArmor(int id);//выбрать броню//возможно должно быть не здесь
    void changeChars(Chars chars);//повышение характеристик
    void changeWeapon(Weapon weaponNew, int index);//выбрать оружие//возможно должно быть не здесь
    void changeAccessory(Accessory acessoryNew, int index);//выбрать аксессуар//возможно должно быть не здесь
};

#endif // PLAYER_H
