#ifndef ITEM_H
#define ITEM_H
#include <damagetypes.h>
#include <string.h>

struct ItemInfo
{
    int id;//сохранить
    char name[50];//сохранить
    int maxDurability;//сохранить
    int durability;//сохранить
    DamageTypesInfo damageT;//сохранить
};

class Item
{
    int id;//сохранить
    char name[50];//сохранить
    int maxDurability;//сохранить
    int durability;//сохранить
    DamageTypes damageT;//сохранить
public:
    Item();
    ItemInfo getInfo();
    void setInfo(ItemInfo info);
    bool isBroken();
    int getId();
    void lowDurability();
    void resetDurability();
    DamageTypes getDamageTypes();
};

#endif // ITEM_H
