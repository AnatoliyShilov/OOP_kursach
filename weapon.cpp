#include "weapon.h"

void Weapon::setInfo(WeaponInfo info)
{
    this->weaponType = info.weaponType;
    this->weight = info.weight;
    Item::setInfo(info.item);
}

WeaponInfo Weapon::getInfo()
{
    WeaponInfo info;
    info.item = Item::getInfo();
    info.weaponType = this->weaponType;
    info.weight = this->weight;
    return info;
}

Weapon::Weapon()
{
    Weapon::weaponType = WeaponType::Attack;
    Weapon::weight = 0;
}

WeaponType Weapon::getType()
{
    return weaponType;
}

int Weapon::getWeight(){
    return weight;
}
