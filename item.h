#ifndef ITEM_H
#define ITEM_H
#include <damagetypes.h>
#include <string.h>

struct ItemInfo
{
    int id;
    char name[50];
    int cost;
    int maxDurability;
    int durability;
    DamageTypesInfo damageT;
};

class Item
{
    int id;
    char name[50];
    int cost;
    int maxDurability;
    int durability;
    DamageTypes damageT;
public:
    Item();
    ItemInfo getInfo();
    void setInfo(ItemInfo info);
    bool isBroken();
    int getId();
    int getCost();
    void lowDurability();
    void resetDurability();
    DamageTypes getDamageTypes();
};

#endif // ITEM_H
