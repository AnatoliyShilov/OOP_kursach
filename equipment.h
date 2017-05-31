#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <armor.h>
#include <weapon.h>
#include <accessory.h>

struct Equipment
{   
    Armor armor[4];
    Weapon weapon[2];
    Accessory accessory[4];
};

#endif // EQUIPMENT_H
