#ifndef ACTOR_H
#define ACTOR_H
#include <equipment.h>
#include <chars.h>
#include <damagetypes.h>
#include <medkit.h>
#include <coordinates.h>
class Actor
{
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
