#ifndef PLAYER_H
#define PLAYER_H
#include <actor.h>
#include <bag.h>

class Player: public Actor
{
    Bag bag;
    int souls;
public:
    Player();
    void changeCoords();
    void changeArmor();
    void changeChars();
    void changeWeapon();
    void changeAccessory();
};

#endif // PLAYER_H
