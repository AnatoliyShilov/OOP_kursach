#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates//����������
{
    int x;//x
    int y;//y
public:
    Coordinates();
    Coordinates(int x, int y);
    void changeCoords(int dx, int dy);//�������� ���������� �� dx � dy
    void setCoords(int x, int y);//���������� ����������
    int getX();//�������� ��������
    int getY();//�������� ��������
    bool equals(Coordinates arg);//�������� �� ��������� 2� ���������
};

#endif // COORDINATES_H
