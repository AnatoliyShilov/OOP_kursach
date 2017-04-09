#ifndef WEAPON_H
#define WEAPON_H
#include <item.h>
enum WeaponType
{
    Attack,
    Shield
};

class Weapon: public Item
{
    WeaponType weaponType;
    int weight;
public:
    Weapon();
    WeaponType getType();
    int getWeight();
};

#endif // WEAPON_H
