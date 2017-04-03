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
};

#endif // COORDINATES_H
