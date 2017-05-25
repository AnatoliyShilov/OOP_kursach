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

struct ArmorInfo
{
    ArmorType type;
    int weight;
    ItemInfo item;
};

class Armor: public Item
{
    ArmorType type;//сохранить
    int weight;//сохранить
public:
    ArmorInfo getInfo();
    void setInfo(ArmorInfo info);
    ArmorType getType();
    int getWeight();
    Armor();
};

#endif // ARMOR_H
