#ifndef ACTOR_H
#define ACTOR_H
#include <damagetypes.h>
#include <medkit.h>
#include <coordinates.h>
#include <armor.h>
#include <weapon.h>
#include <accessory.h>
#include <ctime>
#include <stdlib.h>
#include "additionfunction.h"

enum BattleMod
{
    None,//ничего
    Deviation,//уклонение
    Parry,//парарование
    Protection//блокирование//защита
};

struct CharsBattle
{
    int health;
    int stamina;
};

struct Equipment
{
    Armor armor[4];
    Weapon weapon[2];
    bool twoHanded[2];//оружие 0 двуручный режим
                    //оружие 1 двуручный режим
    Accessory accessory[4];
};

class Actor
{
protected:
    int memoryFragments;//деньги//сохранить
    Equipment equip;//экипировка//сохранить
    Chars charsMax;//максимальные характеристики//сохранить
    Chars charsCurrent;//характеристики текущие (учитывают нанесенные повреждения, бонусы и штрафы)
    CharsBattle charsBattle;//изменяемые во время битвы параметры
    MedKit medkit;//лечилки
    DamageTypes damageT;//базовые бонусы к урону//сохранить
    Coordinates coords;//относительные координаты
    BattleMod battleMod;//режим сражения
    bool dead;//статус персонажа - мертв
    void updateCharsCurrent();//обновить текущие параметры
    int calculateDamage(DamageTypes damage);//расчет входного урона//вернет кол-во очков здоровья (значение < 0),
                                            //которое будет снято при текущем damage
    int is2handed();//0 - оба оружия в одноручном режиме
                    //1 - оружие 0 в двуручном режиме
                    //-1 - оружие 1 в двуручном режиме
public:
    Actor();
    void regenStamina();//восстановление выносливости
    void set2handedW0();//оружие 0 - двуручный режим
    void set2handedW1();//оружие 1 - двуручный режим
    void unset2handed();//оба оружия не в двуручном режиме
    bool isDead();//истинна если персонаж мертв
    int getDex();//возвращает значение ловкости с бонусами
    bool isParry(int enemyDex);//истинна если персонаж смог парировать
    bool isDeviation(int enemyDex);//истинна если персонаж смог уклониться
    bool isCritical(int enemyDex);//истинна если персонаж нанес критический урон
    void takeCriticalDamage(DamageTypes damage);//входной критический урон
    void takeParryDamage(DamageTypes damage);//входной урон от паррирования
    void takeDamage(DamageTypes damage);//входной урон//получает
    DamageTypes makeDamage(int weapon);//выходной урон//наносит
    void useMedKit();//использовать лечилку
};

#endif // ACTOR_H
