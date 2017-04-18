#ifndef ITEM_H
#define ITEM_H
#include <damagetypes.h>

class Item
{
    int id;
    int maxDurability;
    int durability;
    DamageTypes damageT;
public:
    Item();
    bool isBroken();
    int getId();
    void lowDurability();
    DamageTypes getDamageTypes();
};

#endif // ITEM_H
