#ifndef ACCESSORY_H
#define ACCESSORY_H
#include <item.h>
enum EffectType{
    defence,
    attack,
    charsAdd
};

class Accessory: public Item
{   
public:
    EffectType effectType;
    Accessory();
};

#endif // ACCESSORY_H
