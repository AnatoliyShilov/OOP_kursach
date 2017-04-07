#ifndef ACTOR_H
#define ACTOR_H
#include <damagetypes.h>
#include <medkit.h>
#include <coordinates.h>
#include <armor.h>
#include <weapon.h>
#include <accessory.h>

struct Equipment
{
    Armor armor[4];
    Weapon weapon[2];
    Accessory accessory[4];
};

struct Chars
{
    int strenght;
    int stamina;
    int health;
    int agility;
};

class Actor
{
protected:
    Equipment equip;
    Chars charsMax;
    MedKit medkit;
    DamageTypes damageT;
    Coordinates coords;
    int stamina;
    int health;
    int carry;
    int regenS;
public:
    Actor();
    void takeDamage(DamageTypes damage);
    DamageTypes makeDamage();
    void useMedKit();
};

#endif // ACTOR_H
