#ifndef ALLITEMS_H
#define ALLITEMS_H
#include <armor.h>
#include <accessory.h>
#include <weapon.h>
#include "dynamic.h"
#include "additionfunction.h"
#include <fstream>
using namespace std;
class AllItems//все предметы//хранит все возможные предметы в игре
{
public:
    List <Armor> armors;//доспехи
    List <Weapon> weapons;//оружие
    List <Accessory> accessories;//аксессуары
    void save(const char *file);//сохранить в файл
    int load(const char *file);//загрузить из файла
    AllItems();
};

#endif // ALLITEMS_H
