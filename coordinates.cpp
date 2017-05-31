#include "coordinates.h"

bool Coordinates::equals(Coordinates arg)
{
    if (this->x == arg.getX() && this->y == arg.getY())
        return true;
    else
        return false;
}

int Coordinates::getX()
{
    return x;
}

int Coordinates::getY()
{
    return y;
}

void Coordinates::setCoords(int x, int y)
{
    this->x = x;
    this->y = y;
}

Coordinates::Coordinates()
{
    x = y = 0;
}

Coordinates::Coordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Coordinates::changeCoords(int dx, int dy)
{
    x += dx;//x = x + dx
    y += dy;
}

