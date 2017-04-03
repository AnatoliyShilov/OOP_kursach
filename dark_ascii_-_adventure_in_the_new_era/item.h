#ifndef ITEM_H
#define ITEM_H
#include <damagetypes.h>

class Item
{
    int id;
    int durability;
    DamageTypes damageT;
public:
    Item();
    void lowDurability();
    DamageTypes getDamageTypes();
};

#endif // ITEM_H
