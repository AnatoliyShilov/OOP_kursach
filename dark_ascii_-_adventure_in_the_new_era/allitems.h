#ifndef ALLITEMS_H
#define ALLITEMS_H
#include <armor.h>
#include <accessory.h>
#include <weapon.h>
#include <throwing.h>
#include <list>
using namespace std;
class AllItems
{
    list <Armor> armors;
    list <Weapon> weapons;
    list <Accessory> accessories;
    list <Throwing> throwings;
public:
    AllItems();
};

#endif // ALLITEMS_H
