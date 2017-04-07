#include "armor.h"

Armor::Armor()
{
    Armor::weight = 0;
    Armor::set = ArmorSet::helmet;
}

ArmorSet Armor::getArmorType()
{
    return set;
}
