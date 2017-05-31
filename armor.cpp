#include "armor.h"

void Armor::setInfo(ArmorInfo info)
{
    this->type = info.type;
    this->weight = info.weight;
    Item::setInfo(info.item);
}

Armor::Armor()
{
    weight = 0;
    type = ArmorType::helmet;
}

ArmorInfo Armor::getInfo()
{
    ArmorInfo info;
    info.item = Item::getInfo();
    info.type = this->type;
    info.weight = this->weight;
    return info;
}

int Armor::getWeight()
{
    return weight;
}

ArmorType Armor::getType()
{
    return type;
}
