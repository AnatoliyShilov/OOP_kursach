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
    //улучшаемые
    int strenght;//сила
    int health;//здаровье
    int dexterity;//ловкость
    //не улучшаемые
    int luck;//параметр удачи//веро€тность получени€ предмета с врага// интервал [0; luck]
    int stamina;//выносливость
    int carry;//грузоподъемность//переносимый вес
    int regenS;//восстановление выносливости
};

class Accessory: public Item
{   
    Chars additionChars;//сохранить
    AccessoryType accessoryType;//сохранить
public:
    Chars getCharsBonus();
    AccessoryType getType();
    Accessory();
};

#endif // ACCESSORY_H
