#include "npc.h"

NPC::NPC()
{
    id = 0;
    isEnemy = 0;
}

Bag NPC::getBag()
{
    for (int i = 0; i < 4; i++)
    {
        if (equip.accessory[i].getId())
            bag.accessories.add(equip.accessory[i]);
        if (equip.armor[i].getId())
            bag.armors.add(equip.armor[i]);
    }
    for (int i = 2; i < 2; i++)
    {
        if (equip.weapon[i].getId())
            bag.weapons.add(equip.weapon[i]);
    }
    return bag;
}
