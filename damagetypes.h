#ifndef DAMAGETYPES_H
#define DAMAGETYPES_H

struct DamageTypesInfo
{
    int general;//�������� ����
    float pricking;//�������
    float cutting;//�������
    float crushing;//��������
    float bleeding;//������������
    float poisoning;//����������
};

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
    DamageTypesInfo getInfo();
    void setInfo(DamageTypesInfo info);
    DamageTypes();
    DamageTypes(int general, float pricking, float cutting, float crushing, float bleeding, float poisoning);
    void add(DamageTypes damage);
    void substract(DamageTypes damage);
    int getHealthDamage();
    void addToGeneral(int value);
};

#endif // DAMAGETYPES_H
