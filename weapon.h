#ifndef WEAPON_H
#define WEAPON_H
#include <item.h>
enum WeaponType
{
    Attack,
    Shield
};

struct WeaponInfo
{
    WeaponType weaponType;
    int weight;
    ItemInfo item;
};

class Weapon: public Item
{
    WeaponType weaponType;//сохранить
    int weight;//сохранить
public:
    WeaponInfo getInfo();
    void setInfo(WeaponInfo info);
    Weapon();
    WeaponType getType();
    int getWeight();
};

#endif // WEAPON_H
