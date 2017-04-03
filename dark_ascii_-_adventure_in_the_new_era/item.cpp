#include "item.h"

Item::Item()
{

}

void Item::lowDurability()
{
    durability--;
}

DamageTypes Item::getDamageTypes()
{
    return damageT;
}
