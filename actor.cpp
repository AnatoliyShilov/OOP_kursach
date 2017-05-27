#include "actor.h"

Equipment Actor::getEquipment()
{
    return this->equip;
}

void Actor::addFragments(int fragments)
{
    memoryFragments += fragments;
}

int Actor::getFragments()
{
    return memoryFragments;
}

void Actor::lvl0()
{
    memoryFragments = 0;
    dead = false;
    equip.twoHanded[0] = false;
    equip.twoHanded[1] = false;
    charsMax.carry = 10;
    charsMax.dexterity = 5;
    charsMax.health = 100;
    charsMax.regenS = 10;
    charsMax.stamina = 100;
    charsMax.strenght = 5;
    charsCurrent = charsMax;
    battleMod = BattleMod::None;
    charsBattle.health = charsCurrent.health;
    charsBattle.stamina = charsCurrent.stamina;
}

Actor::Actor()
{
    memoryFragments = 0;
    dead = false;
    equip.twoHanded[0] = false;
    equip.twoHanded[1] = false;
    charsMax.carry = 0;
    charsMax.dexterity = 0;
    charsMax.health = 0;
    charsMax.regenS = 0;
    charsMax.stamina = 0;
    charsMax.strenght = 0;
    charsMax.luck = 10;
    charsCurrent = charsMax;
    battleMod = BattleMod::None;
    charsBattle.health = charsCurrent.health;
    charsBattle.stamina = charsCurrent.stamina;
}

Chars Actor::getMaxChars()
{
    return charsMax;
}

Chars Actor::getCurrentChars()
{
    return charsCurrent;
}

bool Actor::isCritical(int enemyDex)
{
    if ((charsCurrent.luck + (charsCurrent.dexterity - enemyDex) / 10) > Dice::roll())
        return true;
    return false;
}

void Actor::regenDurability()
{
    for (int i = 0; i < 4; i++)
    {
        equip.accessory[i].resetDurability();
        equip.armor[i].resetDurability();
    }
    for (int i = 0; i < 2; i++)
        equip.weapon[i].resetDurability();
}

void Actor::updateCharsCurrent()
{
    charsCurrent = charsMax;
    charsCurrent.regenS = charsCurrent.carry = 0;
    for (int i = 0; i < 4; i++)
    {
        if (!equip.accessory[i].isBroken() && equip.accessory[i].getId())
        {
            charsCurrent.dexterity += equip.accessory[i].getCharsBonus().dexterity;
            charsCurrent.health += equip.accessory[i].getCharsBonus().health;
            charsCurrent.luck += equip.accessory[i].getCharsBonus().luck;
            charsCurrent.stamina += equip.accessory[i].getCharsBonus().stamina * 5;
            charsCurrent.regenS += equip.accessory[i].getCharsBonus().regenS;
            charsCurrent.strenght += equip.accessory[i].getCharsBonus().strenght;
            charsCurrent.carry += equip.accessory[i].getCharsBonus().carry;
        }
    }
    charsCurrent.regenS += charsCurrent.stamina / 10;
    charsCurrent.carry += charsCurrent.strenght * 2;
    for (int i = 0; i < 2; i++)
        charsCurrent.carry -= equip.weapon[i].getWeight();
    for (int i = 0; i < 4; i++)
        charsCurrent.carry -= equip.armor[i].getWeight();
    if (charsBattle.health > charsCurrent.health)
        charsBattle.health = charsCurrent.health;
    if (charsBattle.stamina > charsBattle.stamina)
        charsBattle.stamina = charsCurrent.stamina;
    damageT = DamageTypes(charsCurrent.strenght,
                          charsCurrent.dexterity * 3 + charsCurrent.strenght / 2.0,
                          charsCurrent.dexterity * 2 + charsCurrent.strenght * 2,
                          charsCurrent.dexterity / 2.0 + charsCurrent.strenght * 3,
                          0, 0);
}

void Actor::regenStamina()
{
    charsBattle.stamina += charsCurrent.regenS + charsCurrent.carry;
    if (charsBattle.stamina > charsMax.stamina)
        charsBattle.stamina = charsMax.stamina;
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
    equip.twoHanded[0] = false;
    equip.twoHanded[1] = false;
}

