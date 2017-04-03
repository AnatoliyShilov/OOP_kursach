#ifndef WEAPON_H
#define WEAPON_H
#include <item.h>

class Weapon: public Item
{
    int weight;
public:
    Weapon();
    int getWeight();
};

#endif // WEAPON_H
