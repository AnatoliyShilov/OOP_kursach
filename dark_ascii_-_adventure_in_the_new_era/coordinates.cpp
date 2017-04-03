#include "coordinates.h"

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

