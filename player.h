#ifndef PLAYER_H
#define PLAYER_H
#include <actor.h>

#include <fstream>

struct PlayerInfo//обертка информации об игроке
{
    int curentLvl;
    int nextLvlCost;
    int maxFastTravelId;
    int memoryFragments;
    Chars charsMax;
    Chars charsCurrent;
};

class Player: public Actor//игрок
{

    int curentLvl;//текущий уровень персонажа
    int nextLvlCost;//стоимоть следующего уровня
    int maxFastTravelId;//на сколько далеко можно переместиться
public:
    Player();
    PlayerInfo getInfo();//упаковать данные в обертку и вернуть ее
    void save(const char *file);//сохранить данные игрока в файл
    void load(const char *file, AllItems *allItems);// загрузить данные игрока из файла
    void setFastTravel(int lvlId);//установить максимальный номер уровня для быстрого перемещения
    int getFastTravel();//вернуть максимальный номер уровня для быстрого перемещения
    int getNextLvlCost();//вернуть стоимость усовершенствования на следующий уровень
    void changeLvl(Chars dxChars, int dxLvl);//изменить уровень и характеристики игрока
    void lvl0();//сбросить игрока до 0 уровеня
    void rest();//персонаж отдыхает//восстанавливается здоровье и количество аптечек, чинится снаряжение
    void loot(Bag *bag);//обыскать внешнее хранилище предметов и поместить содержимое в сумку игрока
    void sort();//сортировать содержимое сумки
    void cleanArmor(int index);//убрать броню из указанного слота
    void cleanWeapon(int index);//убрать оружие из указанного слота
    void cleanAccessory(int index);//убрать аксессуар из указанного слота
    void changeArmor(Armor armorNew, int index);//выбрать и сменить указанную броню
    void changeWeapon(Weapon weaponNew, int index);//выбрать и сменить указанное оружие
    void changeAccessory(Accessory acessoryNew, int index);//выбрать и сменить указанный аксессуар
};

#endif // PLAYER_H