int Actor::getDex()
{
    return charsCurrent.dexterity;
}

void Actor::useMedKit()
{
    charsBattle.health += medkit.useMedKit();
    if (charsBattle.health > charsMax.health)
        charsBattle.health = charsMax.health;
}

bool Actor::isDeviation(int enemyDex)
{
    if (battleMod == BattleMod::Deviation)
    {
        if ((charsCurrent.luck + (charsCurrent.dexterity - enemyDex) / 2) > Dice::roll())
        {
            for (int i = 0; i < 2; i++)
                charsBattle.stamina -= equip.weapon[i].getWeight();
            for (int i = 0; i < 4; i++)
                charsBattle.stamina -= equip.armor[i].getWeight();
            if (charsBattle.stamina < 0)
                charsBattle.stamina = 0;
            return true;
        }
    }
    return false;
}

bool Actor::isParry(int enemyDex)
{
    if (battleMod == BattleMod::Parry)
    {
        if ((charsCurrent.luck + (charsCurrent.dexterity - enemyDex) / 4) > Dice::roll())
        {
            for (int i = 0; i < 2; i++)
                charsBattle.stamina -= equip.weapon[i].getWeight();
            if (charsBattle.stamina < 0)
                charsBattle.stamina = 0;
            return true;
        }
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
    int currentStrenght = charsCurrent.strenght;
    for (int i = 0; i < 4; i++)
    {
        if (equip.accessory[i].getType() == AccessoryType::attack && !equip.accessory[i].isBroken())
        {
            result.add(equip.accessory[i].getDamageTypes());
            equip.accessory[i].lowDurability();
        }
    }
    if (equip.twoHanded[weapon])
    {
        currentStrenght *= 2;
        charsBattle.stamina -= 2*equip.weapon[weapon].getWeight();
    }
    else
    {
        charsBattle.stamina -= equip.weapon[weapon].getWeight();
    }
    if (charsBattle.stamina < 0)
        charsBattle.stamina = 0;
    result.addToGeneral(equip.weapon[weapon].getWeight() * currentStrenght);
    if (!equip.weapon[weapon].isBroken())
    {
        result.add(equip.weapon[weapon].getDamageTypes());
        equip.weapon[weapon].lowDurability();
    }
    return result;
}

bool Actor::isDead()
{
    return dead;
}

void Actor::takeCriticalDamage(DamageTypes damage)
{
    charsBattle.health += 5 * calculateDamage(damage);
    if (charsBattle.health <= 0)
        dead = true;
}

void Actor::takeParryDamage(DamageTypes damage)
{
    charsBattle.health += 5 * calculateDamage(damage);
    if (charsBattle.health <= 0)
        dead = true;
}

void Actor::takeDamage(DamageTypes damage)
{
    charsBattle.health += calculateDamage(damage);
    if (charsBattle.health <= 0)
        dead = true;
}

int Actor::calculateDamage(DamageTypes damage)
{
    for (int i = 0; i < 4; i++)
    {
        if (!equip.armor[i].isBroken())
        {
            damage.substract(equip.armor[i].getDamageTypes());
            equip.armor[i].lowDurability();
        }
        if (equip.accessory[i].getType() == AccessoryType::defence && !equip.accessory[i].isBroken())
        {
            damage.substract(equip.accessory[i].getDamageTypes());
            equip.accessory[i].lowDurability();
        }
    }
    if (battleMod == BattleMod::Protection)
    {
        for (int i = 0; i < 2; i++)
        {
            if (equip.twoHanded[i] && is2handed())
            {
                if (!equip.weapon[i].isBroken())
                {
                    damage.substract(equip.weapon[i].getDamageTypes());
                    equip.weapon[i].lowDurability();
                }
                charsBattle.stamina -= equip.weapon[i].getWeight();
                break;
            }
            else
            {
                if (!equip.weapon[i].isBroken())
                {
                    damage.substract(equip.weapon[i].getDamageTypes());
                    equip.weapon[i].lowDurability();
                }
                charsBattle.stamina -= equip.weapon[i].getWeight();
            }
        }
        if (charsBattle.stamina < 0)
            charsBattle.stamina = 0;
    }
    return -damage.getHealthDamage();
}
