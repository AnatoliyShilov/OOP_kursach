#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
    int x;
    int y;
public:
    Coordinates();
    Coordinates(int x, int y);
    void changeCoords(int dx, int dy);
    void setCoords(int x, int y);
    int getX();
    int getY();
    bool equals(Coordinates arg);
};

#endif // COORDINATES_H
