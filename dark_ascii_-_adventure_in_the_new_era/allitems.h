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
    List <Armor> armors;//сохранить
    List <Weapon> weapons;//сохранить
    List <Accessory> accessories;//сохранить
    List <Throwing> throwings;//сохранить
    AllItems();
};

#endif // ALLITEMS_H
