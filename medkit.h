#ifndef MEDKIT_H
#define MEDKIT_H


class MedKit//�������
{
    int count;//������� ����������
    int countMax;//������������ ����������
    int effectivity;//������������� �������
public:
    MedKit();
    void resetMedKitCount();//�������� ���������� �������//������� ���������� = �������������
    int useMedKit();//������������ 1 ������� � ������� �������������
    int getCount();//������� ������� ���������� �������
};

#endif // MEDKIT_H
