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
#include <bag.h>

enum BattleMod//режим сражения//определяет поведение персонажа на получение урона
{
    None,//ничего
    Deviation,//уклонение//персонаж попытается уклониться
    Parry,//парарование//персонаж попытается прервать атаку противника и нанести ответный критический урон
    Protection//блокирование//пресонаж будет блокировать атаки противника, тем самым снижая получаемый урон
};

struct CharsBattle//боевые характеристики//изменяются во время сражения
{
    int health;//здоровье
    int stamina;//выносливость
};

struct Equipment//экипировка//то, что носит на себе персонаж
{
    Armor armor[4];//4 слота для брони
    Weapon weapon[2];//2 слота для оружия
    bool twoHanded[2];//оружие 0 двуручный режим
                    //оружие 1 двуручный режим
    Accessory accessory[4];//4 слота для аксессуаров
};

class Actor
{
protected:
    Bag bag;//сумка
    int memoryFragments;//деньги
    Equipment equip;//экипировка
    Chars charsMax;//максимальные характеристики
    Chars charsCurrent;//характеристики текущие (учитывают бонусы и штрафы)
    CharsBattle charsBattle;//изменяемые во время битвы параметры
    MedKit medkit;//аптечки
    DamageTypes damageT;//базовые бонусы к урону
    BattleMod battleMod;//режим сражения
    bool dead;//статус персонажа - мертв
    void regenDurability();//восстановить прочность снаряжения
    int calculateDamage(DamageTypes damage);//расчет входного урона//вернет кол-во очков здоровья (значение < 0),
                                            //которое будет снято при текущем damage
public:
    Actor();
    ~Actor();
    int is2handed();//0 - оба оружия в одноручном режиме
                    //1 - оружие 0 в двуручном режиме
                    //-1 - оружие 1 в двуручном режиме
    void add(Accessory ac);//добавить аксессуар в сумку персонажа
    void add(Armor ar);//добавить броню в сумку персонажа
    void add(Weapon w);//добавить оружие в сумку персонажа
    void cleanBag();//очистить сумку
    Bag *openBag();//просмотр сумки
    Equipment getEquipment();//вернуть снаряжение
    void addFragments(int fragments);//добавить денег
    Chars getMaxChars();//вернуть максимальные характеристики
    Chars getCurrentChars();//вернуть текущие характеристики
    void resetBattleChars();//сбросить боевые характеристики//полностью восстановить здоровье и выносливость
    void updateCharsCurrent();//обновить текущие параметры
    CharsBattle getBattleChars();//вернуть боевые характеристики
    void resetStamina();//полностью восстановить выносливость боевых характеристик
    int getFragments();//вернуть количество денег
    void lvl0();//сбросить персонажа до 0 уровня
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
    int getMedKitCount();//вернуть текущее число аптечек
    void setBattleMode(BattleMod mod);//установить боевой режим
    BattleMod getBattleMod();//вернуть текущий боевой режим
    void useMedKit();//использовать аптечку
};

#endif // ACTOR_H
