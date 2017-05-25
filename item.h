#ifndef ITEM_H
#define ITEM_H
#include <damagetypes.h>

class Item
{
    int id;//���������
    char name[50];//���������
    int maxDurability;//���������
    int durability;//���������
    DamageTypes damageT;//���������
public:
    Item();
    bool isBroken();
    int getId();
    void lowDurability();
    void resetDurability();
    DamageTypes getDamageTypes();
};

#endif // ITEM_H
