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
    EffectType effectType;
public:
    Accessory();
    EffectType getEffectType();
};

#endif // ACCESSORY_H
