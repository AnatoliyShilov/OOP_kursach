#ifndef DAMAGETYPES_H
#define DAMAGETYPES_H

struct DamageTypesInfo//������� ������ � ����� �����
{
    int general;//�������� ����
    float pricking;//�������
    float cutting;//�������
    float crushing;//��������
    float bleeding;//������������
    float poisoning;//����������
};

class DamageTypes//���� �����
{
    int general;//�������� ����
    float pricking;//�������
    float cutting;//�������
    float crushing;//��������
    float bleeding;//������������
    float poisoning;//����������
    void setLessZero();//��������� � ���������� 0 ��� ���� ����� ����� < 0
public:
    DamageTypesInfo getInfo();//��������� ������ � ������� � ������� ��
    void setInfo(DamageTypesInfo info);//����������� ������ � ���������� ��
    DamageTypes();
    DamageTypes(int general, float pricking, float cutting, float crushing, float bleeding, float poisoning);
    void add(DamageTypes damage);//������� ������� �������� ����� ����� � damage
    void substract(DamageTypes damage);//������� �� �������� �������� ����� ����� damage
    int getHealthDamage();//���������� ���� �������� � ������� ���
    void addToGeneral(int value);//�������� � ��������� ����� value
};

#endif // DAMAGETYPES_H
