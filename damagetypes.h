#ifndef DAMAGETYPES_H
#define DAMAGETYPES_H

struct DamageTypesInfo//обертка данных о типах урона
{
    int general;//основной урон
    float pricking;// олющий
    float cutting;//–ежущий
    float crushing;//ƒроб€щий
    float bleeding;// ровотечение
    float poisoning;//ќтравление
};

class DamageTypes//типы урона
{
    int general;//основной урон
    float pricking;// олющий
    float cutting;//–ежущий
    float crushing;//ƒроб€щий
    float bleeding;// ровотечение
    float poisoning;//ќтравление
    void setLessZero();//проверить и установить 0 дл€ всех типов урона < 0
public:
    DamageTypesInfo getInfo();//упаковать данные в обертку и вернуть ее
    void setInfo(DamageTypesInfo info);//распаковать данные и установить их
    DamageTypes();
    DamageTypes(int general, float pricking, float cutting, float crushing, float bleeding, float poisoning);
    void add(DamageTypes damage);//сложить текущие значени€ типов урона с damage
    void substract(DamageTypes damage);//вычесть из текущего значени€ типов урона damage
    int getHealthDamage();//рассчитать урон здоровью и вернуть его
    void addToGeneral(int value);//добавить к основному урону value
};

#endif // DAMAGETYPES_H
