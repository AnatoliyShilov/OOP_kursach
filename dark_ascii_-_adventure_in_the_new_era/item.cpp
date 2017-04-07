#include "item.h"

Item::Item()
{
    Item::id = -1;
    Item::durability = -1;
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
