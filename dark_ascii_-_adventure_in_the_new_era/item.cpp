#include "item.h"

Item::Item()
{
    Item::id = -1;
    Item::durability = -1;
}

bool Item::isBroken()
{
    if (durability <= 0)
        return true;
    return false;
}

int Item::getId()
{
    return id;
}

void Item::lowDurability()
{
    durability--;
}

DamageTypes Item::getDamageTypes()
{
    return damageT;
}
