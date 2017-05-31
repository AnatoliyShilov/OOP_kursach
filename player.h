#ifndef PLAYER_H
#define PLAYER_H
#include <actor.h>

#include <fstream>

struct PlayerInfo//������� ���������� �� ������
{
    int curentLvl;
    int nextLvlCost;
    int maxFastTravelId;
    int memoryFragments;
    Chars charsMax;
    Chars charsCurrent;
};

class Player: public Actor//�����
{

    int curentLvl;//������� ������� ���������
    int nextLvlCost;//�������� ���������� ������
    int maxFastTravelId;//�� ������� ������ ����� �������������
public:
    Player();
    PlayerInfo getInfo();//��������� ������ � ������� � ������� ��
    void save(const char *file);//��������� ������ ������ � ����
    void load(const char *file, AllItems *allItems);// ��������� ������ ������ �� �����
    void setFastTravel(int lvlId);//���������� ������������ ����� ������ ��� �������� �����������
    int getFastTravel();//������� ������������ ����� ������ ��� �������� �����������
    int getNextLvlCost();//������� ��������� ������������������ �� ��������� �������
    void changeLvl(Chars dxChars, int dxLvl);//�������� ������� � �������������� ������
    void lvl0();//�������� ������ �� 0 �������
    void rest();//�������� ��������//����������������� �������� � ���������� �������, ������� ����������
    void loot(Bag *bag);//�������� ������� ��������� ��������� � ��������� ���������� � ����� ������
    void sort();//����������� ���������� �����
    void cleanArmor(int index);//������ ����� �� ���������� �����
    void cleanWeapon(int index);//������ ������ �� ���������� �����
    void cleanAccessory(int index);//������ ��������� �� ���������� �����
    void changeArmor(Armor armorNew, int index);//������� � ������� ��������� �����
    void changeWeapon(Weapon weaponNew, int index);//������� � ������� ��������� ������
    void changeAccessory(Accessory acessoryNew, int index);//������� � ������� ��������� ���������
};

#endif // PLAYER_H
