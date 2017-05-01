#ifndef ACCESSORY_H
#define ACCESSORY_H
#include <item.h>
enum AccessoryType{
    defence,
    attack,
    charsAdd
};

struct Chars
{
    //����������
    int strenght;//����
    int health;//��������
    int dexterity;//��������
    //�� ����������
    int luck;//�������� �����//����������� ��������� �������� � �����// �������� [0; luck]
    int stamina;//������������
    int carry;//����������������//����������� ���
    int regenS;//�������������� ������������
};

class Accessory: public Item
{   
    Chars additionChars;//���������
    AccessoryType accessoryType;//���������
public:
    Chars getCharsBonus();
    AccessoryType getType();
    Accessory();
};

#endif // ACCESSORY_H
