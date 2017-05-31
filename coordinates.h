#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates//координаты
{
    int x;//x
    int y;//y
public:
    Coordinates();
    Coordinates(int x, int y);
    void changeCoords(int dx, int dy);//изменить координаты на dx и dy
    void setCoords(int x, int y);//установить координаты
    int getX();//получить абсциссу
    int getY();//получить ординату
    bool equals(Coordinates arg);//проверка на равенство 2х координат
};

#endif // COORDINATES_H
