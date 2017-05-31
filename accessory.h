#ifndef ACCESSORY_H
#define ACCESSORY_H
#include <item.h>
enum AccessoryType//���� �����������
{
    defence,//��������//��������� ���������� ����
    attack,//���������//����������� ��������� ����
    charsAdd//�����������//�����������/��������� �������������� ���������
};

struct Chars
{
    //����������
    int strenght;//����
    int health;//��������
    int dexterity;//��������
    //�� ����������
    int luck;//�������� �����//����������� ��������� �������� � �����, ��������� ���������� ����������
    int stamina;//������������
    int carry;//����������������//����������� ���
    int regenS;//�������������� ������������
};

struct AccessoryInfo//������� ������ �� ����������
{
    Chars additionChars;
    AccessoryType accessoryType;
    ItemInfo item;
};

class Accessory: public Item
{   
    Chars additionChars;//��������� ������������� ���������
    AccessoryType accessoryType;//��� ����������
public:
    AccessoryInfo getInfo();//��������� ��� ������ � ������� � ������ ��
    void setInfo(AccessoryInfo info);//����������� ������� � ���������� ���������
    Chars getCharsBonus();//������� ������ � ���������������
    AccessoryType getType();//������� ���
    Accessory();
};

#endif // ACCESSORY_H
