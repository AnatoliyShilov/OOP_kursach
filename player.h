#ifndef PLAYER_H
#define PLAYER_H
#include <actor.h>

#include <fstream>

struct PlayerInfo
{
    int curentLvl;
    int nextLvlCost;
    int maxFastTravelId;
    int memoryFragments;
    Chars charsMax;
    Chars charsCurrent;
};

class Player: public Actor
{

    int curentLvl;//текущий уровень персонажа//сохранить
    int nextLvlCost;//стоимоть следующего уровня//сохранить
    int maxFastTravelId;//на сколько далеко можно переместиться//сохранить
public:
    Player();
    PlayerInfo getInfo();
    void save(const char *file);
    void load(const char *file, AllItems *allItems);
    void setFastTravel(int lvlId);
    int getFastTravel();
    int getNextLvlCost();
    void changeLvl(Chars dxChars, int dxLvl);
    void lvl0();
    void rest();
    void loot(Bag *bag);
    void sort();
    void cleanArmor(int index);
    void cleanWeapon(int index);
    void cleanAccessory(int index);
    void changeArmor(Armor armorNew, int index);//сменить броню
    void changeWeapon(Weapon weaponNew, int index);//выбрать оружие
    void changeAccessory(Accessory acessoryNew, int index);//выбрать аксессуар
};

#endif // PLAYER_H
