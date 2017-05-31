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

enum BattleMod//����� ��������//���������� ��������� ��������� �� ��������� �����
{
    None,//������
    Deviation,//���������//�������� ���������� ����������
    Parry,//�����������//�������� ���������� �������� ����� ���������� � ������� �������� ����������� ����
    Protection//������������//�������� ����� ����������� ����� ����������, ��� ����� ������ ���������� ����
};

struct CharsBattle//������ ��������������//���������� �� ����� ��������
{
    int health;//��������
    int stamina;//������������
};

struct Equipment//����������//��, ��� ����� �� ���� ��������
{
    Armor armor[4];//4 ����� ��� �����
    Weapon weapon[2];//2 ����� ��� ������
    bool twoHanded[2];//������ 0 ��������� �����
                    //������ 1 ��������� �����
    Accessory accessory[4];//4 ����� ��� �����������
};

class Actor
{
protected:
    Bag bag;//�����
    int memoryFragments;//������
    Equipment equip;//����������
    Chars charsMax;//������������ ��������������
    Chars charsCurrent;//�������������� ������� (��������� ������ � ������)
    CharsBattle charsBattle;//���������� �� ����� ����� ���������
    MedKit medkit;//�������
    DamageTypes damageT;//������� ������ � �����
    BattleMod battleMod;//����� ��������
    bool dead;//������ ��������� - �����
    void regenDurability();//������������ ��������� ����������
    int calculateDamage(DamageTypes damage);//������ �������� �����//������ ���-�� ����� �������� (�������� < 0),
                                            //������� ����� ����� ��� ������� damage
public:
    Actor();
    ~Actor();
    int is2handed();//0 - ��� ������ � ���������� ������
                    //1 - ������ 0 � ��������� ������
                    //-1 - ������ 1 � ��������� ������
    void add(Accessory ac);//�������� ��������� � ����� ���������
    void add(Armor ar);//�������� ����� � ����� ���������
    void add(Weapon w);//�������� ������ � ����� ���������
    void cleanBag();//�������� �����
    Bag *openBag();//�������� �����
    Equipment getEquipment();//������� ����������
    void addFragments(int fragments);//�������� �����
    Chars getMaxChars();//������� ������������ ��������������
    Chars getCurrentChars();//������� ������� ��������������
    void resetBattleChars();//�������� ������ ��������������//��������� ������������ �������� � ������������
    void updateCharsCurrent();//�������� ������� ���������
    CharsBattle getBattleChars();//������� ������ ��������������
    void resetStamina();//��������� ������������ ������������ ������ �������������
    int getFragments();//������� ���������� �����
    void lvl0();//�������� ��������� �� 0 ������
    void regenStamina();//�������������� ������������
    void set2handedW0();//������ 0 - ��������� �����
    void set2handedW1();//������ 1 - ��������� �����
    void unset2handed();//��� ������ �� � ��������� ������
    bool isDead();//������� ���� �������� �����
    int getDex();//���������� �������� �������� � ��������
    bool isParry(int enemyDex);//������� ���� �������� ���� ����������
    bool isDeviation(int enemyDex);//������� ���� �������� ���� ����������
    bool isCritical(int enemyDex);//������� ���� �������� ����� ����������� ����
    void takeCriticalDamage(DamageTypes damage);//������� ����������� ����
    void takeParryDamage(DamageTypes damage);//������� ���� �� ������������
    void takeDamage(DamageTypes damage);//������� ����//��������
    DamageTypes makeDamage(int weapon);//�������� ����//�������
    int getMedKitCount();//������� ������� ����� �������
    void setBattleMode(BattleMod mod);//���������� ������ �����
    BattleMod getBattleMod();//������� ������� ������ �����
    void useMedKit();//������������ �������
};

#endif // ACTOR_H
