#ifndef PLAYER_H
#define PLAYER_H
#include <actor.h>
#include <bag.h>
#include <fstream>

class Player: public Actor//�������� ����� ������
{
    Bag bag;//�����//���������
    int curentLvl;//������� ������� ���������//���������
    int nextLvlCost;//�������� ���������� ������//���������
    int maxFastTravelId;//�� ������� ������ ����� �������������//���������
public:
    Player();
    void save(const char *file);
    void load(const char *file, AllItems allItems);
    void setFastTravel(int lvlId);
    int getFastTravel();
    int getNextLvlCost();
    void changeLvl(Chars dxChars, int dxLvl);
    void lvl0();
    void rest();
    void loot(Bag bag);
    Bag openBag();//�������� �����
    void changeCoords(int dx, int dy);//�������������
    void changeArmor(Armor armorNew, int index);//������� �����
    Armor selectArmor(int id);//������� �����//�������� ������ ���� �� �����
    void changeChars(Chars chars);//��������� �������������
    void changeWeapon(Weapon weaponNew, int index);//������� ������//�������� ������ ���� �� �����
    void changeAccessory(Accessory acessoryNew, int index);//������� ���������//�������� ������ ���� �� �����
};

#endif // PLAYER_H
