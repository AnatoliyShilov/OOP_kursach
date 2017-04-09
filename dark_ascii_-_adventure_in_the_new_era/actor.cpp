#include "actor.h"

Actor::Actor()
{
    Actor::carry =
    Actor::health =
    Actor::memoryFragments =
    Actor::stamina =
    Actor::regenS = 0;
    Actor::dead =
    Actor::parry =
    Actor::deviation =
    Actor::equip.twoHanded[0] =
    Actor::equip.twoHanded[1] =
    Actor::protection = false;
}

void Actor::regenStamina()
{
    stamina += regenS;
    if (stamina > charsMax.stamina)
        stamina = charsMax.stamina;
}

 int Actor::is2handed()
 {
     return equip.twoHanded[0] - equip.twoHanded[1];
 }

void Actor::set2handedW0()
{
    equip.twoHanded[0] = true;
    equip.twoHanded[1] = false;
}

void Actor::set2handedW1()
{
    equip.twoHanded[0] = false;
    equip.twoHanded[1] = true;
}

void Actor::unset2handed()
{
    equip.twoHanded[0] =
    equip.twoHanded[1] = false;
}

int Actor::getDex()
{
    int dexterity = charsMax.dexterity;
    for (int i = 0; i < 4; i++)
        if (equip.accessory[i].getType() == AccessoryType::charsAdd)
            dexterity += equip.accessory[i].getCharsBonus().dexterity;
    return dexterity;
}

void Actor::useMedKit()
{
    health += medkit.useMedKit();
    if (health > charsMax.health)
        health = charsMax.health;
}

bool Actor::isParry(int enemyDex)
{
    if (parry)
    {
        int currentDex = getDex() - enemyDex;
        if (currentDex / 2 > Dice::roll())
            return true;
    }
    return false;
}

DamageTypes Actor::makeDamage(int weapon)
{
    if (weapon > 1)
        weapon = 1;
    if (weapon < 0)
        weapon = 0;
    if (is2handed() == 1)
        weapon = 1;
    if (is2handed() == -1)
        weapon = 0;
    DamageTypes result;
    int currentStrenght = charsMax.strenght;
    for (int i = 0; i < 4; i++)
    {
        if (equip.accessory[i].getType() == AccessoryType::attack)
        {
            result.add(equip.accessory[i].getDamageTypes());
            equip.accessory[i].lowDurability();
        }
        if (equip.accessory[i].getType() == AccessoryType::charsAdd)
        {
            currentStrenght += equip.accessory[i].getCharsBonus().strenght;
        }
    }
    if (equip.twoHanded[weapon])
    {
        currentStrenght *= 2;
        stamina -= 2*equip.weapon[weapon].getWeight();
    }
    else
    {
        stamina -= equip.weapon[weapon].getWeight();
    }
    if (stamina < 0)
        stamina = 0;
    result.addToGeneral(equip.weapon[weapon].getWeight() * currentStrenght);
    result.add(equip.weapon[weapon].getDamageTypes());
    equip.weapon[weapon].lowDurability();
    return result;
}

bool Actor::isDead()
{
    return dead;
}

void Actor::takeParryDamage(DamageTypes damege)
{
    health += 5 * calculateDamage(damege);
    if (health <= 0)
        dead = true;
}

void Actor::takeDamage(DamageTypes damage, int enemyDex)
{
    if (deviation)
    {
        int currentDex = getDex() - enemyDex;
        if (currentDex > Dice::roll())
            return;
    }
    health += calculateDamage(damage);
    if (health <= 0)
        dead = true;
}

int Actor::calculateDamage(DamageTypes damage)
{
    for (int i = 0; i < 4; i++)
    {
        damage.substract(equip.armor[i].getDamageTypes());
        equip.armor[i].lowDurability();
        if (equip.accessory[i].getType() == AccessoryType::defence)
        {
            damage.substract(equip.accessory[i].getDamageTypes());
            equip.accessory[i].lowDurability();
        }
    }
    for (int i = 0; i < 2; i++)
        if (equip.weapon[i].getType() == WeaponType::Shield && protection)
            damage.substract(equip.weapon[i].getDamageTypes());
    return -damage.getHealthDamage();
}
