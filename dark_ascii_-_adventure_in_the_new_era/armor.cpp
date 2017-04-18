#include "armor.h"

Armor::Armor()
{
    weight = 0;
    type = ArmorType::helmet;
}



int Armor::getWeight()
{
    return weight;
}

ArmorType Armor::getType()
{
    return type;
}
