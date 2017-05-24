#include "weapon.h"

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
