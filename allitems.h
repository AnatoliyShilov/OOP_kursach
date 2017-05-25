#ifndef ALLITEMS_H
#define ALLITEMS_H
#include <armor.h>
#include <accessory.h>
#include <weapon.h>
#include "dynamic.h"
#include "additionfunction.h"
#include <fstream>
using namespace std;
class AllItems
{

public:
    List <Armor> armors;//сохранить
    List <Weapon> weapons;//сохранить
    List <Accessory> accessories;//сохранить
    void save(const char *file);
    int load(const char *file);
    AllItems();
};

#endif // ALLITEMS_H
