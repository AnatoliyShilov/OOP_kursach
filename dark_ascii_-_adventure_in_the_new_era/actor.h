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
    bool twoHanded[2];//������ 0 ��������� �����
                    //������ 1 ��������� �����
    Accessory accessory[4];
};

class Actor
{
protected:
    int memoryFragments;//������
    Equipment equip;//����������
    Chars charsMax;//������������ ��������������
    MedKit medkit;//�������
    DamageTypes damageT;//������� ������ � �����
    Coordinates coords;//������������� ����������
    int stamina;//������� ��������������//������������
    int health;//��������
    int carry;//����������������//����������� ���
    int regenS;//�������������� ������������
    bool dead;//������ ��������� - �����
    bool deviation;//������ �����//���������
    bool parry;//�����������
    bool protection;//������������//������ ��� ������� ����
    int calculateDamage(DamageTypes damage);//������ �������� �����//������ ���-�� ����� �������� (�������� < 0),
                                            //������� ����� ����� ��� ������� damage
    int is2handed();//0 - ��� ������ � ���������� ������
                    //1 - ������ 0 � ��������� ������
                    //-1 - ������ 1 � ��������� ������
public:
    Actor();
    void regenStamina();//�������������� ������������
    void set2handedW0();//������ 0 - ��������� �����
    void set2handedW1();//������ 1 - ��������� �����
    void unset2handed();//��� ������ �� � ��������� ������
    bool isDead();//������� ���� �������� �����
    int getDex();//���������� �������� �������� � ��������
    bool isParry(int enemyDex);//������� ���� �������� ���� ����������
    void takeParryDamage(DamageTypes damege);//������� ���� �� ������������
    void takeDamage(DamageTypes damage, int enemyDex);//������� ����//��������
    DamageTypes makeDamage(int weapon);//�������� ����//�������
    void useMedKit();//������������ �������
};

#endif // ACTOR_H
