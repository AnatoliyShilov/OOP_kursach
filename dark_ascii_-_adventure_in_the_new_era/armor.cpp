#include "armor.h"

Armor::Armor()
{
    Armor::weight = 0;
    Armor::type = ArmorType::helmet;
}

ArmorType Armor::getType()
{
    return type;
}
