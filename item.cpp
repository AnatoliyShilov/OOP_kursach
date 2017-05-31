#include "item.h"

int Item::getCost()
{
    return cost;
}

void Item::setInfo(ItemInfo info)
{
    this->damageT.setInfo(info.damageT);
    this->durability = info.durability;
    this->id = info.id;
    this->maxDurability = info.maxDurability;
    strcpy(this->name, info.name);
    this->cost = info.cost;
}

ItemInfo Item::getInfo()
{
    ItemInfo info;
    info.damageT = this->damageT.getInfo();
    info.durability = this->durability;
    info.id = this->id;
    info.maxDurability = this->maxDurability;
    strcpy(info.name, this->name);
    info.cost = this->cost;
    return info;
}

void Item::resetDurability()
{
    durability = maxDurability;
}

Item::Item()
{
    Item::id = 0;
    Item::durability = 0;
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
