#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <armor.h>
#include <weapon.h>
#include <accessory.h>

class Equipment
{   
public:
    Armor armor;
    Weapon weapon[2];
    Accessory accessory[4];
    Equipment();
};

#endif // EQUIPMENT_H
