#ifndef ARMOR_H
#define ARMOR_H
#include <item.h>
enum ArmorSet
{
    helmet,
    armor,
    gloves,
    leggings
};

class Armor: public Item
{
    ArmorSet set;
    int weight;
public:
    ArmorSet getArmorType();
    Armor();
};

#endif // ARMOR_H
