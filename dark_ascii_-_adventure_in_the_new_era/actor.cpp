#include "actor.h"

Actor::Actor()
{

}

void Actor::useMedKit()
{
    health += medkit.useMedKit();
    if (health > charsMax.health)
        health = charsMax.health;
}

DamageTypes Actor::makeDamage()
{
    DamageTypes result;
    for (int i = 0; i < 2; i++)
    {
        result.addToGeneral(equip.weapon[i].getWeight() * charsMax.strenght);
        result.add(equip.weapon[i].getDamageTypes());
        equip.weapon[i].lowDurability();
    }
    for (int i = 0; i < 4; i++)
    {
        if (equip.accessory[i].getEffectType() == EffectType::attack){
            result.add(equip.accessory[i].getDamageTypes());
        }
    }
    return result;
}

void Actor::takeDamage(DamageTypes damage)
{
    damage.substract(equip.armor.getDamageTypes());
    equip.armor.lowDurability();
    for (int i = 0; i < 4; i++)
    {
        damage.substract(equip.accessory[i].getDamageTypes());
        equip.accessory[i].lowDurability();
    }
    health -= damage.getHealthDamage();
}
