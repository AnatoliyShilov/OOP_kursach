#ifndef ACCESSORY_H
#define ACCESSORY_H
#include <item.h>
enum AccessoryType{
    defence,
    attack,
    charsAdd
};

struct Chars
{
    int strenght;
    int stamina;
    int health;
    int dexterity;
};

class Accessory: public Item
{   
    Chars additionChars;
    AccessoryType accessoryType;
public:
    Chars getCharsBonus();
    AccessoryType getType();
    Accessory();
};

#endif // ACCESSORY_H
