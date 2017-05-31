#ifndef ARMOR_H
#define ARMOR_H
#include <item.h>
enum ArmorType//типы брони
{
    helmet,//шлем
    armor,//доспех//кираса
    gloves,//перчатки
    leggings//поножи
};

struct ArmorInfo//обертка данных брони
{
    ArmorType type;
    int weight;
    ItemInfo item;
};

class Armor: public Item
{
    ArmorType type;//тип брони
    int weight;//вес
public:
    ArmorInfo getInfo();//запаковать данные в обертку и вернуть
    void setInfo(ArmorInfo info);//извлечь данные из обертки и установить
    ArmorType getType();//вернуть тип брони
    int getWeight();//вернуть вес брони
    Armor();
};

#endif // ARMOR_H
