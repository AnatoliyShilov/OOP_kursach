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
    int memoryFragments;//деньги
    Equipment equip;//экипировка
    Chars charsMax;//максимальные характеристики
    MedKit medkit;//лечилки
    DamageTypes damageT;//базовые бонусы к урону
    Coordinates coords;//относительные координаты
    int stamina;//текущие характеристики//выносливость
    int health;//здоровье
    int carry;//грузоподъемность//переносимый вес
    int regenS;//восстановление выносливости
    bool dead;//статус персонажа - мертв
    bool deviation;//режимы битвы//уклонение
    bool parry;//парирование
    bool protection;//блокирование//только при наличии щита
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
    void takeParryDamage(DamageTypes damege);//входной урон от паррирования
    void takeDamage(DamageTypes damage, int enemyDex);//входной урон//получает
    DamageTypes makeDamage(int weapon);//выходной урон//наносит
    void useMedKit();//использовать лечилку
};

#endif // ACTOR_H
