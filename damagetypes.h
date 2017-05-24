#ifndef DAMAGETYPES_H
#define DAMAGETYPES_H


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
    DamageTypes();
    void add(DamageTypes damage);
    void substract(DamageTypes damage);
    int getHealthDamage();
    void addToGeneral(int value);
};

#endif // DAMAGETYPES_H
