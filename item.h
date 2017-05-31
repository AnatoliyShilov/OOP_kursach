#ifndef ITEM_H
#define ITEM_H
#include <damagetypes.h>
#include <string.h>

struct ItemInfo//обертка информации о предмете
{
    int id;
    char name[50];
    int cost;
    int maxDurability;
    int durability;
    DamageTypesInfo damageT;
};

class Item//предмет
{
    int id;//идентификатор
    char name[50];//название
    int cost;//стоимость
    int maxDurability;//максимальная прочность
    int durability;//текущая прочность
    DamageTypes damageT;//типы урона
public:
    Item();
    ItemInfo getInfo();//упаковать данные в обертку и вернуть ее
    void setInfo(ItemInfo info);//распаковать данные из обертки и успановить их
    bool isBroken();//инстанна если оружие сломано//текущая прочность == 0
    int getId();//вернуть идентификатор
    int getCost();//вернуть стоимость
    void lowDurability();//снизить текущую прочность// текущая прочность - 1
    void resetDurability();//сбросить текущую прочность// текущая прочность = максимальная прочность
    DamageTypes getDamageTypes();//вернуть типы урона
};

#endif // ITEM_H
