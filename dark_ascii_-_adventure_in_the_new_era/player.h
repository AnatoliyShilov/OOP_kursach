#ifndef PLAYER_H
#define PLAYER_H
#include <actor.h>
#include <bag.h>

class Player: public Actor
{
    Bag bag;//сумка
    int nextLvlCost;//стоимоть следующего уровня
    int maxFastTravelId;//на сколько далеко можно переместиться
    int luck;//параметр удачи//вероятность получения предмета с врага// интервал [0; luck]
public:
    Player();
    Bag openBag();//просмотр сумки
    void changeCoords(int dx, int dy);//переместиться
    void changeArmor(Armor armorNew, int index);//сменить броню
    Armor selectArmor(int id);//выбрать броню//возможно должно быть не сдесь
    void changeChars();//повышение характеристик
    void changeWeapon(Weapon weaponNew, int index);//выбрать оружие//возможно должно быть не сдесь
    void changeAccessory(Accessory acessoryNew, int index);//выбрать аксессуар//возможно должно быть не сдесь
};

#endif // PLAYER_H
