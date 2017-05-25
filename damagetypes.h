#ifndef DAMAGETYPES_H
#define DAMAGETYPES_H

struct DamageTypesInfo
{
    int general;//основной урон
    float pricking;//Колющий
    float cutting;//Режущий
    float crushing;//Дробящий
    float bleeding;//Кровотечение
    float poisoning;//Отравление
};

class DamageTypes
{
    int general;//основной урон
    float pricking;//Колющий
    float cutting;//Режущий
    float crushing;//Дробящий
    float bleeding;//Кровотечение
    float poisoning;//Отравление
    void setLessZero();
public:
    DamageTypesInfo getInfo();
    void setInfo(DamageTypesInfo info);
    DamageTypes();
    DamageTypes(int general, float pricking, float cutting, float crushing, float bleeding, float poisoning);
    void add(DamageTypes damage);
    void substract(DamageTypes damage);
    int getHealthDamage();
    void addToGeneral(int value);
};

#endif // DAMAGETYPES_H
