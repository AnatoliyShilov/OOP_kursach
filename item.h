#ifndef ITEM_H
#define ITEM_H
#include <damagetypes.h>

class Item
{
    int id;//сохранить
    char name[50];//сохранить
    int maxDurability;//сохранить
    int durability;//сохранить
    DamageTypes damageT;//сохранить
public:
    Item();
    bool isBroken();
    int getId();
    void lowDurability();
    void resetDurability();
    DamageTypes getDamageTypes();
};

#endif // ITEM_H
