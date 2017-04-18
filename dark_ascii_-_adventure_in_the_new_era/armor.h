#ifndef ARMOR_H
#define ARMOR_H
#include <item.h>
enum ArmorType
{
    helmet,
    armor,
    gloves,
    leggings
};

class Armor: public Item
{
    ArmorType type;
    int weight;
public:
    ArmorType getType();
    int getWeight();
    Armor();
};

#endif // ARMOR_H
