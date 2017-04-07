#ifndef ALLITEMS_H
#define ALLITEMS_H
#include <armor.h>
#include <accessory.h>
#include <weapon.h>
#include <throwing.h>
#include "dynamic.h"
using namespace std;
class AllItems
{

public:
    List <Armor> armors;
    List <Weapon> weapons;
    List <Accessory> accessories;
    List <Throwing> throwings;
    AllItems();
};

#endif // ALLITEMS_H
