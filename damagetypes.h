#ifndef DAMAGETYPES_H
#define DAMAGETYPES_H


class DamageTypes
{
    int general;//�������� ����
    float pricking;//�������
    float cutting;//�������
    float crushing;//��������
    float bleeding;//������������
    float poisoning;//����������
    void setLessZero();
public:
    DamageTypes();
    void add(DamageTypes damage);
    void substract(DamageTypes damage);
    int getHealthDamage();
    void addToGeneral(int value);
};

#endif // DAMAGETYPES_H
