#ifndef ACCESSORY_H
#define ACCESSORY_H
#include <item.h>
enum AccessoryType//типы аксессуаров
{
    defence,//защитный//уменьшает получаемый урон
    attack,//атакующий//увеличивает наносимый урон
    charsAdd//специальный//увеличивает/уменьшает характеристики персонажа
};

struct Chars
{
    //улучшаемые
    int strenght;//сила
    int health;//здаровье
    int dexterity;//ловкость
    //не улучшаемые
    int luck;//параметр удачи//вероятность получения предмета с врага, успешного выполнения спецприема
    int stamina;//выносливость
    int carry;//грузоподъемность//переносимый вес
    int regenS;//восстановление выносливости
};

struct AccessoryInfo//обертка данных об аксессуаре
{
    Chars additionChars;
    AccessoryType accessoryType;
    ItemInfo item;
};

class Accessory: public Item
{   
    Chars additionChars;//изменение характеристик персонажа
    AccessoryType accessoryType;//тип аксессуара
public:
    AccessoryInfo getInfo();//упаковать все данные в обертку и верную ее
    void setInfo(AccessoryInfo info);//распаковать обертку и установить параметры
    Chars getCharsBonus();//вернуть бонусы к характеристикам
    AccessoryType getType();//вернуть тип
    Accessory();
};

#endif // ACCESSORY_H
