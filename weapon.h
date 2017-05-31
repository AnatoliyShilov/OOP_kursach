#ifndef WEAPON_H
#define WEAPON_H
#include <item.h>
enum WeaponType//тип оружия
{
    Attack,//атакующее
    Shield//щит
};

struct WeaponInfo//обертка информации об оружии
{
    WeaponType weaponType;
    int weight;
    ItemInfo item;
};

class Weapon: public Item//оружие
{
    WeaponType weaponType;//тип оружия
    int weight;//вес
public:
    WeaponInfo getInfo();//упаковать информацию в обертку и вернуть ее
    void setInfo(WeaponInfo info);//извлечь информацию из обертки и установить
    Weapon();
    WeaponType getType();
    int getWeight();//вернуть вес
};

#endif // WEAPON_H
